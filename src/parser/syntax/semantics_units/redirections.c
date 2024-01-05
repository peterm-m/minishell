/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 01:08:35 by pedro             #+#    #+#             */
/*   Updated: 2024/01/05 14:02:26 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	join_redirection(t_dlst *lex, t_state	*state, int rule)
{
	return ;
}

void *push_heredoc (t_redirect *r)
{
	(void *) r;
	return (NULL);
}

void	append_redir(t_redirect *redir1, t_redirect *redir2)
{
	return ;
}


t_redirect	*make_redirection(t_unit_io *source, int type, t_unit_io *dest, int flag)
{
	t_redirect	*redirect;

	redirect = (t_redirect *)ft_malloc(sizeof(t_redirect));
	return (redirect);
}
