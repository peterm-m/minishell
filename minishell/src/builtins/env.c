#include "minishell.h"

int bin_env(int argc, char **argv, char **env)
{
    int i;
  
    (void)argc;
    (void)argv;
    i = -1;
    while (env[++i])
        printf("%s\n", env[i]);
    return (EXIT_SUCCESS);
}