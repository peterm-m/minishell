/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 11:30:19 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/14 16:40:33 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	clean_connection(t_connection *connection)
{
	t_command	*cmd1;
	t_command	*cmd2;

	if (connection == NULL)
		return ;
	cmd1 = connection->first;
	cmd2 = connection->second;
	if (cmd1 != NULL)
		clean_command(cmd1);
	if (cmd2 != NULL)
		clean_command(cmd2);
	ft_free(connection);
}

static void	clean_subshell(t_subshell *subshell)
{
	if (subshell == NULL)
		return ;
	if (subshell->command != NULL)
		clean_command(subshell->command);
	ft_free(subshell);
}

static void	clean_simple(t_simple *cmd)
{
	if (cmd == NULL)
		return ;
	if (cmd->words != NULL)
		clean_word(&(cmd->words));
	if (cmd->redirs != NULL)
		clean_redirection(&(cmd->redirs));
	ft_free(cmd);
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
	clean_redirection(&(cmd->redirs));
	ft_free(cmd);
}
