/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 19:23:11 by pedromar          #+#    #+#             */
/*   Updated: 2024/03/18 19:22:57 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


// TODO: testear que pasa si NULL en input
//		 testear PATH no existe
//		 testear que pasa si no se encuentra dir
//		 testear que pasa si existe pero sin permisos de ejecucion

//TODO gestion error, name or path to long

static int	search_path(char *name, t_path_name *path)
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
	ft_free(directorys);
	return (find);
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

void	ft_execle(t_word_list *args)
{
	t_path_name	filename;
	char		**argv;

	argv = list_to_arr(args);
	if (search_path(args->word, &filename))
		return ;
	ft_execve(filename.path_name, argv, environ);
}
