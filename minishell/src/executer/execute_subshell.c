/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_subshell.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:53:24 by pedromar          #+#    #+#             */
/*   Updated: 2024/03/22 17:59:41 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_subshell(t_subshell *cmd)
{
	pid_t		pid;

	pid = ft_fork();
	if (pid == 0)
	{
		child_signals();
		execute_command(cmd->command); // TODO: investigar si subshell se hace esto
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