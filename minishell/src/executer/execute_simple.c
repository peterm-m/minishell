/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_simple.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:56:16 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/03 12:26:39 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Execute a simple command that is hopefully defined in a disk file
   somewhere.

   1) fork
	child:	
   		2) change signals
   		3) connect pipes
   		4) do redirections
   		5) execve
		6) exit
	father:
		2) change signals
		3) wait
			NO_PIPE block waitpid
			LAST_IN_PIPE no block waitpit for all child process
			IN_PIPE no wait
		4) restore signals
*/
// TODO: gestionar error.

static	void	wait_command(pid_t pid, int type)
{
	int		status;
	pid_t	tmp;

	if (type == NO_PIPE)
	{
		ft_waitpid(pid, &status, WUNTRACED);
		if (WIFEXITED(status))
			g_exit_status = WEXITSTATUS(status);
	}
	else if (type == LAST_IN_PIPE)
	{
		while (1)
		{
			tmp = waitpid(-1, &status, WUNTRACED | WNOHANG);
			if (tmp < 0)
				break ;
			else if (tmp == pid && WIFEXITED(status))
				g_exit_status = WEXITSTATUS(status);
		}
	}
}

void	execute_simple(t_command *cmd, int fd_in, int fd_out)
{
	pid_t		pid;
	t_simple	*command;

	command = cmd->value.simple;
	pid = ft_fork();
	if (pid == 0)
	{
		child_signals();
		make_pipe(fd_in, fd_out);
		make_redir(command->redirects);
		ft_execle(command->words);
		exit (EXIT_SUCCESS);
	}
	else
	{
		wait_signals();
		if (fd_in == NO_PIPE && fd_out == NO_PIPE)
			wait_command(pid, NO_PIPE);
		else if (fd_in != NO_PIPE && fd_out == NO_PIPE)
			wait_command(pid, LAST_IN_PIPE);
		initial_signals();
	}
	return ;
}
