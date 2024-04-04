/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_connection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:54:23 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/04 19:36:13 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	execute_and(t_connection *cmd, int fd_in, int fd_out)
{
	execute_command(cmd->first, fd_in, fd_out);
	if (g_exit_status == 0)
		execute_command(cmd->second, fd_in, fd_out);
	return (0);
}

static int	execute_or(t_connection *cmd, int fd_in, int fd_out)
{
	execute_command(cmd->first, fd_in, fd_out);
	if (g_exit_status != 0)
		execute_command(cmd->second, fd_in, fd_out);
	return (0);
}

static int	execute_pipe(t_command *cmd, int fd_in, int fd_out)
{
	t_command	*command;
	int			prev;
	t_pipe		pipe;

	command = cmd;
	prev = fd_in;
	while (command->value.connection->connector == tt_pipe)
	{
		ft_pipe(&pipe);
		execute_command(command->value.connection->first, prev, pipe.pipe[1]);
		if (prev >= 0)
			ft_close(prev);
		prev = pipe.pipe[0];
		ft_close(pipe.pipe[1]);
		command = command->value.connection->second;
	}
	execute_command(command, prev, fd_out);
	if (prev >= 0)
		ft_close(prev);
	return (0);
}

int	execute_connection(t_command *cmd, int fd_in, int fd_out)
{
	t_connection	*connection;

	connection = cmd->value.connection;
	if (connection->connector == tt_and_if)
		execute_and(connection, fd_in, fd_out);
	else if (connection->connector == tt_or_if)
		execute_or(connection, fd_in, fd_out);
	else if (connection->connector == tt_pipe)
		execute_pipe(cmd, fd_in, fd_out);
	return (0);
}
