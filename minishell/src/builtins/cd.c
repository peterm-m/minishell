/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:09:57 by adiaz-uf          #+#    #+#             */
/*   Updated: 2024/03/12 20:09:40 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/wrappers/wrappers.h"
#include "../../lib/libft/libft.h"
#include <limits.h>

static int update_pwd()
{
    int     i;
    char    new_pwd[PATH_MAX];

    if (getcwd(new_pwd, PATH_MAX) == NULL)
	{
        printf("Error\n");
		return (EXIT_FAILURE);
	}
    i = 0;
    setenv("PWD", new_pwd, 1);
    printf("PWD en update_pwd con getcwd: %s\n", new_pwd);   //sobra
    return (EXIT_SUCCESS);
}

static int update_oldpwd()
{
    int i;

    i = 0;
    setenv("OLDPWD", getenv("PWD"), 1);
    printf("OLDPWD en update_opwd: %s\n", getenv("OLDPWD"));    //sobra
    if (update_pwd() == EXIT_FAILURE)
        return (EXIT_FAILURE); 
    return (EXIT_SUCCESS);
}

static char	*get_path(int argc, char *dir)
{
	char	*path;

	path = NULL;
	if (argc == 1)
	{
		path = getenv("HOME");
		if (path == NULL)
			printf("Home not set\n");
	}
	else if (dir && ft_strncmp(dir, "-", 2) == 0)
	{
		path = getenv("OLDPWD");
		if (path == NULL)
			printf("OLDPWD not set\n");
	}
	else
		path = dir;          
	return (path);
}

int main(int argc, char **argv, char **env) //pasar como argumento PATH de env
{
	char	*dir;

    (void)env;
	dir = get_path(argc, argv[1]);
	if (dir == NULL)
		return (EXIT_FAILURE);
    if (chdir(dir) == 0)
	{
        if (argv[1] && ft_strncmp(argv[1], "-", 2) == 0)
            printf("%s\n", dir);
        if (update_oldpwd() == EXIT_FAILURE) // actualiza las variables PWD y OLDPWD del ENV
            return (EXIT_FAILURE); 
		return (EXIT_SUCCESS);
	}
    printf("cd: no such file or directory\n");
    return (EXIT_FAILURE);
}