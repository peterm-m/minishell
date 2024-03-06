#include "minishell.h"
char    *get_env_value(char *str, char **env) // BORRAR! repetida para probar por separado
{
    int      i;

    i = 0;
    while (env[i])
    {
        if (ft_strncmp(str, env[i], ft_strlen(str)) == 0)
            return (ft_strchr(env[i], '=') + 1);
        i++;
    }
    return (NULL);
}
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

    new_opwd = ft_strjoin("OLDPWD=", get_env_value("PWD", env));
    i = 0;
    while (env[i])
    {
        if (ft_strncmp("OLDPWD=", env[i], 8) == 0)
        {
            //free(env[i]);
            env[i] = new_opwd;
        }
        i++;
    }
    if (update_oldpwd(env) == EXIT_FAILURE)
        return (EXIT_FAILURE); 
    return (EXIT_SUCCESS);
}

static char	*get_path(int argc, char *dir, char **env)
{
	char	*path;

	path = NULL;
	if (argc == 1)
	{
		path = get_env_value("HOME", env);
		if (path == NULL)
			printf("Error\n");
	}
	else if (dir && ft_strncmp(dir, "-", 2) == 0)
	{
		path = get_env_value("OLDPWD", env);
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
    char    *new_pwd;
    char    *old_pwd;
    char    *path;
    int     fd;

	dir = get_path(argc, argv[1], env);
	if (dir == NULL)
		return (EXIT_FAILURE);
    path = getenv("BASEDIR");
    old_pwd = getcwd(NULL, 0);
    if (chdir(dir) == -1)
        return (EXIT_FAILURE);
	new_pwd = getcwd(NULL, 0);
	path = ft_strjoin(path, "/.dir");
    fd = open(path, O_CREAT | O_RDWR | O_TRUNC, 0664);
    path = getenv("BASEDIR");
    write(fd, new_pwd, ft_strlen(new_pwd));
    close(fd);
    //free(path); ??
    if (argv[1] && ft_strncmp(argv[1], "-", 2) == 0)
            printf("%s\n", dir);
    if (update_oldpwd(env) == EXIT_FAILURE) // actualiza las variables PWD y OLDPWD del ENV
        return (EXIT_FAILURE); 
    return (EXIT_FAILURE);
}