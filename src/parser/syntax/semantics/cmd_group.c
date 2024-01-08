/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_group.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 00:52:26 by pedro             #+#    #+#             */
/*   Updated: 2024/01/08 20:36:56 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clean_group(t_group_cmd *group)
{
	if (group == NULL)
		return ;
	if (group->command != NULL)
		clean_command(group->command);
	free(group);
}

t_command	*make_group(t_command *command)
{
	t_group_cmd	*group;

	group = (t_group_cmd *)ft_malloc(sizeof(t_group_cmd));
	group->ignore = 0;
	group->command = command;
	return (make_command(cmd_group, (t_node )group));
}
