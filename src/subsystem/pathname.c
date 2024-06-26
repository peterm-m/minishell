/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathname.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 13:22:40 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/08 18:13:18 by pedromar         ###   ########.fr       */
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
	while (directorys && directorys[i])
	{
		if (find == 0)
		{
			ft_strlcpy(path->path_name, directorys[i], PATH_MAX);
			ft_strlcat(path->path_name, "/", PATH_MAX);
			ft_strlcat(path->path_name, name, PATH_MAX);
			if (access(path->path_name, F_OK) == 0)
				find = 1;
		}
		ft_free(directorys[i++]);
	}
	if (directorys != NULL)
		ft_free(directorys);
	return (find);
}

int	get_pathname(char *name, t_path_name *path)
{
	if (ft_strchr((const char *)name, '/') != NULL)
		return (ft_strlcpy(path->path_name, name, PATH_MAX));
	else
		return (search_path(name, path));
}
