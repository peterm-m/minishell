#include "minishell.h"

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
