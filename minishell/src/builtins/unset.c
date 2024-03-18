#include "minishell.h"

int unset_main(char **argv)
{
	int		argc;
	int		i;

	argc = get_arr_len(argv);
	if (argc == 1)
	{
		printf("unset: not enough arguments\n");
		return(EXIT_SUCCESS);
	}
	if (ft_strncmp(argv[1], "_", 2) == 0)
		return (EXIT_SUCCESS);
	i = 1;
	while (argv[i])
	{
		if (ft_getenv(argv[i]) != NULL)
			ft_unsetenv(argv[i]);
		i++;
	}
	return (EXIT_SUCCESS);
}
