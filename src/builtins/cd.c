/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:09:57 by adiaz-uf          #+#    #+#             */
/*   Updated: 2024/04/11 20:52:28 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	update_pwd(int fd)
{
	char	*last_pwd;
	char	pwd[PATH_MAX];
	char	new_pwd[PATH_MAX];

	if (getcwd(pwd, PATH_MAX) == NULL)
	{
		ft_putendl_fd("Error\n", fd);
		return (EXIT_FAILURE);
	}
	ft_strlcpy(new_pwd, "PWD=", PATH_MAX);
	ft_strlcat(new_pwd, getcwd(pwd, PATH_MAX), PATH_MAX);
	last_pwd = ft_getvar("PWD");
	ft_free(last_pwd);
	ft_putenv(ft_strdup(new_pwd));
	return (EXIT_SUCCESS);
}

static int	update_oldpwd(int fd)
{
	char	*last_old_pwd;
	char	*old_pwd;

	if (ft_getenv("PWD") == NULL)
		return (EXIT_FAILURE);
	old_pwd = ft_strjoin("OLDPWD=", ft_getenv("PWD"));
	last_old_pwd = ft_getvar("OLDPWD");
	ft_free(last_old_pwd);
	ft_putenv(old_pwd);
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
		path = ft_getenv("HOME");
		if (path == NULL)
			ft_putendl_fd("Home not set\n", fd);
	}
	else if (dir && ft_strncmp(dir, "-", 2) == 0)
	{
		path = ft_getenv("OLDPWD");
		if (path == NULL)
			ft_putendl_fd("OLDPWD not set\n", fd);
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
	ft_putendl_fd("cd: no such file or directory\n", fd);
	return (EXIT_FAILURE);
}
