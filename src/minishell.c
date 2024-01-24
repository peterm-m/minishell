/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:56:16 by pedromar          #+#    #+#             */
/*   Updated: 2024/01/23 21:06:31 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void tok_p(void *t)
{
 	if (((t_token *)t)->str == NULL)
	{
		printf(BHYEL"\nToken: "BHBLU" void\n"
 		BHYEL"Flag(0/1/2): "BHGRN"%d\n\n"END,
		((t_token *)t)->flag);
	}
	else
	{
 		printf(BHYEL"\nToken: "BHBLU"%s\n"
 		BHYEL"Flag(0/1/2): "BHGRN"%d\n\n"END,
		((t_token *)t)->str, ((t_token *)t)->flag);
	}
}
// Función que gestiona la entrada para heredoc, añade un token al final de la lista con todo el contenido de heredoc
void heredoc(t_dlst **lex, char *delimiter)
{
	char *line;
	char *full_history;
	int		size;
	t_token	*token;

	line = "a";
	full_history = NULL;
	size = ft_strlen(delimiter);
	while (ft_strncmp(line, delimiter, size) != 0)
	{
		line = readline("heredoc >");
		full_history = ft_strjoin(full_history, line);
		full_history = ft_strjoin(full_history, "\n");
		//free(line);
	}
	full_history = ft_strjoin(full_history, delimiter);
	token = new_token();
	set_token(full_history, 0, ft_strlen(full_history), tt_dgreat, token);
	ft_dlstaddb(lex, ft_dlstnew(token));
}

int	main(int argc, char const **argv, char const **envp)
{
	char	*read_line;
	t_data	data;
	
	(void) argc;
	(void) argv;
	data.env = envp;
	// Subsystems
	while (1)
	{
		read_line = readline(BHMAG"minishell42-> "END);
		if (ft_strncmp(read_line, "exit", 5) == 0)
			break ;
		if (read_line[0] == '\\')
		{
			char *buffer = readline("quote >$");
			printf("buffer = %s\n", buffer);
		}
		ft_dlstnew(data.lexlist);
		data.lexlist = lexer(read_line, &data.lexlist);
		heredoc(&data.lexlist, "hola");
		ft_dlstiter(data.lexlist, tok_p);
		//syntax(data.lexlist);
		ft_dlstclear(&data.lexlist, ft_free);
		//expander(&data, read_line);
	}
	ft_dlstclear(&data.lexlist, ft_free);
	return (0);
}
