/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_subshell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 00:50:53 by pedro             #+#    #+#             */
/*   Updated: 2024/01/08 20:36:04 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clean_subshell(t_subshell_cmd *subshell)
{
	if (subshell == NULL)
		return ;
	if (subshell->command != NULL)
		clean_command(subshell->command);
	free(subshell);
}

t_command	*make_subshell(t_command *cmd)
{
	t_subshell_cmd	*subshell;

	subshell = (t_subshell_cmd *)ft_malloc(sizeof(t_subshell_cmd));
	subshell->command = cmd;
	subshell->flags = cmd_subshell;
	return (make_command(cmd_subshell, (t_node )subshell));
}
