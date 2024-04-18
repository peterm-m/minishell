/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:26:54 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/18 15:08:24 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	index_builtin(char *str)
{
	int	index;

	if (ft_strncmp(str, "cd", 3) == 0)
		index = 0;
	else if (ft_strncmp(str, "echo", 5) == 0)
		index = 1;
	else if (ft_strncmp(str, "env", 4) == 0)
		index = 2;
	else if (ft_strncmp(str, "exit", 5) == 0)
		index = 3;
	else if (ft_strncmp(str, "export", 7) == 0)
		index = 4;
	else if (ft_strncmp(str, "pwd", 4) == 0)
		index = 5;
	else if (ft_strncmp(str, "unset", 6) == 0)
		index = 6;
	else
		index = -1;
	return (index);
}

static int	fd_builtin(t_redir *redirs, int fd_out)
{
	t_redir		*r;
	int			fd;

	fd = fd_out;
	if (redirs == NULL && fd_out == STDOUT_FILENO)
		return (STDOUT_FILENO);
	else if (redirs == NULL && fd_out != STDOUT_FILENO)
		return (fd_out);
	r = redirs;
	while (r != NULL)
	{
		fd = ft_open(r->dest.filename, r->mode_bits, r->flags_bits);
		if (r->rtype == r_input_direction
			|| r->rtype == r_appending_to)
			ft_close(fd);
		else if (r->rtype == r_appending_to || r->rtype == r_output_direction)
		{
			if (fd_out >= 0)
				ft_close(fd_out);
			fd_out = fd;
		}
		r = r->next;
	}
	return (fd_out);
}

static int	run_builtin(int index, char **argv, int fd_out)
{
	int			status;
	static int	(*builtin[7])(char **, int) = {\
		cd_main, echo_main, env_main,
		exit_main, export_main, pwd_main,
		unset_main};

	status = builtin[index](argv, fd_out);
	return (status);
}

int	execute_builtin(t_command *cmd, int fd_out)
{
	t_simple	*simple;
	char		**argv;
	int			index;

	simple = cmd->value.simple;
	if (simple->words == NULL)
		return (EXIT_FAILURE);
	argv = list_to_argv(simple->words);
	if (argv == NULL || argv[0] == NULL)
	{
		clean_argv(argv);
		return (EXIT_SUCCESS);
	}
	index = index_builtin(argv[0]);
	if (index < 0)
		return (EXIT_FAILURE);
	fd_out = fd_builtin(simple->redirs, fd_out);
	g_exit_status = run_builtin(index, argv, fd_out);
	clean_argv(argv);
	return (EXIT_SUCCESS);
}
