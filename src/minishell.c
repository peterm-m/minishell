/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:56:16 by pedromar          #+#    #+#             */
/*   Updated: 2024/01/21 18:24:06 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
// #include <readline/readline.h>
// #include <stdio.h>
// #include <stdlib.h>

// void tok_p(void *t)
// {
// 	if (((t_token *)t) != NULL)
// 		printf(BHYEL"\nToken: "BHBLU"%s\n"
// 		BHYEL"Flag(0/1/2): "BHGRN"%d\n\n"END,
// 		((t_token *)t)->str, ((t_token *)t)->flag);
// }

int	main(int argc, char const **argv, char const **envp)
{
	char	*read_line;
	t_data	data;
	
	(void) argc;
	(void) argv;
	data.env = envp;
	while (1)
	{
		read_line = readline(BHMAG"minishell42-> "END);
		//printf("%s", read_line);
		if (ft_strncmp(read_line, "exit", 5) == 0)
			break ;
		if (read_line[0] == '\\')
		{
			char *buffer = readline("quote >$");
			printf("buffer = %s\n", buffer);
		}
		ft_dlstnew(data.lexlist);
		data.lexlist = lexer(read_line, &data.lexlist);
		//ft_dlstiter(data.lexlist, tok_p);
		expander(&data, read_line);
		/* ##########  PROPUESTA ##########
		if (lexical_cheker(lex)) // lexical_check: comprueba si es un conjunto de tokens es valido.
			printf("LEXICAL ERROR!");

		tree = syntax(lex); // parte sintactica
		if (sintax_cheker(lex))
			printf("LEXICAL ERROR!");
			echo "hola?" | cat minish* && echo "$(COMMD_SUB)" || echo "${PARAM_E}"
		*/
	}
	ft_dlstclear(&data.lexlist, ft_free);
	return (0);
}
