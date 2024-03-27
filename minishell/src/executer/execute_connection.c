/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_connection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:54:23 by pedromar          #+#    #+#             */
/*   Updated: 2024/03/27 09:40:56 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execute_and(t_connection *cmd, int fd_in, int fd_out)
{
	execute_command(cmd->first, fd_in, fd_out);
	if (g_exit_status == 0)
		execute_command(cmd->second, fd_in, fd_out);
	return (0);
}

int	execute_or(t_connection *cmd, int fd_in, int fd_out)
{
	execute_command(cmd->first, fd_in, fd_out);
	if (g_exit_status != 0)
		execute_command(cmd->second, fd_in, fd_out);
	return (0);
}

int	execute_connection(t_command *cmd, int fd_in, int fd_out)
{
	t_connection *connection;

	connection = cmd->value.connection;
	if (connection->connector == tt_and_if)
		execute_and(connection, fd_in, fd_out);
	else if (connection->connector == tt_or_if)
		execute_or(connection, fd_in, fd_out);
	else if (connection->connector == tt_pipe)
		execute_pipe(cmd, fd_in, fd_out);
	return (0);
}
