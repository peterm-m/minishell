/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 19:50:20 by adiaz-uf          #+#    #+#             */
/*   Updated: 2024/04/16 18:07:01 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_main(char **argv, int fd)
{
	int	i;
	int j;
	int	is_local;

	(void)argv;
	i = -1;
	is_local = 0;
	while (environ[++i])
	{
		j = 0;
		while (environ[i][j])
		{
			if (environ[i][j] == '=')
			{
				ft_putendl_fd(environ[i], fd);
				break;
			}
			j++;
		}
	}
	return (EXIT_SUCCESS);
}
