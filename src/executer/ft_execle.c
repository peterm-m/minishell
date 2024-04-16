/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 19:23:11 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/16 20:46:27 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_execle(t_word *args)
{
	t_path_name	filename;
	char		**argv;

	if (args == NULL)
		exit(EXIT_SUCCESS);
	argv = list_to_argv(args);
	if (argv[0] == NULL)
		(void) 0;
	else if (get_pathname(argv[0], &filename) == 0)
	{
		ft_putstr_fd(argv[0], 2);
		ft_putstr_fd(": Command not found\n", 2);
		exit(STATUS_CMD_NOT_FOUND);
	}
	else if (access(filename.path_name, X_OK) != 0)
	{
		ft_putstr_fd(argv[0], 2);
		ft_putstr_fd(": Permission denied\n", 2);
		exit(STATUS_CMD_NOT_EXEC);
	}
	else
		ft_execve(filename.path_name, argv, environ);
	clean_argv(argv);
	exit(EXIT_SUCCESS);
}
