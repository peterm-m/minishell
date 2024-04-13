/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:08:32 by adiaz-uf          #+#    #+#             */
/*   Updated: 2024/04/13 14:33:10 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exit_not_identifier(char *cmd)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd("export: '", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd("' not a valid identifier\n", 2);
	return (EXIT_FAILURE);
}

void	print_sorted_env(int fd)
{
	int	i;

	sort_env();
	i = -1;
	while (environ[++i])
		ft_putendl_fd(environ[i], fd);
}

int	export_args(char **argv)
{
	int		i;
	int		j;
	int		valid;
	char	new_var[PATH_MAX];

	j = 1;
	while (argv[j])
	{
		i = 0;
		valid = 0;
		while (argv[j][i])
		{
			if (ft_isdigit(argv[j][0]))
				return (exit_not_identifier(argv[j]));
			if (argv[j][i] == '=' && valid == 0)
			{
				ft_strlcpy(new_var, argv[j], PATH_MAX);
				ft_putenv(ft_strdup(new_var)); //TODO cambiado a memoria dinámica
				valid = 1;
			}
			i++;
		}
		j++;
	}
	return (EXIT_SUCCESS);
}

int	export_main(char **argv, int fd)
{
	int	argc;

	argc = get_arr_len(argv);
	if (argc == 1)
	{
		print_sorted_env(fd);
		return (EXIT_SUCCESS);
	}
	return (export_args(argv));
}
