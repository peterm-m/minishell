/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:56:16 by pedromar          #+#    #+#             */
/*   Updated: 2024/03/12 19:28:06 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	if path_name find put this in path
	else path emty string
*/

void	search_builtin(char *name, t_path_name *path)
{
	int			i;
	int			find;
	static char	*directory = "/src/builtins/";
    static char	*builtins[7] = \
	{"cd", "echo", "env", "pwd", "export", "unset", "exit"};

	printf("Empieza a buscar\n");//
	i = 0;
	find = 0;
	while (i < 7)
	{
		printf("Builtin[%i]: %s\n",i, builtins[i]);//
		if (ft_strncmp(name, builtins[i], ft_strlen(builtins[i]) + 1) == 0 && find == 0)
		{
			ft_strlcpy(path->path_name, directory, PATH_MAX);
			ft_strlcat(path->path_name, builtins[i], PATH_MAX);
			printf(BHYEL"Path a validar: %s\n"END, path->path_name);//
			printf("pwd: %s\n", getenv("PWD"));//
			if (access(path->path_name, F_OK) == 0) // CHECK
			{
				printf(BHGRN"Path valido: %s\n"END, path->path_name);//
				find = 1;
			}	
		}
		i++;
	}
 /* 	if (find == 0)
		path->path_name[0] = '\0'; */
	printf("TERMINA search builtins\n\n");
}

// TODO: testear que pasa si NULL en input
//		 testear PATH no existe
//		 testear que pasa si no se encuentra dir
//		 testear que pasa si existe pero sin permisos de ejecucion

void	search_path(char *name, t_path_name *path)
{
	int			i;
	int			find;
	char		**directorys;

	i = 0;
	find = 0;
	directorys = ft_split(ft_getenv("PATH"), ':');
	while (directorys[i])
	{
		if (find == 0)
		{
			ft_strlcpy(path->path_name, directorys[i], PATH_MAX);
			ft_strlcat(path->path_name, "/", PATH_MAX);
			ft_strlcat(path->path_name, name, PATH_MAX);
			if (access(path->path_name, X_OK) == 0) // CHECK
				find = 1;
		}
		ft_free(directorys[i++]);
	}
	if (find == 0)
		path->path_name[0] = '\0';
	ft_free(directorys);
}

char	**list_to_arr(t_word_list *words)
{
	size_t		n_word;
	char		**arr;
	t_word_list	*tmp;

	n_word = 0;
	tmp = words; 
	while (tmp)
	{
		tmp = tmp->next;
		n_word++;
	}
	arr = ft_malloc((n_word +1) * sizeof(char *));
	arr[n_word] = NULL;
	n_word = 0;
	tmp = words;
	while (tmp)
	{
		arr[n_word++] = tmp->word;
		tmp = tmp->next;
	}
	return (arr);
}

//NO: Si no nombre del comando no tiene barras, intenta localizarlo en las funciones

//SI: Si no es una funcion. Se busca en la lista de built-in
//SI: Si no funcion ni built-in busca en PATH. Mirar descripcion 
//SI: Si la busqueda es satisfactoria o si el nombre tiene barras, se ejecuta en shell por separado
// 		usando el resto de argumentos como parametros.
//SI: Si falla 

//NO: Si no se lanza de forma asincrona, la shell espera a que se complete el comando y recopila su salida.

void	executer(t_simple *cmd)
{
	pid_t		pid;
	t_path_name	filename;
	char		**argv;
	int			status;

	search_path(cmd->words->word, &filename);
	search_builtin(cmd->words->word, &filename);
	printf("TERMINA\n\n");
	argv = list_to_arr(cmd->words);
	pid = ft_fork();
	if (pid == 0)
	{
		printf("filename.path_name %s\n", filename.path_name);
		ft_signal(SIGINT, SIG_DFL); // CHECK 
		ft_execve(filename.path_name, argv, environ);
		// TODO: gestionar error. 
	}
	else
		waitpid(pid, &status, WUNTRACED);
		
	return ;
}
