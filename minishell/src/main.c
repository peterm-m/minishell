/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:42:25 by pedromar          #+#    #+#             */
/*   Updated: 2024/03/25 20:11:09 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_exit_status;

void print_lexer(void *p)   //TODO  BORRAR: Imprimir lista tokens
{
	printf(BHYEL"str:  %s, flag:  "END, (*(t_token *)(p)).str);
	printf(BHYEL"%i\n"END, (*(t_token *)(p)).flag);
}

char *get_prompt(int counter)
{
	char	*directory;
	char	pwd[PATH_MAX];
	char	*prompt;
	
	directory = ft_strrchr(getcwd(pwd, PATH_MAX), '/');
	// Esto de segmentation si nos vacian el env. En ese caso getenv(PWD) es NULL,
	//directory es NULL, cuando haces el strjoin da segmentation,
	//TODO: puedes poner un promp por defecto en caso de que no tengamos PWD.
//	if (directory == NULL)
//		directory = ;
	// Por otro lado, si no se te ocurre como hacerlo, o si prefieres avanzar en otros lados.
	// no se si el manejo del promp es mandatory. Podemos usar todo el tiempo el mismo.
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

static int	interactive_loop(void)
{
	char	*read_line;
	t_dlst	*tokens;
	int counter;

	counter = -1;
	while (1)
	{
		//read_line = readline(get_prompt(++counter));
		read_line = "$HOME$PWD";
		//add_history(read_line);
		if (read_line == NULL)
		{
			printf("\n");
			exit (EXIT_SUCCESS);
		}
		tokens = lexer(read_line);
		ft_dlstiter(tokens, print_lexer); //TODO  BORRAR: Imprimir lista tokens
		if (tokens == NULL)
			continue ;
		syntax(&tokens);
		//redirections();
		//executers();
		//????
		//rl_on_new_line();  TODO:QUITAR COMENTARIO
	}
	//rl_clear_history(); TODO:QUITAR COMENTARIO
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

//void	setup_term(void)
//{
//	struct termios	t;
//
//	tcgetattr(0, &t);
//	t.c_lflag &= ~ECHOCTL;
//	tcsetattr(0, TCSANOW, &t);
//}

int	main()
{
//	setup_term();
	g_exit_status = 0;
	initial_signals();
	interactive_loop();
	return (EXIT_SUCCESS);
}
#endif
