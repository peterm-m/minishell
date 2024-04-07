/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:42:25 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/07 12:50:13 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_exit_status;

/* void print_lexer(t_token *token) // ¡NO BORRAR!
{
	printf(BHYEL"token: %s\n FLAG: %i\n"END,token->str, token->flag);
} */

static int	interactive_loop(void)
{
	char	*read_line;
	t_dlst	*tokens;

	while (1)
	{
		read_line = readline(get_prompt());
		add_history(read_line);
		if (read_line == NULL)
		{
			printf("\n");
			exit (EXIT_SUCCESS);
		}
		tokens = lexer(read_line);
		//ft_dlstiter(tokens, print_lexer);
		if (tokens == NULL)
			continue ;
		syntax(&tokens);
		//executers();
		rl_on_new_line();
	}
	rl_clear_history();
	return (0);
}

int	main(void)
{
	g_exit_status = 0;
	setup_term();
	initial_signals();
	interactive_loop();
	return (EXIT_SUCCESS);
}
