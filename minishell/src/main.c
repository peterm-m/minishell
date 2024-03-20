/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:42:25 by pedromar          #+#    #+#             */
/*   Updated: 2024/03/20 20:14:45 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void print_lexer(void *p)   //TODO  BORRAR: Imprimir lista tokens
{
	printf(BHYEL"str:  %s, flag:  ", (*(t_token *)(p)).str);
	printf("%i\n"END, (*(t_token *)(p)).flag);
}

char *get_prompt(int counter)
{
	char	*directory;
	char	*prompt;
	
	directory = ft_strrchr(ft_getenv("PWD"), '/');
	if (counter % 3 == 0)
		prompt = ft_strjoin("\e[1;95m",directory + 1);
	else if (counter % 3 == 1)
		prompt = ft_strjoin("\e[1;96m",directory + 1);
	else
		prompt = ft_strjoin("\e[1;93m",directory + 1);
	prompt = ft_strjoin(prompt, "42 -> \e[0m");	
	counter++;
	return (prompt);	
}

int	interactive_loop(int argc, char **argv)
{
	char	*read_line;
	t_dlst	*tokens;
	int counter;

	counter = -1;
	(void) argc; // SOBRA
	(void) argv; // SOBRA
	while (1)
	{
		read_line = readline(get_prompt(++counter));
		add_history(read_line);
		if (read_line == NULL)
		{
			printf("\n");
			exit (EXIT_SUCCESS);
		}
		tokens = lexer(read_line);
		//ft_dlstiter(tokens, print_lexer);   //TODO  BORRAR: Imprimir lista tokens
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

void	setup_term(void)
{
	struct termios	t;

	tcgetattr(0, &t);
	t.c_lflag &= ~ECHOCTL;
	tcsetattr(0, TCSANOW, &t);
}

int	main(int argc, char **argv)
{
//	setup_term();
	initial_signals();
	//TODO: init environ if NULL
	interactive_loop(argc, argv);
	return (EXIT_SUCCESS);
}
#endif
