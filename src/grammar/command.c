/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:46:40 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/13 16:32:58 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	new_command(t_command_type type, t_command **out)
{
	*out = ft_calloc(1, sizeof(t_command));
	if (*out == NULL)
		return (FALSE);
	(*out)->type = type;
	(*out)->flag = 0;
	if (type == cmd_simple)
		(*out)->value.simple = ft_calloc(1, sizeof(t_simple));
	else if (type == cmd_subshell)
		(*out)->value.subshell = ft_calloc(1, sizeof(t_subshell));
	else if (type == cmd_connection)
		(*out)->value.connection = ft_calloc(1, sizeof(t_connection));
	if ((*out)->value.simple == NULL)
	{
		ft_free(*out);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
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

	if (new_command(cmd_simple, &command))
		return (NULL);
	while (1)
	{
		if (redirection_token(lex) || type_token(lex) == tt_io_number)
		{
			redir = make_redirection(lex);
			add_redirection(&command->value.simple->redirects, redir);
		}
		else if (type_token(lex) == tt_word)
		{
			word = make_word(lex);
			add_word(&command->value.simple->words, word);
		}
		else
			break ;
	}
//	if (!redir && !word)
//		TODO: gestionar errores
	return (command);
}
