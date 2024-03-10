/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_group.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 00:52:26 by pedro             #+#    #+#             */
/*   Updated: 2024/03/10 16:25:26 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#undef LOGS 
#define LOGS 0

void	print_group(t_group *group)
{
	fprintf(stderr, "group:\n");
	print_command(group->command);
}

void	clean_group(t_group *group)
{
	dbg("│\t│\t├─%s\n", "");
	if (group == NULL)
		return ;
	if (group->command != NULL)
		clean_command(group->command);
	ft_free(group);
	dbg("├─%s\n", "clean group");
}

t_command	*make_group(t_command *command)
{
	t_group	*group;

	dbg("│\t│\t├─%s\n", "");
	group = (t_group *) ft_malloc(sizeof(t_group));
	group->ignore = 0;
	group->command = command;
	return (make_command(cmd_group, (t_node)group));
}
