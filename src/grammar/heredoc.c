/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 19:55:18 by adiaz-uf          #+#    #+#             */
/*   Updated: 2024/04/19 15:27:20 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	parent_heredoc(pid_t pid)
{
	if (pid < 0)
		return ;
	wait_signals();
	waitpid(pid, 0, WUNTRACED);
	initial_signals();
}

static char	*ft_expand_heredoc(char *str, int expand)
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

static void	child_heredoc(int fd, char *del, int expand)
{
	char	*line;

	child_signals();
	while (TRUE)
	{
		line = readline(BHRED"heredoc> "END);
		if (!line || ft_strncmp(line, del, ft_strlen(del) + 1) == 0)
		{
			ft_free(line);
			exit(EXIT_SUCCESS);
		}
		line = ft_expand_heredoc(line, expand);
		ft_putstr_fd(line, fd);
		ft_putstr_fd("\n", fd);
		ft_free(line);
	}
}

char	*heredoc(t_redir *redir, char *delimiter)
{
	pid_t	pid;
	int		expand;
	char	*a;
	int		fd;

	redir->mode_bits = (O_CREAT | O_RDWR);
	redir->here_doc_eof = delimiter;
	expand = !((is_quotes(delimiter[0]) \
		&& is_quotes(delimiter[ft_strlen(delimiter) - 1])));
	quote_remove(delimiter);
	a = ft_temfile();
	if (a == NULL)
		return (NULL);
	fd = minish_open(a, redir->mode_bits, redir->flags_bits);
	if (fd < 0)
		return (NULL);
	pid = minish_fork();
	if (pid == 0)
		child_heredoc(fd, delimiter, expand);
	else if (pid > 0)
		parent_heredoc(pid);
	close(fd);
	ft_free(delimiter);
	return (a);
}
