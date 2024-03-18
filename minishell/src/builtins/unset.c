#include "minishell.h"

int unset_main(char **argv)
{
	char    *name;
	int     i;
	int		argc;

	argc = get_arr_len(argv);
	if (argc == 1)
	{
		printf("unset: not enough arguments\n");
		return(EXIT_SUCCESS);
	}
	if (ft_strncmp(argv[1], "_", 2) == 0)
		return (EXIT_SUCCESS);
	i = 0;
	while (argv[1][i] && argv[1][i] != '=')
		i++;
	name = ft_substr(argv[1], 0, i);
	if (!name)
		return (EXIT_SUCCESS);
	if (ft_unsetenv(name) == -1)
	{
		free(name);
		return (EXIT_FAILURE);
	}
	free(name);
	return(EXIT_SUCCESS);
}
