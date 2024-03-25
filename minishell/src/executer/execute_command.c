/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:32:58 by pedromar          #+#    #+#             */
/*   Updated: 2024/03/21 15:44:57 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execute_command(t_command *cmd)
{
	// TODO: Si cmd->redirects != NULL hacer redirecciones externas (comprobar como se hacen)
	if (cmd->type == cmd_simple)
		execute_simple(cmd->value.simple);
	else if (cmd->type == cmd_connection)
		execute_connection(cmd->value.connection);
	else if (cmd->type == cmd_subshell)
		execute_subshell(cmd->value.subshell);
	return (0);
}
