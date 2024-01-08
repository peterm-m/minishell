/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 00:59:42 by pedro             #+#    #+#             */
/*   Updated: 2024/01/08 20:39:30 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clean_command(t_command *cmd)
{
	t_node	value;

	value = cmd->value;
	free(cmd);
	if (cmd->type == cmd_simple)
		clean_simple(value.simple);
	else if (cmd->type == cmd_connection)
		clean_connection(value.connection);
	else if (cmd->type == cmd_subshell)
		clean_subshell(value.subshell);
	else if (cmd->type == cmd_group)
		clean_group(value.group);
	else
		return ;
}

t_command	*make_command(t_command_type type, t_node value)
{
	t_command	*tmp;

	tmp = (t_command *)ft_malloc(sizeof(t_command));
	tmp->type = type;
	tmp->value = value;
	tmp->value.simple->flags = 0;
	tmp->flags = 0;
	tmp->redirects = (t_redirect *)NULL;
	return (tmp);
}

