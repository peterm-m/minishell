/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:56:16 by pedromar          #+#    #+#             */
/*   Updated: 2024/03/09 11:19:31 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void tok_p(void *t)
{
 	if (((t_token *)t)->str == NULL)
	{
		printf(BHYEL"\nToken(%p): "BHRED"void\n"
 		BHYEL"Flag:                  "BHGRN"%d\n\n"END,t,
		((t_token *)t)->flag);
	}
	else
	{
 		printf(BHYEL"\nToken(%p): "BHBLU"%s\n"
 		BHYEL"Flag:                  "BHGRN"%d\n\n"END,t,
		((t_token *)t)->str, ((t_token *)t)->flag);
	}
}
// Función que gestiona la entrada para heredoc, añade un token al final de la lista con todo el contenido de heredoc
/* void heredoc(t_dlst **lex, char *delimiter)
{
	char *line;
	char *full_history;
	int		size;
	t_token	*token;

	line = NULL;
	full_history = NULL;
	size = ft_strlen(delimiter);
	full_history = ft_strjoin(full_history, delimiter);
	full_history = ft_strjoin(full_history, "\n");
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
} */
void p_lst(void *e)
{
	int i = 0;
    printf(BHBLK"%s="END, ((t_env *)e)->key);
	while (((t_env *)e)->value[i])
	{
		printf(BHBLK"%s"END, ((t_env *)e)->value[i]);
		if (((t_env *)e)->value[i + 1])
		{
			printf(":");
		}
		i++;
	}
	printf("\n");

}

int	main(int argc, char const **argv, char const **envp)
{
	char	*read_line;
	t_data	data;
	//int j = 0; // para probar la funcionn make_char
	
	(void) argc;
	(void) argv;
	(void) envp;
	// Prueba Gestion de ENV
	/* printf(BHRED"Variables de entorno al inicio del programa: \n"END);
	ft_dlstnew(data.envlist);
	data.envlist = get_enviroment(envp,  &data.envlist);
	ft_dlstiter(data.envlist, p_lst);
	char **nueva = make_char(data.envlist); //malloc error
	while (nueva[j])
	{
		printf("%s\n", nueva[j]);
		j++;
	}
	printf(BHGRN"Buscar variable de entorno: "BHCYN"%s"BHGRN" devuelve:"BHCYN"%s""\n"END, "PATH"END, get_env_value("PATH", nueva)); */
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
		//heredoc(&data.lexlist, "hola");
		data.lexlist = lexer(read_line);
		//heredoc(&data.lexlist, "hola");
		ft_dlstiter(data.lexlist, tok_p);
		//syntax(data.lexlist);
		ft_dlstclear(&data.lexlist, ft_free);
		//expander(&data, read_line);
	}
	//ft_dlstclear(&data.lexlist, ft_free);
	//ft_dlstclear(&data.envlist, ft_free);
	return (0);
}
