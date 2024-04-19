/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:10:16 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/19 18:09:18 by pedromar         ###   ########.fr       */
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
