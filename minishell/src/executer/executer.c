/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:56:16 by pedromar          #+#    #+#             */
/*   Updated: 2024/03/11 01:46:23 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	if path_name find put this in path
	else path emty string
*/

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
			if (access(path->path_name, X_OK) == 0)
				find = 1;
		}
		ft_free(directorys[i++]);
	}
	if (find == 0)
		path->path_name[0] = '\0';
	ft_free(directorys);
}

char 	**list_to_arr(t_word_list *words)
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

// Si no nombre del comando no tiene barras, intenta localizarlo en las funciones
// Si no es una funcion. Se busca en la lista de built-in
// Si no funcion ni built-in busca en PATH. Mirar descripcion 
// Si la busqueda es satisfactoria o si el nombre tiene barras, se ejecuta en shell por separado
// 		usando el resto de argumentos como parametros.
// Si falla 
// Si no se lanza de forma asincrona, la shell espera a que se complete el comando y recopila su salida.
	

void	executer(t_simple *cmd)
{
	pid_t		pid;
	t_path_name	filename;
	char		**argv;

	search_path(cmd->words->word, &filename);
	argv = list_to_arr(cmd->words);
	pid = ft_fork();
	if (pid == 0)
	{
		(void) filename;
		(void) argv;
		(void) environ;
	 	exit(0);
	}
	else
	{
		(void) 0;
	}
	return ;
}
