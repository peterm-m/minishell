/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:21:06 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/13 12:07:40 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_command	*make_command(t_dlst **lex)
{
	t_command	*command;

	if (token_type(lex) == tt_lbraket)
		command = make_subshell(lex);
		// si error en make subshell
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
	if (token_type(lex) != tt_pipe)
		return (first);
	while (token_type(lex) == tt_pipe)
	{
		tok = pop_token(lex);
		pipeline = new_command(cmd_connection);
		// si error
		pipeline->value.connection->connector = (tok->flag & TOK_TYPE);
		free_token(tok);
		pipeline->value.connection->first = first;
		second = make_command(lex);
		// si error;
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
	if (token_type(lex) != tt_pipe)
		return (first);
	while (token_type(lex) == tt_pipe)
	{
		tok = pop_token(lex);
		and_or = new_command(cmd_connection);
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

	while (token_type(lex) != tt_end)
	{
		program = make_and_or(lex);
		if (token_type(lex) != tt_end)
		{
			// error
			break ;
		}
	}
	return (program);
}
