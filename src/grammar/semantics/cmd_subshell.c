/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_subshell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 00:50:53 by pedro             #+#    #+#             */
/*   Updated: 2024/02/21 16:58:08 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#undef LOGS 
#define LOGS 0

void	print_subshell(t_subshell *subshell)
{
	fprintf(stderr,"subshell: flags %d\n", subshell->flags);
	print_command(subshell->command);
}

void	clean_subshell(t_subshell *subshell)
{dbg("│\t│\t├─%s\n","");
	if (subshell == NULL)
		return ;
	if (subshell->command != NULL)
		clean_command(subshell->command);
	ft_free(subshell);
}

t_command	*make_subshell(t_command *cmd)
{dbg("│\t│\t├─%s\n","");
	t_subshell	*subshell;

	subshell = (t_subshell *)ft_malloc(sizeof(t_subshell));
	subshell->command = cmd;
	subshell->flags = cmd_subshell;
	return (make_command(cmd_subshell, (t_node)subshell));
}
