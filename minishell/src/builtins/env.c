#include "minishell.h"

int	env_main()
{
	int	i;

	i = -1;
	while (environ[++i])
		printf("%s\n", environ[i]);
	return (EXIT_SUCCESS);
}
