/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:27:05 by pedromar          #+#    #+#             */
/*   Updated: 2024/03/19 21:00:12 by pedromar         ###   ########.fr       */
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
}

void	wait_handler(int sig)
{
	if (sig == SIGQUIT)
		printf("Quit: 3\n");
	else if (sig == SIGINT)
		printf("\n");
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
