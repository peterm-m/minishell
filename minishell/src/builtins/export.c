/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:08:32 by adiaz-uf          #+#    #+#             */
/*   Updated: 2024/03/20 19:40:50 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_not_identifier(char *cmd)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd("export: ", 2);
	ft_putstr_fd("not an identifier\n", 2);
	ft_putstr_fd(cmd, 2);
}

void    print_sorted_env()
{
	int i;

	sort_env();
	i = -1;
	while (environ[++i])
		printf ("declare -x %s\n", environ[i]);
}

int export_args(char **argv)
{
	int     i;
	int		j;
	int		valid;

	j = 1;
	while (argv[j])
	{
		i = 0;
		valid = 0;
		while (argv[j][i])
		{
			if (argv[j][i] == '=' && valid == 0)
			{
				if (ft_isdigit(argv[j][0] == 1))
					exit_not_identifier(argv[j]);
				else
					ft_putenv(argv[j]);		
				valid = 1;
			}
			i++;	
		}
		j++;
	}
	return (EXIT_SUCCESS);
}
int export_main(char **argv)
{
	int     argc;

	argc = get_arr_len(argv);
	if (argc == 1)
	{
		print_sorted_env();
		return(EXIT_SUCCESS);
	}
	return(export_args(argv));
}
