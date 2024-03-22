/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_connection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:54:23 by pedromar          #+#    #+#             */
/*   Updated: 2024/03/22 17:24:16 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execute_and(t_connection *cmd)
{
	execute_command(cmd->first);
	if (g_exit_status == 0)
		execute_command(cmd->second);
	return (0);
}

int	execute_or(t_connection *cmd)
{
	execute_command(cmd->first);
	if (g_exit_status != 0)
		execute_command(cmd->second);
	return (0);
}

int	execute_pipe(t_connection *cmd)
{
	(void)cmd;
	// TODO: gestion pipes 
	printf("---> %d\n", __LINE__);
	return (0);
}

int	execute_connection(t_connection *cmd)
{
	if (cmd->connector == tt_and_if)
		execute_and(cmd);
	else if (cmd->connector == tt_or_if)
		execute_or(cmd);
	else if (cmd->connector == tt_pipe)
		execute_pipe(cmd);
	return (0);
}
