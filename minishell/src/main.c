/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:42:25 by pedromar          #+#    #+#             */
/*   Updated: 2024/03/18 21:09:25 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* void print_lexer(void *p)
{
	printf("%s\n", (*(t_token *)(p)).str);
	printf("%i\n", (*(t_token *)(p)).flag);
} */
int	interactive_loop(int argc, char **argv)
{
	char	*read_line;
	t_dlst	*tokens;

	(void) argc;
	(void) argv;
	while (1)
	{
		read_line = readline(PROMPT);
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
		//redirections();
		//executers();
		//????
		rl_on_new_line();
	}
	rl_clear_history();
	return (0);
}

#ifdef DEBUG

int	main(int argc, char **argv)
{
	interactive_loop(argc, argv);
	rl_clear_history();
	return (EXIT_SUCCESS);
}

#else

int	main(int argc, char **argv)
{
	initial_signals();
	//TODO: init environ if NULL
	interactive_loop(argc, argv);
	return (EXIT_SUCCESS);
}
#endif
