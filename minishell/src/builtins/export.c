/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:08:32 by adiaz-uf          #+#    #+#             */
/*   Updated: 2024/03/18 19:04:52 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int get_arr_len(char **env)
{
	int i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}

void    sort_env()
{
	int i;
	int j;
	int env_len;
	char *aux;

	env_len = get_arr_len(environ);
	i = 0;
	while (i < env_len - 1)
	{
		j = i + 1;
		while (j < env_len)
		{
			if (strcmp(environ[i], environ[j]) > 0)
			{
				aux  = environ[i];
				environ[i] = environ[j];
				environ[j] = aux;
			}
			j++;
		}
		i++;
	}
}

void    print_sorted_env()
{
	int i;

	sort_env();
	i = -1;
	while (environ[++i])
		printf ("declare -x %s\n", environ[i]);
}

int export_main(char **argv)
{
	int		find;
	int     argc;
	int     i;
	int		j;

	argc = get_arr_len(argv);
	if (argc == 1)
	{
		print_sorted_env();
		return(EXIT_SUCCESS);
	}
	j = 0;
	find = 0;
	i = -1;
	while (argv[++j][i])
	{
		while (argv[j][++i])
		if (argv[1][i] == '=')
			ft_putenv(argv[j]);
	}
	ft_putenv(argv[1]);
	return(EXIT_SUCCESS);
}
