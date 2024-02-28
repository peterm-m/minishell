#include "minishell.h"
static int update_pwd(char **env)
{
    int i;
    char *new_pwd;

    i = 0;
    if (getcwd(new_pwd, MAX_PATH) == NULL)
	{
		printf("Error\n");
		return (EXIT_FAILURE);
	}
    i = 0;
    ft_setenv("PWD", new_pwd, TRUE);
    while (env[i])
    {
        if (ft_strncmp("PWD=", env[i], 4) == 0)
        {
            //free(env[i]);
            env[i] = ft_strjoin("PWD=", new_pwd);
        }
        i++;
    }
    return (EXIT_SUCCESS);
}

static int update_oldpwd(char **env)
{
    int i;
    char *new_opwd;

    new_opwd = getenv("PWD");//get_env
    i = 0;

    ft_setenv("OLDPWD", new_opwd, TRUE);
/*     while (env[i])
    {
        if (ft_strncmp("OLDPWD=", env[i], 8) == 0)
        {
            //free(env[i]);
            env[i] = new_opwd;
        }
        i++;
    } */
    if (update_pwd(env) == EXIT_FAILURE)
        return (EXIT_FAILURE); 
    return (EXIT_SUCCESS);
}

static char	*get_path(int argc, char *dir, char **env)
{
	char	*path;

	path = NULL;
	if (argc == 1)
	{
		path = getenv("HOME");
		if (path == NULL)
			printf("Error\n");
	}
	else if (dir && ft_strncmp(dir, "-", 2) == 0)
	{
		path = getenv("OLDPWD");
		if (path == NULL)
			printf("Error\n");
	}
	else
		path = dir;
	return (path);
}

int main(int argc, char **argv, char **env) //pasar como argumento PATH de env
{
	char	*dir;

	dir = get_path(argc, argv[1],env);
	if (dir == NULL)
		return (EXIT_FAILURE);
    if (chdir(dir) == 0)
	{
        if (argv[1] && ft_strncmp(argv[1], "-", 2) == 0)
            printf("%s\n", dir);
        if (update_oldpwd(&argv[2]) == EXIT_FAILURE) // actualiza las variables PWD y OLDPWD del ENV
            return (EXIT_FAILURE); 
		return (EXIT_SUCCESS);
	}
    return (EXIT_FAILURE);
}