#include "minishell.h"
static int update_pwd(char **env)
{
    int i;
    char *new_pwd;

    if (getcwd(new_pwd, MAX_PATH) == NULL)
	{
		printf("Error\n");
		return (EXIT_FAILURE);
	}
    i = 0;
    setenv("PWD", new_pwd, TRUE);
    printf("PWD en update_opwd: %s\n", new_pwd);
    //free(new_pwd);
/*     while (env[i])
    {
        if (ft_strncmp("PWD=", env[i], 4) == 0)
        {
            //free(env[i]);
            env[i] = ft_strjoin("PWD=", new_pwd);
        }
        i++;
    } */
    return (EXIT_SUCCESS);
}

static int update_oldpwd(char **env)
{
    int i;
    char *new_opwd;

    new_opwd = getenv("PWD");//get_env
    i = 0;
    printf("OLDPWD en update_opwd: %s\n", new_opwd);
    setenv("OLDPWD", new_opwd, TRUE);
/*     while (env[i])
    {
        if (ft_strncmp("OLDPWD=", env[i], 8) == 0)
        {
            //free(env[i]);
            env[i] = new_opwd;
        }
        i++;
    } */
    printf("OLDPWD en update_opwd: %s\n", new_opwd);
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
        printf("OLDPWD en get_Path: %s\n", path);
        char *path2 = getenv("PWD");
        printf("PWD en get_Path: %s\n", path2);
		if (path == NULL)
			printf("Error\n");
	}
	else
    {
		path = dir;
        printf("dir get_Path: %s\n", path);
    }
	return (path);
}

int main(int argc, char **argv, char **env) //pasar como argumento PATH de env
{
	char	*dir;

	dir = get_path(argc, argv[1],env);
	if (dir == NULL)
		return (EXIT_FAILURE);
    printf("chdir = %d\n", chdir(dir));
    if (chdir(dir) == 0)
	{
        if (argv[1] && ft_strncmp(argv[1], "-", 2) == 0)
            printf("%s\n", dir);
        if (update_oldpwd(env) == EXIT_FAILURE) // actualiza las variables PWD y OLDPWD del ENV
            return (EXIT_FAILURE); 
		return (EXIT_SUCCESS);
	}
    return (EXIT_FAILURE);
}