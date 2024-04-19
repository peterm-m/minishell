/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:52:27 by pedro             #+#    #+#             */
/*   Updated: 2024/04/19 17:07:52 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	wait_pipe(pid_t pid, t_pipe *p)
{
	int		status;
	pid_t	tmp;

	close_pipe(p);
	while (1)
	{
		tmp = waitpid(-1, &status, WUNTRACED | WNOHANG);
		if (tmp < 0)
			break ;
		else if (pid != PID_BUILTIN && tmp == pid && WIFEXITED(status))
			g_exit_status = WEXITSTATUS(status);
	}
}

void	wait_command(pid_t pid)
{
	int		status;

	waitpid(pid, &status, WUNTRACED);
	if (WIFEXITED(status))
		g_exit_status = WEXITSTATUS(status);
}
