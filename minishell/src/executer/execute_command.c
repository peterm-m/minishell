/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:32:58 by pedromar          #+#    #+#             */
/*   Updated: 2024/03/27 18:02:29 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execute_command(t_command *cmd, int fd_in, int fd_out)
{
	// TODO: Si cmd->redirects != NULL hacer redirecciones externas (comprobar como se hacen)
	if (cmd->type == cmd_simple)
		execute_simple(cmd, fd_in, fd_out);
	else if (cmd->type == cmd_connection)
		execute_connection(cmd, fd_in, fd_out);
	else if (cmd->type == cmd_subshell)
		execute_subshell(cmd->value.subshell, fd_in, fd_out);
	return (0);
}
