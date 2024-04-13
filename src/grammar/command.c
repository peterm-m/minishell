/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:46:40 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/13 12:05:43 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_command	*new_command(t_command_type type)
{
	t_command	*command;

	command = ft_malloc(sizeof(t_command));
	if (command == NULL)
		return (NULL);
	command->type = type;
	command->flag = 0;
	if (type == cmd_simple)
		command->value.simple = ft_malloc(sizeof(t_simple));
	else if (type == cmd_subshell)
		command->value.subshell = ft_malloc(sizeof(t_subshell));
	else if (type == cmd_connection)
		command->value.connection = ft_malloc(sizeof(t_connection));
	command->redirects = NULL;
	if (command->value.simple == NULL)
	{
		ft_free(command);
		return (NULL);
	}
	return (command);
}

t_command	*make_subshell(t_dlst **lex)
{
	(void)lex;
	return (NULL);
}

/*
	Comando simple: lista de palabras y redirecciones en cualquier orden
		Primera palabra sera el comando a ejecutar
*/

t_command	*make_simple(t_dlst **lex)
{
	t_redirect	*redir;
	t_word		*word;
	t_command	*command;
	t_simple	*simple;

	command = new_command(cmd_simple);
	simple = command->value.simple;
	while (1)
	{
		if (token_type(lex) == tt_dgreat || token_type(lex) == tt_great
			|| token_type(lex) == tt_dless || token_type(lex) == tt_less
			|| token_type(lex) == tt_io_number)
		{
			redir = make_redirection(lex);
			add_redirection(&simple->redirects, redir);
		}
		else if (token_type(lex) == tt_word)
		{
			word = make_word(lex);
			add_word(&simple->words, word);
		}
		else
			break ;
	}
//	if (!redir && !word)
//		TODO: gestionar errores
	return (command);
}
