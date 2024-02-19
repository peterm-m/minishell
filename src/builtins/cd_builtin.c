#include "minishell.h"
void update_pwd(char *p, t_data *data)
{

}
void update_oldpwd(char *p,  t_data *data)
{
    int i;
    char *new_opwd;

    new_opwd = ft_strjoin("OLDPWD=", p);
    i = 0;
    while (&data->envlist[i])
    {
        if (ft_strncmp("OLDPWD=", &data->envlist[i], 8) == 0)
        {
           &data->envlist. = new_opwd;
        }
    }
}

int cd_builtin(t_data *data, char *argv) //pasar como argumento PATH de env
{
    char    t_path[MAX_PATH];

    getcwd(t_path, MAX_PATH);
	if (ft_strncmp(argv, "-")) // si es cd -, moverse al OLDPWD
		return (cd_oldpwd(t_path, data));
    if (chdir(argv[1]) == 0)
	{
		update_oldpwd(t_path, argv[1]); // actualiza la variable OLDPWD del ENV
		update_pwd(env); // actualiza la variable PWD del ENV
		return (EXIT_SUCCESS);
	}
}