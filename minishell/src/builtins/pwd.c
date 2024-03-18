#include "minishell.h"

int	pwd_main()
{
	printf("%s\n", ft_getenv("PWD"));
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