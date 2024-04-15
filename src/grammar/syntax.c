/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:21:06 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/15 12:29:02 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	Ref: 2. Shell Command Language. 2.9 Shell Commands
	In minishell command is one of the following:
		* Simple command: 2.9.1 Simple Commands
			A simple command is a sequence  words and redirections,
			terminated by a control operator.
		* Compound Commands: 2.9.4 Compound Commands
			The shell has several programming constructs that are
			compound commands, which provide control flow for commands.
			In this minishell we implemented "(" and_or ")"
*/
static t_command	*make_command(t_dlst **lex);

/*
	Ref: 2. Shell Command Language. 2.9.2 Pipelines
	pipeline is a sequence of one or more commands
		separated by the control operator '|'
*/
static t_command	*make_pipeline(t_dlst **lex);

/*
	Ref: 2. Shell Command Language. 2.9.3 Lists
	An and_or list is a sequence of one or more pipelines
		separated by the operators "&&" and "||"
*/
static t_command	*make_and_or(t_dlst **lex);

t_command	*syntax(t_dlst **lex)
{
	t_command	*program;

	program = NULL;
	if (lex == NULL || *lex == NULL)
		return (NULL);
	while (type_token(lex) != tt_end)
	{
		program = make_and_or(lex);
		if (type_token(lex) != tt_end || program == NULL)
			return (parser_error(lex, program));
		else
			break ;
	}
	ft_dlstclear(lex, free_token);
	return (program);
}

static t_command	*make_and_or(t_dlst **lex)
{
	t_token		*tok;
	t_command	*and_or;
	t_command	*first;
	t_command	*second;

	first = make_pipeline(lex);
	if ((type_token(lex) != tt_and_if && type_token(lex) != tt_or_if)
		|| first == NULL)
		return (first);
	while (type_token(lex) == tt_and_if || type_token(lex) == tt_or_if)
	{
		tok = pop_token(lex);
		if (new_command(cmd_connection, &and_or))
			return (parser_error(lex, first));
		and_or->value.connection->connector = (tok->flag & TOK_TYPE);
		free_token(tok);
		and_or->value.connection->first = first;
		second = make_pipeline(lex);
		if (second == NULL)
			return (parser_error(lex, and_or));
		and_or->value.connection->second = second;
		first = and_or;
	}
	return (first);
}

static t_command	*make_pipeline(t_dlst **lex)
{
	t_token		*tok;
	t_command	*pipeline;
	t_command	*first;
	t_command	*second;

	first = make_command(lex);
	if (type_token(lex) != tt_pipe || first == NULL)
		return (first);
	while (type_token(lex) == tt_pipe)
	{
		tok = pop_token(lex);
		if (new_command(cmd_connection, &pipeline))
			return (parser_error(lex, first));
		pipeline->value.connection->connector = (tok->flag & TOK_TYPE);
		free_token(tok);
		pipeline->value.connection->first = first;
		second = make_command(lex);
		if (second == NULL)
			return (parser_error(lex, pipeline));
		pipeline->value.connection->second = second;
		first = pipeline;
	}
	return (first);
}

static t_command	*make_command(t_dlst **lex)
{
	t_token		*tok;
	t_command	*command;

	if (type_token(lex) == tt_lbraket)
	{
		tok = pop_token(lex);
		free_token(tok);
		if (new_command(cmd_subshell, &command))
			return (parser_error(lex, command));
		command->value.subshell->command = make_and_or(lex);
		if (command->value.subshell->command == NULL
			|| type_token(lex) != tt_rbraket)
			return (parser_error(lex, command));
		tok = pop_token(lex);
		free_token(tok);
		while (redirection_token(lex) || type_token(lex) == tt_io_number)
			if (add_redirection(&command->redirs, lex))
				return (parser_error(lex, command));
	}
	else
		command = make_simple(lex);
	return (command);
}
