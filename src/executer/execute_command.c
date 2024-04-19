/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:32:58 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/19 14:59:08 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	execute_command(t_command *cmd, t_pipe *p, int index_cmd);
static int	execute_pipeline(t_command *cmd, t_pipe *p, int index_cmd);
static int	execute_and_or(t_command *cmd);

int	execute(t_command *cmd)
{
	return (execute_and_or(cmd));
}

static int	execute_command(t_command *cmd, t_pipe *p, int index_cmd)
{
	if (cmd->type == cmd_simple)
	{
		if (execute_builtin(cmd, p, index_cmd))
			execute_simple(cmd, p, index_cmd);
	}
	else if (cmd->type == cmd_subshell)
		execute_subshell(cmd, p, index_cmd);
	return (EXIT_SUCCESS);
}

static int	execute_pipeline(t_command *cmd, t_pipe *p, int index_cmd)
{
	int			n_pipes;

	if (cmd->type == cmd_connection
		&& cmd->value.connection->connector == tt_pipe)
	{
		if (p == NULL && index_cmd == 0)
		{
			n_pipes = len_pipe(cmd);
			index_cmd = n_pipes;
			if (make_pipe(&p, n_pipes))
				return (EXIT_FAILURE);
		}
		execute_pipeline(cmd->value.connection->first, p, index_cmd -1);
		execute_pipeline(cmd->value.connection->second, p, index_cmd);
	}
	else
		execute_command(cmd, p, index_cmd);
	return (EXIT_SUCCESS);
}

static int	execute_and_or(t_command *cmd)
{
	int	type;

	if (cmd->type == cmd_connection
		&& cmd->value.connection->connector != tt_pipe)
	{
		if (execute_and_or(cmd->value.connection->first))
			return (EXIT_FAILURE);
		type = cmd->value.connection->connector;
		if ((type == tt_and_if && g_exit_status == 0)
			|| (type == tt_or_if && g_exit_status != 0))
		{
			if (execute_and_or(cmd->value.connection->second))
				return (EXIT_FAILURE);
		}
	}
	else
		return (execute_pipeline(cmd, NULL, 0));
	return (EXIT_SUCCESS);
}
