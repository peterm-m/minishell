/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipeline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:03:39 by pedro             #+#    #+#             */
/*   Updated: 2024/03/27 18:13:08 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	wait_pipe(void)
{
	pid_t	pid;
	pid_t	last_in_pipe;
	int		status;
	int		status_pipe;

	pid = -1;
	last_in_pipe = pid;
	status_pipe = 0;
	while (1)
	{
		pid = waitpid(-1, &status, WUNTRACED|WNOHANG);
		if (pid < 0)
			break ;
		else if (pid > last_in_pipe)
		{
			last_in_pipe = pid;
			status_pipe = status;
		}
	}
	if (WIFEXITED(status_pipe))
		g_exit_status = WEXITSTATUS(status_pipe);
}

int	execute_pipe(t_command *cmd, int fd_in, int fd_out)
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
	if (fd_in == NO_PIPE && fd_out == NO_PIPE)
		wait_pipe();
	return (0);
}
