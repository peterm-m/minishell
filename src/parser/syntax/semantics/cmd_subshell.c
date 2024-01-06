/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_subshell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 00:50:53 by pedro             #+#    #+#             */
/*   Updated: 2024/01/06 13:12:13 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clean_subshell(t_subshell_cmd *subshell)
{
	if (subshell == NULL)
		return ;
	if (subshell->command != NULL)
		clena_command(subshell->command);
	free(subshell);
}

t_command	*make_subshell(t_command *cmd)
{
	t_subshell_cmd	*subshell;

	subshell = (t_subshell_cmd *)ft_malloc(sizeof(t_subshell_cmd));
	subshell->command = cmd;
	subshell->flags = cmd_subshell;
	return (make_command(cmd_subshell, (t_subshell_cmd *)subshell));
}
