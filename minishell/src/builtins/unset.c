#include "minishell.h"

int unset_main(char **argv)
{
	int		argc;
	int		i;

	argc = get_arr_len(argv);
	if (argc == 1)
	{
		ft_putendl_fd("unset: not enough arguments", 2);
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
