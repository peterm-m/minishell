/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 19:55:18 by adiaz-uf          #+#    #+#             */
/*   Updated: 2024/04/07 11:33:49 by adiaz-uf         ###   ########.fr       */
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
	int		expand;

	line = NULL;
	expand = 1;
	if (is_quotes(delimiter[0]) && is_quotes(delimiter[ft_strlen(delimiter)]))
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
		redir->here_doc_eof = ft_strjoin(redir->here_doc_eof, line);
		redir->here_doc_eof = ft_strjoin(redir->here_doc_eof, "\n");
	}
	free(line);
}
