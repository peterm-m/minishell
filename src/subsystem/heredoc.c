/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 19:55:18 by adiaz-uf          #+#    #+#             */
/*   Updated: 2024/04/15 20:57:12 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_expand_heredoc(char *str, int expand)
{
	int		i;
	char	*out;

	i = 0;
	if (expand == TRUE)
	{
		out = str;
		while (1)
		{
			i += search_character(out + i, '$');
			while (out[i] == '$')
				i++;
			if (!out[i])
				break ;
			out = make_expansion(out, i);
		}
		return (out);
	}
	return (str);
}

void	get_heredoc(int fd, char *del, int expand)
{
	char	*line;

	while (TRUE)
	{
		line = readline(BHRED"heredoc> "END);
		if (!line || ft_strncmp(line, del, ft_strlen(del) + 1) == 0)
		{
			ft_free(line);
			break ;
		}
		line = ft_expand_heredoc(line, expand);
		ft_putstr_fd(line, fd);
		ft_putstr_fd("\n", fd);
		ft_free(line);
	}
}

char	*heredoc(char *delimiter)
{
	char	*del;
	int		expand;
	char	*a;
	int		fd;

	expand = 1;
	printf("cadena: %s\n", delimiter);
	if (is_quotes(delimiter[0]) == 1
		&& is_quotes(delimiter[ft_strlen(delimiter)]) == 1)
	{
		expand = 0;
		del = ft_substr(delimiter, 1, ft_strlen(delimiter) - 2);
	}
	else
		del = ft_strdup(delimiter);
	a = ft_temfile();
	fd = ft_open(a, (O_CREAT | O_APPEND | O_WRONLY),
			(S_IWUSR | S_IRUSR | S_IRGRP | S_IROTH));
	get_heredoc(fd, del, expand);
	close(fd);
	ft_free(del);
	ft_free(delimiter);
	return (a);
}
