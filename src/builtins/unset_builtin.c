#include "minishell.h"

int get_env_len(char **env)
{
    int i;

    i = 0;
    while (env[i])
        i++;
    return (i);
}

void    sort_env(char **env)
{
    int i;
    int j;
    int env_len;
    char *aux;

    env_len = get_env_len(env);
    i = 0;
    while (i < env_len - 1)
    {
        j = i + 1;
        while (j < env_len)
        {
            if (strcmp(env[i], env[j]) > 0)
            {
                aux  = env[i];
                env[i] = env[j];
                env[j] = aux;
            }
            j++;
        }
        i++;
    }
}

void    print_sorted_env(char **env)
{
    int i;

    sort_env(env);
    i = -1;
    while (env[++i])
        printf ("declare -x %s\n", env[i]);
}
int main(int argc, char **argv, char **env)
{
    char    *name;
    int     i;

    if (argc == 1)
    {
        printf("unset: not enough arguments\n");
        return(EXIT_SUCCESS);
    }
    if (ft_strncmp(argv[1], "_", 2) == 0)
        return (EXIT_SUCCESS);
    i = 0;
    while (argv[1][i] && argv[1][i] != '=')
        i++;
    name = ft_substr(argv[1], 0, i);
    if (!name)
        return (EXIT_SUCCESS);
    if (unsetenv(name) == -1)//TODO: FT_unsetenv
    {
        free(name);
        return (EXIT_FAILURE);
    }
    free(name);    
    return(EXIT_SUCCESS);
}
