/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:39:10 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/08 17:53:07 by pedromar         ###   ########.fr       */
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

void	make_redir(t_redirect *redirections)
{
	t_redirect	*redir;

	redir = redirections;
	open_redir(redirections);
	while (redir != NULL)
	{
		ft_dup2(redir->dest.fd, redir->source.fd);
		ft_close(redir->dest.fd);
		redir = redir->next;
	}
}

void	open_redir(t_redirect *redirections)
{
	t_redirect	*redir;
	int			fd;

	redir = redirections;
	while (redir != NULL)
	{
		fd = ft_open(redir->dest.filename, redir->mode_bits,
				(S_IWUSR | S_IRUSR | S_IRGRP | S_IROTH));
		if (fd > 0)
		{
			ft_free(redir->dest.filename);
			redir->dest.fd = fd;
		}
		redir = redir->next;
	}
}
