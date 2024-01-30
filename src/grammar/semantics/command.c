/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 00:59:42 by pedro             #+#    #+#             */
/*   Updated: 2024/01/30 20:36:53 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#undef LOGS 
#define LOGS 0

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
ft_free(cmd);
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
	tmp->flags = 0;
	tmp->redirects = (t_redirect *) NULL;
	return (tmp);
}
#undef LOGS
#define LOGS 1