/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:42:25 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/14 22:40:30 by pedro            ###   ########.fr       */
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
		cmd = syntax(&tokens);
		if (cmd != NULL)
			execute_command(cmd, NO_PIPE, NO_PIPE);
		clean_command(cmd);
		ft_free(read_line);
		rl_on_new_line();
	}
	rl_clear_history();
	return (0);
}

//void lk() {system("leaks minishell");}
//	atexit(lk);

int	main(void)
{
	g_exit_status = 0;
	ft_initenv();
	setup_term();
	initial_signals();
	interactive_loop();
	ft_putstr_fd("exit\n", 1);
	return (EXIT_SUCCESS);
}
