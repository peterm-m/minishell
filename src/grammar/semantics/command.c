/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 00:59:42 by pedro             #+#    #+#             */
/*   Updated: 2024/01/25 19:12:39 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clean_command(t_command *cmd)
{
	dbg("%s\n","");
	if (cmd == NULL)
		return ;
	if (cmd->type == cmd_simple)
		clean_simple(cmd->value.simple);
	else if (cmd->type == cmd_connection)
		clean_connection(cmd->value.connection);
	else if (cmd->type == cmd_subshell)
		clean_subshell(cmd->value.subshell);
	else if (cmd->type == cmd_group)
		clean_group(cmd->value.group);
	clean_redirection(cmd->redirects);
	free(cmd);
}

t_command	*join_command_redir(t_command *cmd, t_redirect *redir)
{
	dbg("%s\n","");
	cmd->redirects = join_redir(cmd->redirects, redir);
	return (cmd);
}

t_command	*make_command(t_command_type type, t_node value)
{
	dbg("%s\n","");
	t_command	*tmp;

	tmp = (t_command *) ft_malloc(sizeof(t_command));
	tmp->type = type;
	tmp->value = value;
	tmp->value.simple->flags = 0;
	tmp->flag = 0;
	tmp->redirects = (t_redirect *) NULL;
	return (tmp);
}
