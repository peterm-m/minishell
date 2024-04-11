/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:42:25 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/11 20:54:08 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_exit_status;

/*
void print_lexer(t_token *token) // ¡NO BORRAR!
{
	printf(BHYEL"token: %s\t FLAG: %i puntero token: %p\t puntero string: \
		%p\n"END,token->str, token->flag, token, token->str);
}
*/

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
//		ft_dlstiter(tokens, print_lexer);
		if (tokens == NULL)
			continue ;
		cmd = syntax(tokens);
		if (cmd == NULL)
			continue ;
		execute_command(cmd, NO_PIPE, NO_PIPE);
		clean_command(cmd);
		ft_free(read_line);
		rl_on_new_line();
	}
	rl_clear_history();
	ft_clearenv();
	return (0);
}

void lk() {system("leaks minishell");}

int	main(void)
{
	ft_initenv();
	g_exit_status = 0;
	atexit(lk);
	setup_term();
	initial_signals();
	interactive_loop();
	ft_putstr_fd("exit\n", 1);
	return (EXIT_SUCCESS);
}
