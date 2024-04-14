/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 19:23:11 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/14 15:03:06 by pedromar         ###   ########.fr       */
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
	if (get_pathname(args->word, &filename) == 0)
	{
		ft_putstr_fd(args->word, 2);
		ft_putstr_fd(": Command not found\n", 2);
		exit(STATUS_CMD_NOT_FOUND);
	}
	else if (access(filename.path_name, X_OK) != 0)
	{
		ft_putstr_fd(args->word, 2);
		ft_putstr_fd(": Permission denied\n", 2);
		exit(STATUS_CMD_NOT_EXEC);
	}
	ft_execve(filename.path_name, argv, environ);
	clean_argv(argv);
	exit(EXIT_SUCCESS);
}
