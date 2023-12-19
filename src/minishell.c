/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:56:16 by pedromar          #+#    #+#             */
/*   Updated: 2023/12/17 18:28:29 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
// #include <readline/readline.h>
// #include <stdio.h>
// #include <stdlib.h>

int	main(int argc, char const **argv, char const **envp)
{
	char	*read_line;
	//t_data *data;

	(void) argc;
	(void) argv;
	(void) envp;
	while (1)
	{
		read_line = readline(BHMAG"> "END);
		//printf("%s", read_line);
		if (ft_strncmp(read_line, "exit", 5) == 0)
			break ;
		/* ##########  PROPUESTA ##########

		t_dlst	*lex;
		lex = lexer(read_line); // lexer: pasa la string  a una lista de tokens.
		if (lexical_cheker(lex)) // lexical_check: comprueba si es un conjunto de tokens es valido.
			printf("LEXICAL ERROR!");

		tree = syntax(lex); // parte sintactica
		if (sintax_cheker(lex))
			printf("LEXICAL ERROR!");

		*/
		if (lexer(read_line))
			printf(BHGRN"Lexer ok\n"END);
	}
	return (0);
}
