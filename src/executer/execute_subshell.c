/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_subshell.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:53:24 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/15 18:18:34 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// TODO: investigar si subshell se hace esto

void	execute_subshell(t_command *cmd, int fd_in, int fd_out)
{
	pid_t		pid;
	t_subshell	*subshell;

	subshell = cmd->value.subshell;
	pid = ft_fork();
	if (pid == 0)
	{
		make_pipe(fd_in, fd_out);
		make_redir(cmd->redirs);
		execute_command(subshell->command, NO_PIPE, NO_PIPE);
		exit (EXIT_SUCCESS);
	}
	else
	{
		wait_signals();
		ft_waitpid(pid, &g_exit_status, WUNTRACED);
		if (WEXITSTATUS(g_exit_status))
			g_exit_status = WEXITSTATUS(g_exit_status);
		initial_signals();
	}
	return ;
}
