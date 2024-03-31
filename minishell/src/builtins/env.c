#include "minishell.h"

int	env_main(int fd)
{
	int	i;

	i = -1;
	while (environ[++i])
		ft_putendl_fd(environ[i], fd); //printf("%s\n", environ[i]);
	return (EXIT_SUCCESS);
}
