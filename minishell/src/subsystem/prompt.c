/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:43:44 by pedro             #+#    #+#             */
/*   Updated: 2024/04/07 12:42:49 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// TODO checkear

void	setup_term(void)
{
	struct termios	initial;

	if (tcgetattr(STDIN_FILENO, &initial) == -1)
		exit(EXIT_FAILURE);
	if (isatty(STDIN_FILENO) == 0
		|| isatty(STDOUT_FILENO) == 0)
		exit(EXIT_SUCCESS);
}

// TODO: leaks and check NULL
//	only change if change cwd

char	*get_prompt(void)
{
	char	*directory;
	char	pwd[PATH_MAX];
	char	*prompt;

	directory = ft_strrchr(getcwd(pwd, PATH_MAX), '/');
	prompt = ft_strjoin(BHMAG PROMPT BHCYN, directory + 1);
	prompt = ft_strjoin(prompt, BHMAG") -> "END);
	return (prompt);
}
