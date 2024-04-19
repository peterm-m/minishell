/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:10:16 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/19 15:18:43 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	num_files_dir(char *name)
{
	char			n_files;
	DIR				*d;

	d = opendir(name);
	n_files = 0;
	if (d)
	{
		while (readdir(d))
			n_files++;
		closedir(d);
	}
	return (n_files);
}

// TODO: funcion que de lista de elementos
// en un directorio ordenados alphanumericamente
// falta el llenado del array despues del break

char	**get_file_names(char *name)
{
	char			**arr;
	char			n_files;
	DIR				*d;
	struct dirent	*dir;

	n_files = num_files_dir(name);
	arr = ft_calloc(n_files, sizeof(char *));
	if (!arr)
		return (NULL);
	n_files = 0;
	d = opendir(".");
	if (d)
	{
		while (1)
		{
			dir = readdir(d);
			if (!dir)
				break ;
		}
		closedir(d);
	}
	return (arr);
}
