#include "minishell.h"

void    sort_env(char **env)
{
    int i;
    int j;
    int env_len;
    char *aux;

    i = 0;
    env_len = get_env_len;
    while (i < env_len)
    {
        j = 0;
        while (j < env_len - 1)
        {
            if (ft_strcmp(env[j], env[j + 1]) > 0)
            {
                aux  = env[j];
                env[j] = env[j + 1];
                env[j + 1] = aux;
            }
            i++;
        }
        env_len--;
    }
}

void    print_sorted_env(char **env)
{
    int i;

    sort_env(env);
    i = -1;
    while (env[++i])
        printf ("declare -x %s\n", env[i])
}

int main(int argc, char **argv, char **env)
{
    if (argc == 1)
    {
        print_sorted_env(env);
        return(EXIT_SUCCESS);
    }
    
}