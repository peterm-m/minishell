/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 19:50:20 by adiaz-uf          #+#    #+#             */
/*   Updated: 2024/04/18 19:37:50 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_main(char **argv, int fd)
{
	int	i;
	int	j;

	(void)argv;
	i = 0;
	while (ft_environ("", INDEX, i) != NULL)
	{
		j = 0;
		while (ft_environ("", INDEX, i)[j])
		{
			if (ft_environ("", INDEX, i)[j] == '=')
			{
				ft_putendl_fd(ft_environ("", INDEX, i), fd);
				break ;
			}
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
