/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_group.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 00:52:26 by pedro             #+#    #+#             */
/*   Updated: 2024/01/30 20:36:53 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#undef LOGS 
#define LOGS 0

void	clean_group(t_group_cmd *group)
{
	dbg("%s\n","");
	if (group == NULL)
		return ;
	if (group->command != NULL)
		clean_command(group->command);
ft_free(group);
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
#undef LOGS
#define LOGS 1