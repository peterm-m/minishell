/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:42:25 by pedromar          #+#    #+#             */
/*   Updated: 2024/03/10 18:30:10 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
			return (EXIT_SUCCESS);
		//tokens = lexer(read_line);
		//if (tokens == NULL)
		//	continue ;
		//syntax(&tokens);
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
	//initialization();
	interactive_loop(argc, argv);
	return (EXIT_SUCCESS);
}
#endif
