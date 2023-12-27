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

void tok_p(void *t)
{
	if (((t_token *)t) != NULL)
		printf("TOKEN: %s\nTYPE:\n%d\nEXPAND(TRUE/FALSE): %d\n\n", ((t_token *)t)->str, ((t_token *)t)->type, ((t_token *)t)->expand);
}

int	main(int argc, char const **argv, char const **envp)
{
	char	*read_line;
	t_data data;

	data.list = NULL;
	(void) argc;
	(void) argv;
	data.env = envp;
	while (1)
	{
		read_line = readline(BHMAG"minishell42-> "END);
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
		//if (lexer(read_line))
		ft_dlstnew(data.list);
		data.list = lexer(read_line, &data.list);
		ft_dlstiter(data.list, tok_p);
	}
	ft_dlstclear(&data.list, free_list);
	return (0);
}

