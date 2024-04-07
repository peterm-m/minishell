/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_subshell.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:53:24 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/07 17:33:52 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// TODO: investigar si subshell se hace esto

void	execute_subshell(t_subshell *cmd, int fd_in, int fd_out)
{
	pid_t	pid;

	pid = ft_fork();
	if (pid == 0)
	{
		child_signals();
		execute_command(cmd->command, fd_in, fd_out);
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
