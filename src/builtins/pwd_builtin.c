#include "minishell.h"

/* int	ft_strncmp(char *s1, char *s2, size_t n)
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
}//TODO: BORRAR

char	*ft_strchr(const char *s, int c)
{
	char	aux;
	char	*str;
	int		i;

	aux = (char)c;
	str = (char *)s;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == aux)
			return (&str[i]);
		else
			i++;
	}
	if (aux == '\0')
		return (&str[i]);
	else
		return (0);
}//TODO: BORRAR */

int main(int argc, char **argv, char **env)
{
    int i;

    (void)argc;
    (void)argv;
    i = 0;
    printf(BHCYN"%s\n"END, getenv("PWD"));//MÉTODO 1

/*     while (env[i])                     //MÉTODO 2
    {
        if (ft_strncmp(env[i], "PWD", 3) == 0)
        {
            printf(BHCYN"%s\n"END, ft_strchr(env[i], '=') + 1);
            break;
        }
        i++;
    } */
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

//"USER=adiaz-uf" "MallocNanoZone=0" "PATH=/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/munki" "LOGNAME=adiaz-uf" "SSH_AUTH_SOCK=/private/tmp/com.apple.launchd.UzETPWzoJT/Listeners" "PWD=/Users/adiaz-uf/42cursus/minishell" "OLDPWD=/Users/adiaz-uf/42cursus/minishell" "ZSH=/Users/adiaz-uf/.oh-my-zsh"
