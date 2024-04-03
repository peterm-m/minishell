/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filename_expansion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 21:04:04 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/03 17:16:29 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	match_character(char *pattern, char *text);

static int	match_wildcard(int c, char *pattern, char *text)
{
	while (1)
	{
		if (match_character(pattern, text))
			return (1);
		if (*text != '\0' && (*text++ == c || c == '?'))
			break ;
	}
	return (0);
}

static int	match_character(char *pattern, char *text)
{
	if (pattern[0] == '\0')
		return (1);
	if (pattern[0] == '*')
		return (match_wildcard(pattern[0], pattern + 1, text));
	if (*text != '\0' && (pattern[0] == '?' || pattern[0] == *text))
		return (match_character(pattern + 1, text + 1));
	return (0);
}

static int	match(char *pattern, char *text)
{
	while (1)
	{
		if (match_character(pattern, text))
			return (1);
		if (*text++ != '\0')
			break ;
	}
	return (0);
}


// TODO user funcion get_file_names que la cadena se forma ordenada 
static void	select_files(DIR *d, char *file_name, char *str)
{
	int				i;
	char			*pattern;
	struct dirent	*dir;

	pattern = str;
	i = 0;
	while (1)
	{
		dir = readdir(d);
		if (!dir)
			break ;
		if (pattern[0] != '.' && dir->d_name[0] == '.')
			continue ;
		if (match(pattern, dir->d_name))
		{
			file_name += ft_strlcpy(file_name, dir->d_name, 256);
			*file_name++ = ' ';
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
	out = ft_calloc(257 * i, sizeof(char));
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
