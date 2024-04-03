/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:43:44 by pedro             #+#    #+#             */
/*   Updated: 2024/04/03 12:23:33 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	setup_term(void)
{
	static struct termios	initial = { \
				.c_iflag = 0,
				.c_oflag = 0,
				.c_cflag = 0,
				.c_lflag = 0,
				.c_cc = NULL };

	if (initial.c_cc == NULL)
		if (tcgetattr(STDIN_FILENO, &initial) == -1)
			exit(EXIT_FAILURE);
	if (isatty(STDIN_FILENO) == 0 ||
		isatty(STDOUT_FILENO) == 0)
		exit(EXIT_SUCCESS);
}

char *get_prompt(void)
{
	char		*directory;
	char		pwd[PATH_MAX];
	char		*prompt;

	directory = ft_strrchr(getcwd(pwd, PATH_MAX), '/');
	prompt = ft_strjoin(BHMAG PROMPT END,BHGRN " (");
	prompt = ft_strjoin(prompt, directory + 1);
	prompt = ft_strjoin(prompt, ")>"END);
	return (prompt);
}
