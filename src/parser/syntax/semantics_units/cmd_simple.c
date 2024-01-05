/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_simple.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 00:56:44 by pedro             #+#    #+#             */
/*   Updated: 2024/01/05 14:07:18 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_redirection(t_dlst *lex, t_state	*state, int rule)
{
	return ;
}

t_command	*clean_command(t_command *cmd)
{
	(void) cmd;
	return (NULL);
}

t_command	*make_simple_command(t_command *cmd, t_element *element)
{
	return (cmd);
}
