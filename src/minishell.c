/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:56:16 by pedromar          #+#    #+#             */
/*   Updated: 2023/11/21 17:29:43 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
// #include <readline/readline.h>
// #include <stdio.h>
// #include <stdlib.h>

int	main(int argc, char const **argv, char const **envp)
{
	char	*read_line;

	(void) argc;
	(void) argv;
	(void) envp;
	while (1)
	{
		read_line = readline(BHMAG"> "END);
		if (!strcmp(read_line, "exit"))
			break ;
		// if (lexer(read_line))
		// 	printf(BHGRN"Lexer ok\n"END);
	}
	return (0);
}
