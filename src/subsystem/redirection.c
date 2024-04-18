/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:39:10 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/18 17:40:34 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// TODO gestionar mensaje de error

static int	open_files(t_redir *redirections)
{
	t_redir	*redir;
	int		fd;

	redir = redirections;
	while (redir != NULL)
	{
		fd = open(redir->dest.filename, redir->mode_bits, redir->flags_bits);
		if (fd > 0)
			redir->dest.fd = fd;
		else
			return (EXIT_FAILURE);
		redir = redir->next;
	}
	return (EXIT_SUCCESS);
}

int	open_redir(t_redir *redirections)
{
	t_redir	*redir;

	redir = redirections;
	if (open_files(redirections))
		return (EXIT_FAILURE);
	while (redir != NULL)
	{
		if (ft_dup2(redir->dest.fd, redir->source.fd) < 0)
			return (EXIT_FAILURE);
		ft_close(redir->dest.fd);
		redir = redir->next;
	}
	return (EXIT_SUCCESS);
}
