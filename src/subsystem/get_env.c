#include "minishell.h"

t_env_lst   *get_enviroment(const char **env, t_env_lst **head)
{
    t_env_lst   *next_env;
    char        *equal;
    char        *key;
    size_t      key_size;
    int         i;

    i = 0;
    while (env[i])
    {
        equal = ft_strrchr(env[i], '='); // Busca el '=' en cada linea de env
        key_size = ft_strlen(env[i]) - ft_strlen(equal); //tamaño de la string que precede al '='(key)
        key = ft_substr(env[i], 0, key_size); //genera el string key
        equal++;
        next_env = ft_envlstnew(key, equal); //genera el string value
        ft_envlstaddb(head, next_env);
        i++;
    }
    return (*head);
}



/*int main(int argc, char **argv, char **env)
{
    (void)argc;
    (void)argv;
    t_env_lst *p = get_enviroment(env, &p);
    ft_envlstiter(p, p_lst);
}*/