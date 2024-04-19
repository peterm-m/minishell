/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:43:44 by pedro             #+#    #+#             */
/*   Updated: 2024/04/19 18:09:27 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	setup_term(void)
{
	struct termios	initial;

	if (tcgetattr(STDIN_FILENO, &initial) == -1)
		exit(EXIT_FAILURE);
	if (isatty(STDIN_FILENO) == 0
		|| isatty(STDOUT_FILENO) == 0)
		exit(EXIT_SUCCESS);
}

char	*get_prompt(void)
{
	static char	prompt[PATH_MAX];
	char		pwd[PATH_MAX];
	char		*name_cwd;
	char		*aux;

	getcwd(pwd, PATH_MAX);
	name_cwd = ft_strrchr(pwd, '/');
	aux = prompt;
	aux += ft_strlcpy(aux, BHMAG "minishell42 " "(" BHCYN, PATH_MAX);
	aux += ft_strlcpy(aux, name_cwd + 1, PATH_MAX);
	aux += ft_strlcpy(aux, BHMAG") -> "END, PATH_MAX);
	return (prompt);
}
