/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:33:33 by pedro             #+#    #+#             */
/*   Updated: 2024/04/18 20:21:41 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

int	connect_pipe(t_pipe *pipe, int index_cmd)
{
	if (pipe == NULL)
		return (EXIT_SUCCESS);

	if (index_cmd != 0)
	{
		if (dup2(pipe->fds[(index_cmd -1) * 2], STDIN_FILENO) < 0)
			return (EXIT_FAILURE);
	}
	if (index_cmd != pipe->len_pipe)
	{
		if (dup2(pipe->fds[(2 * index_cmd) +1], STDOUT_FILENO) < 0)
			return (EXIT_FAILURE);
	}
	close_pipe(pipe);
	return (EXIT_SUCCESS);
}

void	close_pipe(t_pipe *pipe)
{
	int	i;
	int	len_fds;

	i = 0;
	len_fds = 2 * pipe->len_pipe;
	while (i < len_fds)
		close(pipe->fds[i++]);
	free(pipe->fds);
	free(pipe);
}

int	len_pipe(t_command *cmd)
{
	t_command	*command;
	int			num_pipes;

	if (cmd == NULL || cmd->type != cmd_connection)
		return (0);
	num_pipes = 0;
	command = cmd;
	while (command->type == cmd_connection
		&& command->value.connection->connector == tt_pipe)
	{
		command = command->value.connection->first;
		num_pipes++;
	}
	return (num_pipes);
}

int	make_pipe(t_pipe **p, int num_pipes)
{
	int		i;

	*p = ft_calloc(num_pipes +1, sizeof(t_pipe));
	if (*p == NULL)
		return (EXIT_FAILURE);
	(*p)->fds = ft_calloc(num_pipes * 2, sizeof(int));
	(*p)->len_pipe = num_pipes;
	if ((*p)->fds == NULL)
	{
		free(NULL);
		return (EXIT_FAILURE);
	}
	i = -1;
	while (++i < num_pipes)
	{
		if (pipe((*p)->fds + i * 2) < 0)
		{
			while (i > 0)
				close((*p)->fds[i--]);
			free((*p)->fds);
			free(*p);
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}