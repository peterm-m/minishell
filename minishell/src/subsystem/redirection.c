/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:39:10 by pedromar          #+#    #+#             */
/*   Updated: 2024/03/20 20:20:26 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// TODO: PIPES

void	make_redir(t_redirect *redirections)
{
	int			fd;
	t_redirect	*redir;

	redir = redirections;
	open_redir(redirections);
	while (redir != NULL)
	{
		dup2(redir->dest.fd, redir->source.fd);
		ft_close(fd);
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
			redir->dest.fd = fd;
		redir = redir->next;
	}
}
