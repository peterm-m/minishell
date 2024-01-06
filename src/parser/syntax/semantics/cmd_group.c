/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_group.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 00:52:26 by pedro             #+#    #+#             */
/*   Updated: 2024/01/06 19:19:24 by pedro            ###   ########.fr       */
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

t_command *make_group(t_command *command)
{
	t_group_cmd	*group;

	group = (t_group_cmd *)ft_malloc(sizeof(t_group_cmd));
	group->ignore = 0;
	group->command = command;
	return (make_command(cmd_group, (t_simple_cmd *)group));
}
