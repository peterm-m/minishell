/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 19:23:11 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/04 19:49:28 by adiaz-uf         ###   ########.fr       */
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
			if (access(path->path_name, F_OK) == 0)
				find = 1;
		}
		free(directorys[i++]);
	}
	free(directorys);
	return (find);
}

void	ft_execle(t_word_list *args)
{
	t_path_name	filename;
	char		**argv;

	
	argv = list_to_arr(args);
	if (search_path(args->word, &filename) == 0)
	{
		ft_putstr_fd(args->word, 2);
		ft_putstr_fd(": Command not found\n", 2);
		exit(STATUS_CMD_NOT_FOUND);
	}
	else if (access(filename.path_name, X_OK) != 0)
	{
		ft_putstr_fd(args->word, 2);
		ft_putstr_fd(": Permission denied\n", 2);
		exit(STATUS_CMD_NOT_EXEC);
	}
	ft_execve(filename.path_name, argv, environ);
	clean_arr(argv);
}
