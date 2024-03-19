/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:09:57 by adiaz-uf          #+#    #+#             */
/*   Updated: 2024/03/19 19:28:21 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	update_pwd(void)
{
	char	pwd[PATH_MAX];
	char	*new_pwd;

	if (getcwd(pwd, PATH_MAX) == NULL)
	{
		printf("Error\n");
		return (EXIT_FAILURE);
	}
	new_pwd = ft_strjoin("PWD=", getcwd(pwd, PATH_MAX));
	ft_putenv(new_pwd);
	return (EXIT_SUCCESS);
}

static int update_oldpwd()
{
	int		i;
	char	*old_pwd;

	i = 0;
	if (ft_getenv("PWD") == NULL)
		return (EXIT_FAILURE);
	old_pwd = ft_strjoin("OLDPWD=", ft_getenv("PWD"));
	ft_putenv(old_pwd);
	if (update_pwd() == EXIT_FAILURE || !old_pwd)
		return (EXIT_FAILURE); 
	return (EXIT_SUCCESS);
}

static char	*get_path(int argc, char *dir)
{
	char	*path;

	path = NULL;
	if (argc == 1)
	{
		path = ft_getenv("HOME");
		if (path == NULL)
			printf("Home not set\n");
	}
	else if (dir && ft_strncmp(dir, "~", 2) == 0)
	{
		path = ft_getenv("HOME");
		if (path == NULL)
			printf("HOME not set\n");
	}
	else if (dir && ft_strncmp(dir, "-", 2) == 0)
	{
		path = ft_getenv("OLDPWD");
		if (path == NULL)
			printf("OLDPWD not set\n");
	}
	else
		path = dir;
	return (path);
}

int cd_main(char **argv)
{
	char	*dir;
	int		argc;
	
	argc = get_arr_len(argv);
	dir = get_path(argc, argv[1]);
	if (dir == NULL)
		return (EXIT_FAILURE);
	if (chdir(dir) == 0)
	{
		if (argv[1] && ft_strncmp(argv[1], "-", 2) == 0)
			printf("%s\n", dir);
		if (update_oldpwd() == EXIT_FAILURE)
			return (EXIT_FAILURE); 
		return (EXIT_SUCCESS);
	}
	printf("cd: no such file or directory\n");
	return (EXIT_FAILURE);
}
