/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 19:55:18 by adiaz-uf          #+#    #+#             */
/*   Updated: 2024/04/16 12:38:34 by pedro            ###   ########.fr       */
=======
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 19:55:18 by adiaz-uf          #+#    #+#             */
/*   Updated: 2024/04/15 21:00:01 by adiaz-uf         ###   ########.fr       */
>>>>>>> bb9df61c1e5e0402f5d27a17bbb27822da134c27
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

char	*heredoc(t_redir *redir, char *delimiter)
{
	char	*del;
	int		expand;
	char	*a;
	int		fd;

	expand = 1;
<<<<<<< HEAD
	redir->mode_bits = (O_CREAT | O_RDWR);
	redir->here_doc_eof = delimiter;
	if (is_quotes(delimiter[0])
		&& is_quotes(delimiter[ft_strlen(delimiter) - 1]))
=======
	printf("cadena: %s\n", delimiter);
	if (is_quotes(delimiter[0]) == 1
		&& is_quotes(delimiter[ft_strlen(delimiter)]) == 1)
>>>>>>> bb9df61c1e5e0402f5d27a17bbb27822da134c27
	{
		expand = 0;
		del = ft_substr(delimiter, 1, ft_strlen(delimiter) - 2);
	}
	else
		del = ft_strdup(delimiter);
	a = ft_temfile();
	fd = ft_open(a, redir->mode_bits, redir->flags_bits);
	get_heredoc(fd, del, expand);
	close(fd);
	ft_free(del);
	ft_free(delimiter);
	return (a);
}
