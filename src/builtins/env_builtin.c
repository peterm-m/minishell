#include "minishell.h"

int main(int argc, char **argv) //Pasar como argumentos lista de ENV 
{
    int i;

    
    (void)argc;
    i = 0;
    while (argv[++i])
        printf("%s\n", argv[i]);
    return (EXIT_SUCCESS);
}