/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:39:10 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/19 14:51:31 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	open_files(t_redir *redirections)
{
	t_redir	*redir;
	int		fd;

	redir = redirections;
	while (redir != NULL)
	{
		fd = ft_open(redir->dest.filename, redir->mode_bits, redir->flags_bits);
		redir->dest.fd = fd;
		redir = redir->next;
	}
}

void	open_redir(t_redir *redirections)
{
	t_redir	*redir;

	redir = redirections;
	open_files(redirections);
	while (redir != NULL)
	{
		ft_dup2(redir->dest.fd, redir->source.fd);
		close(redir->dest.fd);
		redir = redir->next;
	}
}
