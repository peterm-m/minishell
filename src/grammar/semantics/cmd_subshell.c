/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_subshell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 00:50:53 by pedro             #+#    #+#             */
/*   Updated: 2024/04/08 17:01:03 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#undef LOGS 
#define LOGS 0

void	clean_subshell(t_subshell *subshell)
{
	dbg("│\t│\t├─%s\n", "");
	if (subshell == NULL)
		return ;
	if (subshell->command != NULL)
		clean_command(subshell->command);
	ft_free(subshell);
	dbg("├─%s\n", "clean_subshell");
}

t_command	*make_subshell(t_command *cmd)
{
	t_subshell	*subshell;

	dbg("│\t│\t├─%s\n", "");
	subshell = (t_subshell *)ft_malloc(sizeof(t_subshell));
	subshell->command = cmd;
	subshell->flags = cmd_subshell;
	return (make_command(cmd_subshell, (t_node)subshell));
}
