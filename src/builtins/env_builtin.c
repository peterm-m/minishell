#include "minishell.h"

int main(int argc, char **argv)
{
    int i;

    
    (void)argc;
    i = 0;
    while (argv[++i])
        printf("%s\n", argv[i]);
    return (EXIT_SUCCESS);
}