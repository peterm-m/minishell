/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 19:23:11 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/19 15:09:31 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	search_path(char *name, t_path_name *path);
static int	get_pathname(char *name, t_path_name *path);

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

static int	search_path(char *name, t_path_name *path)
{
	int			i;
	int			find;
	char		**directorys;

	i = 0;
	find = 0;
	directorys = ft_split(ft_environ("PATH", GET, 0), ':');
	while (directorys && directorys[i])
	{
		if (find == 0)
		{
			ft_strlcpy(path->path_name, directorys[i], PATH_MAX);
			ft_strlcat(path->path_name, "/", PATH_MAX);
			ft_strlcat(path->path_name, name, PATH_MAX);
			if (access(path->path_name, F_OK) == 0)
				find = 1;
		}
		ft_free(directorys[i++]);
	}
	if (directorys != NULL)
		ft_free(directorys);
	return (find);
}

static int	get_pathname(char *name, t_path_name *path)
{
	if (ft_strchr((const char *)name, '/') != NULL)
		return (ft_strlcpy(path->path_name, name, PATH_MAX));
	else
		return (search_path(name, path));
}
