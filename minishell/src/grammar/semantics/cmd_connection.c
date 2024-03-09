/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_connection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 00:38:01 by pedro             #+#    #+#             */
/*   Updated: 2024/03/08 14:39:49 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#undef LOGS 
#define LOGS 0

void	print_connection(t_connection *connection)
{
	printf("connection: type %d\n", connection->connector);
	printf("CMD1:\n");
	print_command(connection->first);
	printf("CMD2\n:");
	print_command(connection->first);
}

void	clean_connection(t_connection *connection)
{
	t_command	*cmd1;
	t_command	*cmd2;

	if (connection == NULL)
		return ;
	cmd1 = connection->first;
	cmd2 = connection->second;
	ft_free(connection);
	if (connection->first != NULL)
		clean_command(cmd1);
	if (connection->second != NULL)
		clean_command(cmd2);
	dbg("├─%s\n", "clean connection");
}

t_command	*make_connection(t_command *cmd1, t_command *cmd2, int type)
{
	t_connection	*connection;

	dbg("│\t│\t├─%s\n", "make connection");
	connection = (t_connection *)ft_malloc(sizeof(t_connection));
	connection->connector = type;
	connection->first = cmd1;
	connection->second = cmd2;
	return (make_command(cmd_connection, (t_node)connection));
}
