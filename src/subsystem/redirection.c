/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:39:10 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/15 12:07:54 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// TODO gestion de errores de archivos

void	close_pipe(int fd_in, int fd_out)
{
	if (fd_in > STDIN_FILENO)
		close(fd_in);
	if (fd_out > STDIN_FILENO)
		close(fd_out);
}

void	make_pipe(int fd_in, int fd_out)
{
	if (fd_in != NO_PIPE)
		ft_dup2(fd_in, STDIN_FILENO);
	if (fd_in > 0)
		ft_close(fd_in);
	if (fd_out != NO_PIPE)
		ft_dup2(fd_out, STDOUT_FILENO);
	if (fd_out == 0 || fd_out > 1)
		ft_close(fd_out);
}

void	make_redir(t_redir *redirections)
{
	t_redir	*redir;

	redir = redirections;
	open_redir(redirections);
	while (redir != NULL)
	{
		ft_dup2(redir->dest.fd, redir->source.fd);
		ft_close(redir->dest.fd);
		redir = redir->next;
	}
}

void	open_redir(t_redir *redirections)
{
	t_redir	*redir;
	int		fd;

	redir = redirections;
	while (redir != NULL)
	{
		fd = ft_open(redir->dest.filename, redir->mode_bits, redir->flags_bits);
		if (fd > 0)
			redir->dest.fd = fd;
		redir = redir->next;
	}
}
