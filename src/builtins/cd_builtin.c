#include "minishell.h"

int main(int argc, char **argv) //pasar como argumento PATH de env
{
    char    t_path[MAX_PATH];

    getcwd(t_path, MAX_PATH);
	if (strncmp(env.path, "-")) // si es cd -, moverse al OLDPWD
		return (cd_oldpwd(t_path, env));
    if (chdir(argv[1]) == 0)
	{
		update_oldpwd(t_path, argv[1]); // actualiza la variable OLDPWD del ENV
		update_pwd(env); // actualiza la variable PWD del ENV
		return (EXIT_SUCCESS);
	}
}