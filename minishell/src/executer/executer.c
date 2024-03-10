/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:56:16 by pedromar          #+#    #+#             */
/*   Updated: 2024/03/10 20:21:56 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	if path_name find put this in path
	else path emty string
*/

void	search_path(t_file_name *name, t_path_name *path)
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
			ft_strlcat(path->path_name, name->file_name, PATH_MAX);
			if (access(path->path_name, X_OK) == 0)
				find = 1;
		}
		ft_free(directorys[i++]);
	}
	if (find == 0)
		path->path_name[0] = '\0';
	ft_free(directorys);
}

void	executer(void)
{
	return ;
}
