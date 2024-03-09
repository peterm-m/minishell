/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 00:59:42 by pedro             #+#    #+#             */
/*   Updated: 2024/03/08 14:59:01 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#undef LOGS 
#define LOGS 0

void	print_command(t_command *cmd)
{
	if (cmd == NULL)
		return ;
	if (cmd->type == cmd_simple)
		print_simple(cmd->value.simple);
	else if (cmd->type == cmd_connection)
		print_connection(cmd->value.connection);
	else if (cmd->type == cmd_subshell)
		print_subshell(cmd->value.subshell);
	else if (cmd->type == cmd_group)
		print_group(cmd->value.group);
}

void	clean_command(t_command *cmd)
{
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
	clean_redirection(&(cmd->redirects));
	ft_free(cmd);
	dbg("├─%s\n", "clean_command");
}

t_command	*join_command_redir(t_command *cmd, t_redirect *redir)
{
	dbg("│\t│\t├─%s\n", "join redir");
	join_redir(&(cmd->redirects), redir);
	return (cmd);
}

t_command	*make_command(t_command_type type, t_node value)
{
	t_command	*tmp;

	dbg("│\t│\t├─%s\n", "make_command");
	tmp = (t_command *) ft_malloc(sizeof(t_command));
	tmp->type = type;
	tmp->value = value;
	tmp->value.simple->flags = 0;
	tmp->flag = 0;
	tmp->redirects = (t_redirect *) NULL;
	return (tmp);
}
