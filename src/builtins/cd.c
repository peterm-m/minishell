/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:09:57 by adiaz-uf          #+#    #+#             */
/*   Updated: 2024/04/19 17:25:03 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	update_pwd(int fd)
{
	char	pwd[PATH_MAX];
	char	new_pwd[PATH_MAX];

	if (getcwd(pwd, PATH_MAX) == NULL)
	{
		ft_putendl_fd("Error: PWD not found", fd);
		return (EXIT_FAILURE);
	}
	ft_strlcpy(new_pwd, "PWD=", PATH_MAX);
	ft_strlcat(new_pwd, getcwd(pwd, PATH_MAX), PATH_MAX);
	ft_environ(ft_strdup(new_pwd), ADD, 0);
	return (EXIT_SUCCESS);
}

static int	update_oldpwd(int fd)
{
	char	*old_pwd;

	if (ft_environ("PWD", GET, 0) == NULL)
		return (EXIT_FAILURE);
	old_pwd = ft_strjoin("OLDPWD=", ft_environ("PWD", GET, 0));
	ft_environ(old_pwd, ADD, 0);
	if (update_pwd(fd) == EXIT_FAILURE || !old_pwd)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static char	*get_path(int argc, char *dir, int fd)
{
	char	*path;

	path = NULL;
	if (argc == 1 || (dir && ft_strncmp(dir, "~", 2) == 0))
	{
		path = ft_environ("HOME", GET, 0);
		if (path == NULL)
			ft_putendl_fd("Home not set", fd);
	}
	else if (dir && ft_strncmp(dir, "-", 2) == 0)
	{
		path = ft_environ("OLDPWD", GET, 0);
		if (path == NULL)
			ft_putendl_fd("OLDPWD not set", fd);
	}
	else
		path = dir;
	return (path);
}

int	cd_main(char **argv, int fd)
{
	char	*dir;
	int		argc;

	argc = get_arr_len(argv);
	dir = get_path(argc, argv[1], fd);
	if (dir == NULL)
		return (EXIT_FAILURE);
	if (chdir(dir) == 0)
	{
		if (argv[1] && ft_strncmp(argv[1], "-", 2) == 0)
			printf("%s\n", dir);
		if (update_oldpwd(fd) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		return (EXIT_SUCCESS);
	}
	ft_putendl_fd("cd: no such file or directory", fd);
	return (EXIT_FAILURE);
}
