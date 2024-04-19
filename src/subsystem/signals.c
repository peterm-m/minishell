/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:27:05 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/19 15:04:04 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sigint_handler(int sig)
{
	(void)sig;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	g_exit_status = 1;
}

void	wait_handler(int sig)
{
	if (sig == SIGQUIT)
	{
		g_exit_status = 131;
		printf("Quit: 3\n");
	}
	else if (sig == SIGINT)
	{
		g_exit_status = 130;
		printf("\n");
	}
}

void	initial_signals(void)
{
	ft_signal(SIGINT, sigint_handler);
	ft_signal(SIGQUIT, SIG_IGN);
	ft_signal(SIGTTIN, SIG_IGN);
	ft_signal(SIGTTOU, SIG_IGN);
	ft_signal(SIGTSTP, SIG_IGN);
}

void	wait_signals(void)
{
	ft_signal(SIGINT, wait_handler);
	ft_signal(SIGQUIT, wait_handler);
	ft_signal(SIGTTIN, SIG_IGN);
	ft_signal(SIGTTOU, SIG_IGN);
	ft_signal(SIGTSTP, SIG_IGN);
}

void	child_signals(void)
{
	ft_signal(SIGINT, SIG_DFL);
	ft_signal(SIGQUIT, SIG_DFL);
	ft_signal(SIGTSTP, SIG_DFL);
	ft_signal(SIGTTIN, SIG_DFL);
	ft_signal(SIGTTOU, SIG_DFL);
	ft_signal(SIGCHLD, SIG_DFL);
}
