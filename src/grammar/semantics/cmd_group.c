/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_group.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 00:52:26 by pedro             #+#    #+#             */
/*   Updated: 2024/01/24 21:25:17 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clean_group(t_group_cmd *group)
{
	dbg("%s\n","");
	if (group == NULL)
		return ;
	if (group->command != NULL)
		clean_command(group->command);
	free(group);
}

t_command	*make_group(t_command *command)
{
	dbg("%s\n","");
	t_group_cmd	*group;

	group = (t_group_cmd *) ft_malloc(sizeof(t_group_cmd));
	group->ignore = 0;
	group->command = command;
	return (make_command(cmd_group, (t_node)group));
}
