/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:42:25 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/18 19:50:20 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_exit_status;


/* void print_lexer(void *token) // ¡NO BORRAR!
{
	printf(BHYEL"token: %s\t FLAG: %i puntero token: %p\t puntero string: \
		%p\n"END,((t_token *)token)->str, ((t_token *)token)->flag, token, ((t_token *)token)->str);
} */

//		ft_dlstiter(tokens, print_lexer);

static int	interactive_loop(void)
{
	char		*read_line;
	t_dlst		*tokens;
	t_command	*cmd;

	while (1)
	{
		read_line = readline(get_prompt());
		add_history(read_line);
		if (read_line == NULL)
			break ;
		tokens = lexer(read_line);
		//ft_dlstiter(tokens, print_lexer);
		cmd = syntax(&tokens);
		if (cmd != NULL)
			execute_command(cmd, NO_PIPE, NO_PIPE);
		clean_command(cmd);
		ft_free(read_line);
		rl_on_new_line();
	}
	return (0);
}

void lk() {system("leaks minishell");}
//	atexit(lk);

int	main(void)
{
	g_exit_status = 0;
	setup_term();
	initial_signals();
	interactive_loop();
	rl_clear_history();
	ft_environ("", CLEAN, 0);
	ft_putstr_fd("exit\n", 1);
	atexit(lk);
	return (EXIT_SUCCESS);
}
