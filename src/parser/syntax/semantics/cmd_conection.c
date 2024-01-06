/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_conection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 00:38:01 by pedro             #+#    #+#             */
/*   Updated: 2024/01/06 19:19:05 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clean_connection(t_connection *connection)
{
	if (connection == NULL)
		return ;
	if (connection->first != NULL)
		clena_command(connection->first);
	if (connection->second != NULL)
		clena_command(connection->second);
	free(connection);
}

t_command	*make_connection(t_command	*cmd1, t_command *cmd2, int type)
{
	t_connection	*connection;

	connection = (t_connection *)ft_malloc(sizeof(t_connection));
	connection->connector = type;
	connection->first = cmd1;
	connection->second = cmd2;
	return (make_command(cmd_connection, (t_connection *)connection));
}
