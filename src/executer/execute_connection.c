/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_connection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:54:23 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/18 18:59:54 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	execute_and(t_connection *cmd, t_pipe *p, int index_cmd)
{
	execute_command(cmd->first, p, index_cmd);
	if (g_exit_status == 0)
		execute_command(cmd->second, p, index_cmd);
	return (0);
}

static int	execute_or(t_connection *cmd, t_pipe *p, int index_cmd)
{
	execute_command(cmd->first, p, index_cmd);
	if (g_exit_status != 0)
		execute_command(cmd->second, p, index_cmd);
	return (0);
}

static int	execute_pipe(t_command *cmd, t_pipe *p, int index_cmd)
{
	t_command	*command;
	t_pipe		*new_p;
	int			n_pipes;

	n_pipes = len_pipe(cmd);
	new_p = make_pipe(n_pipes);
	if (new_p == NULL)
		return (0);
	
	close_pipe(p);
	free(p);
	return (0);
}

int	execute_connection(t_command *cmd, t_pipe *p, int index_cmd)
{
	t_connection	*connection;

	connection = cmd->value.connection;
	if (connection->connector == tt_and_if)
		execute_and(connection, p, index_cmd);
	else if (connection->connector == tt_or_if)
		execute_or(connection, p, index_cmd);
	else if (connection->connector == tt_pipe)
		execute_pipe(cmd, p, index_cmd);
	return (0);
}
