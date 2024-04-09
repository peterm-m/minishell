/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 19:55:18 by adiaz-uf          #+#    #+#             */
/*   Updated: 2024/04/09 18:32:52 by pedromar         ###   ########.fr       */
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

void	heredoc(t_redirect *redir, char *delimiter)
{
	char	*line;
	char	*del;
	char	*full_heredoc;
	int		expand;

	line = NULL;
	expand = 1;
	if (is_quotes(delimiter[0]) && is_quotes(delimiter[ft_strlen(delimiter) - 1]))
	{
		expand = 0;
		del = ft_substr(delimiter, 1, ft_strlen(delimiter) - 2);
	}
	else
		del = ft_strdup(delimiter);
	while (TRUE)
	{
		line = readline(BHRED"heredoc> "END);
		if (!line || ft_strncmp(line, del, ft_strlen(del) + 1) == 0)
			break ;
		line = ft_expand_heredoc(line, expand);
		if (full_heredoc == NULL)
			full_heredoc = ft_strdup(line);
		else
			full_heredoc = ft_strjoin(full_heredoc, line);
		full_heredoc = ft_strjoin(full_heredoc, "\n");
	}
	ft_free(redir->dest.filename);
	redir->dest.filename = full_heredoc;
	ft_free(line);
}
