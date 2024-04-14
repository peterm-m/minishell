/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:32:58 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/14 17:27:18 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// TODO: Si cmd->redirs != NULL
// hacer redirecciones externas (comprobar como se hacen)

int	execute_command(t_command *cmd, int fd_in, int fd_out)
{
	if (cmd->type == cmd_simple)
	{
		if (execute_builtin(cmd, fd_out))
			execute_simple(cmd, fd_in, fd_out);
	}
	else if (cmd->type == cmd_connection)
		execute_connection(cmd, fd_in, fd_out);
	else if (cmd->type == cmd_subshell)
		execute_subshell(cmd->value.subshell, fd_in, fd_out);
	return (0);
}
