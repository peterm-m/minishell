#include "minishell.h"

void update_oldpwd(char *p,  char **env)
{
    int i;
    char *new_opwd;

    new_opwd = ft_strjoin("OLDPWD=", p);
    i = 0;
    while (env[i])
    {
        if (ft_strncmp("OLDPWD=", env[i], 8) == 0)
        {
            env[i] = 
        }
    }
}

int main(int argc, char **argv) //pasar como argumento PATH de env
{
    char    t_path[MAX_PATH];

    getcwd(t_path, MAX_PATH);
	if (ft_strncmp(env.path, "-")) // si es cd -, moverse al OLDPWD
		return (cd_oldpwd(t_path, env));
    if (chdir(argv[1]) == 0)
	{
		update_oldpwd(t_path, argv[1]); // actualiza la variable OLDPWD del ENV
		update_pwd(env); // actualiza la variable PWD del ENV
		return (EXIT_SUCCESS);
	}
}