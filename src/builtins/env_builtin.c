#include "minishell.h"

int main(int argc, char **argv, char **env) //Pasar como argumentos lista de ENV 
{
    int i;

    (void)argc;
    (void)argv;
    i = -1;
    while (env[++i])
        printf("%s\n", env[i]);
    return (EXIT_SUCCESS);
}