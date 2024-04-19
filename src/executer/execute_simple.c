/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_simple.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:56:16 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/19 14:50:12 by pedromar         ###   ########.fr       */
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
				if simple command: wait_command
				else if: last in pipe no block waitpit for all child process
				else: in pipe no wait
			4) restore signals
*/

void	execute_simple(t_command *cmd, t_pipe *p, int index_cmd)
{
	pid_t		pid;
	t_simple	*command;

	command = cmd->value.simple;
	pid = minish_fork();
	if (pid == 0)
	{
		child_signals();
		connect_pipe(p, index_cmd);
		open_redir(command->redirs);
		ft_execle(command->words);
		exit (EXIT_SUCCESS);
	}
	else if (pid > 0)
	{
		wait_signals();
		if (p == NULL)
			wait_command(pid);
		else if (p != NULL && index_cmd == p->len_pipe)
			wait_pipe(pid, p);
		initial_signals();
	}
	return ;
}
