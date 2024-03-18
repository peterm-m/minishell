#include "minishell.h"

int	env_main(char **env)
{
	int	i;

	i = -1;
	while (env[++i])
		printf("%s\n", env[i]);
	return (EXIT_SUCCESS);
}
