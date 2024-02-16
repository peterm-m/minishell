#include "minishell.h"

static int update_pwds(char **env)
{
    int i;
    char *new_opwd;
    char *new_pwd[MAX_PATH];

    new_opwd = ft_strjoin("OLDPWD=", get_env_value("PWD"));
    i = 0;
    while (env[i])
    {
        if (ft_strncmp("OLDPWD=", env[i], 8) == 0)
            env[i] = new_opwd;
        i++;
    }
    if (getcwd(new_pwd, MAX_PATH) == NULL)
	{
		printf("Error\n");
		return (EXIT_FAILURE);
	}
    i = 0;
    while (env[i])
    {
        if (ft_strncmp("PWD=", env[i], 4) == 0)
            env[i] = ft_strjoin("PWD=", new_pwd);
        i++;
    }
    return (EXIT_SUCCESS);
}

static char	*get_path(int argc, char *dir)
{
	char	*path;

	path = NULL;
	if (argc == 1)
	{
		path = get_env_value("HOME");
		if (path == NULL)
			printf("Error\n");
	}
	else if (dir && ft_strncmp(dir, "-", 2) == 0)
	{
		path = get_env_value("OLDPWD");
		if (path == NULL)
			printf("Error\n");
	}
	else
		path = dir;
	return (path);
}

int main(int argc, char **argv) //pasar como argumento PATH de env
{
	char	*dir;

	dir = get_path(argc, argv[1]);
	if (dir == NULL)
		return (EXIT_FAILURE);
    if (chdir(dir) == 0)
	{
        if (argv[1] && ft_strncmp(argv[1], "-", 2) == 0)
            printf("%s\n", dir);
        if (update_pwds(env) == EXIT_FAILURE) // actualiza las variables PWD y OLDPWD del ENV
            return (EXIT_FAILURE); 
		return (EXIT_SUCCESS);
	}
    return (EXIT_FAILURE);
}