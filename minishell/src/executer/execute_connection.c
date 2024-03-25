/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_connection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:54:23 by pedromar          #+#    #+#             */
/*   Updated: 2024/03/21 15:13:20 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execute_and(t_connection *cmd)
{
	(void)cmd;
	printf("---> %d\n", __LINE__);
	return (0);
}

int	execute_or(t_connection *cmd)
{
	(void)cmd;
	printf("---> %d\n", __LINE__);
	return (0);
}

int	execute_pipe(t_connection *cmd)
{
	(void)cmd;
	printf("---> %d\n", __LINE__);
	return (0);
}

int	execute_connection(t_connection *cmd)
{
	if (cmd->connector == tt_and_if)
		execute_and(cmd);
	else if (cmd->connector == tt_or_if)
		execute_or(cmd);
	else if (cmd->connector == tt_pipe)
		execute_pipe(cmd);
	return (0);
}
