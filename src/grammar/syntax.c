/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:21:06 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/13 16:31:14 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_command	*make_and_or(t_dlst **lex);

static t_command	*make_command(t_dlst **lex)
{
	t_token		*tok;
	t_command	*command;

	if (type_token(lex) == tt_lbraket)
	{
		tok = pop_token(lex);
		free_token(tok);
		if (new_command(cmd_subshell, &command))
			return (NULL);
		command->value.subshell->command = make_and_or(lex);
		if (command->value.subshell->command == NULL || type_token(lex) == tt_rbraket)
		{
			// clean
			return (NULL);
		}
	}
	else
		command = make_simple(lex);
		// si error en simple
	return (command);
}

static t_command	*make_pipeline(t_dlst **lex)
{
	t_token		*tok;
	t_command	*pipeline;
	t_command	*first;
	t_command	*second;

	first = make_command(lex);
	if (type_token(lex) != tt_pipe)
		return (first);
	while (type_token(lex) == tt_pipe)
	{
		tok = pop_token(lex);
		if (new_command(cmd_connection, &pipeline))
			return (NULL);
		pipeline->value.connection->connector = (tok->flag & TOK_TYPE);
		free_token(tok);
		pipeline->value.connection->first = first;
		second = make_command(lex);
		// si error
		pipeline->value.connection->second = second;
		first = pipeline;
	}
	return (first);
}

static t_command	*make_and_or(t_dlst **lex)
{
	t_token		*tok;
	t_command	*and_or;
	t_command	*first;
	t_command	*second;

	first = make_pipeline(lex);
	if (type_token(lex) != tt_and_if && type_token(lex) != tt_or_if)
		return (first);
	while (type_token(lex) == tt_pipe)
	{
		tok = pop_token(lex);
		new_command(cmd_connection, &and_or);
		// si error
		and_or->value.connection->connector = (tok->flag & TOK_TYPE);
		free_token(tok);
		and_or->value.connection->first = first;
		second = make_pipeline(lex);
		// si error;
		and_or->value.connection->second = second;
		first = and_or;
	}
	return (first);
}

t_command	*syntax(t_dlst **lex)
{
	t_command	*program;

	while (type_token(lex) != tt_end)
	{
		program = make_and_or(lex);
		if (type_token(lex) != tt_end)
		{
			if (program != NULL)
				clean_command(program);
			ft_dlstclear(lex, free_token);
			return (NULL);
		}
	}
	return (program);
}
