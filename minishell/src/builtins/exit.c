#include "minishell.h"

int is_number(char *num)
{
    int i;

    i = 0;
    while(num[i])
    {
        if (!ft_isdigit(num[i]))
            return (FALSE);
        i++;
    }
    return (TRUE);
}

static void	exit_no_numeric(char *cmd)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd("exit: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": numeric argument required\n", 2);
	exit (255);
}


int main (int argc, char **argv, char **env)
{
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
        exit(ft_atoi(argv[1]));
    }
}