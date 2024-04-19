/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filename_expansion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 21:04:04 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/19 17:46:42 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	match(char *pattern, char *name);

static int	wildcard(int c, char *pattern, char *name)
{
	while (1)
	{
		if (match(pattern, name))
			return (1);
		if (*name == '\0' || (*name++ == c || c == '?'))
			break ;
	}
	return (0);
}

static int	match(char *pattern, char *name)
{
	if (pattern[0] == '\0')
		return (1);
	if (pattern[0] == '*')
		return (wildcard(pattern[0], pattern + 1, name));
	if (*name != '\0' && (pattern[0] == '?' || pattern[0] == *name))
		return (match(pattern + 1, name + 1));
	return (0);
}

static void	select_files(DIR *d, char *file_name, char *str)
{
	char			*pattern;
	struct dirent	*dir;

	pattern = str;
	while (1)
	{
		dir = readdir(d);
		if (!dir)
			break ;
		if (pattern[0] != '.' && dir->d_name[0] == '.')
			continue ;
		if (match(pattern, dir->d_name))
		{
			file_name += ft_strlcpy(file_name, dir->d_name, PATH_MAX);
			*file_name++ = 31;
		}
		pattern = str;
	}
}

char	*filename_expansion(char *str)
{
	DIR		*d;
	int		i;
	char	*out;

	i = num_files_dir(".");
	out = ft_calloc((PATH_MAX +1) * i, sizeof(char));
	if (out == NULL)
		return (str);
	d = opendir(".");
	if (d)
	{
		select_files(d, out, str);
		closedir(d);
	}
	return (out);
}
