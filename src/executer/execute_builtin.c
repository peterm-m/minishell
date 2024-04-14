/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:26:54 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/14 15:01:07 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(char *str)
{
	if (ft_strncmp(str, "cd", 3) == 0)
		return (1);
	else if (ft_strncmp(str, "echo", 5) == 0)
		return (1);
	else if (ft_strncmp(str, "env", 4) == 0)
		return (1);
	else if (ft_strncmp(str, "exit", 5) == 0)
		return (1);
	else if (ft_strncmp(str, "export", 7) == 0)
		return (1);
	else if (ft_strncmp(str, "pwd", 4) == 0)
		return (1);
	else if (ft_strncmp(str, "unset", 6) == 0)
		return (1);
	return (0);
}

int	execute_builtin(t_word *words, int fd_out)
{
	char	**argv;
	int		status;

	argv = list_to_argv(words);
	status = -1;
	if (fd_out == NO_PIPE)
		fd_out = STDOUT_FILENO;
	if (argv[0] && ft_strncmp(argv[0], "cd", 3) == 0)
		status = cd_main(argv, fd_out);
	else if (argv[0] && ft_strncmp(argv[0], "echo", 5) == 0)
		status = echo_main(argv, fd_out);
	else if (argv[0] && ft_strncmp(argv[0], "env", 4) == 0)
		status = env_main(fd_out);
	else if (argv[0] && ft_strncmp(argv[0], "exit", 5) == 0)
		status = exit_main(argv);
	else if (argv[0] && ft_strncmp(argv[0], "export", 7) == 0)
		status = export_main(argv, fd_out);
	else if (argv[0] && ft_strncmp(argv[0], "pwd", 4) == 0)
		status = pwd_main(fd_out);
	else if (argv[0] && ft_strncmp(argv[0], "unset", 6) == 0)
		status = unset_main(argv);
	clean_argv(argv);
	if (status != -1)
		g_exit_status = status;
	return (status);
}

/* int	execute_builtin(t_word *words, int fd_out)
{
	char	**argv;

	argv = list_to_argv(words);
	if (fd_out == NO_PIPE)
		fd_out = STDOUT_FILENO;
	if (ft_strncmp(argv[0], "cd", 3) == 0)
		g_exit_status = cd_main(argv, fd_out);
	else if (ft_strncmp(argv[0], "echo", 5) == 0)
		g_exit_status = echo_main(argv, fd_out);
	else if (ft_strncmp(argv[0], "env", 4) == 0)
		g_exit_status = env_main(fd_out);
	else if (ft_strncmp(argv[0], "exit", 5) == 0)
		g_exit_status = exit_main(argv);
	else if (ft_strncmp(argv[0], "export", 7) == 0)
		g_exit_status = export_main(argv, fd_out);
	else if (ft_strncmp(argv[0], "pwd", 4) == 0)
		g_exit_status = pwd_main(fd_out);
	else if (ft_strncmp(argv[0], "unset", 6) == 0)
		g_exit_status = unset_main(argv);
	clean_argv(argv);
	return (-1);
} */