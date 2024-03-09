#include "minishell.h"
int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while ((unsigned char)*s1 == (unsigned char)*s2 \
		&& *s1 != '\0' && n - 1 > 0)
	{
		s1++;
		s2++;
		n--;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int main(int argc, char **argv)
{
    int i;

    (void)argc;
    (void)argv;
    i = 1;
    while (argv[i])
    {
        if (ft_strncmp(argv[i], "PWD", 3) == 0)
        {
            printf(BHCYN"%s\n"END, argv[i]);
            break;
        }
        i++;
    }
    return (EXIT_SUCCESS);
}
//SHLVL=1 PWD=/Users/adiaz-uf/42cursus/minishell OLDPWD=/Users/adiaz-uf

/*ORIGINAL_XDG_CURRENT_DESKTOP=undefined
SHLVL=1
PWD=/Users/adiaz-uf/42cursus/minishell
OLDPWD=/Users/adiaz-uf
ZSH=/Users/adiaz-uf/.oh-my-zsh
PAGER=less
LESS=-R */