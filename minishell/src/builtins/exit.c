#include "minishell.h"

/* int	exit_number(char *num)
{
	int number;

	number = ft_atoi(num);
	return (number % 256);
} */

int is_number(char *num)
{
	int i;

	i = 0;
	while(num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	exit_no_numeric(char *cmd)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd("exit: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": numeric argument required\n", 2);
	exit (255);
}


int exit_main(char **argv)
{
	int	argc;

	argc = get_arr_len(argv);
	if (argc == 1)
	{
		ft_putstr_fd("exit\n", 2);
		exit(EXIT_SUCCESS);
	}
	if (argc >= 2)
	{
		if (is_number(argv[1]) && argc >= 3)
		{
			ft_putstr_fd("minishell: exit: too many arguments\n", 2);
			return(EXIT_SUCCESS);
		}
		if (!is_number(argv[1]))
			exit_no_numeric(argv[1]);
		ft_putstr_fd("exit\n", 2);
		exit(ft_atoi(argv[1]) % 256);
	}
	return (EXIT_FAILURE);
}