/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 19:50:20 by adiaz-uf          #+#    #+#             */
/*   Updated: 2024/04/05 19:54:05 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_main(int fd)
{
	int	i;

	i = -1;
	while (environ[++i])
		ft_putendl_fd(environ[i], fd);
	return (EXIT_SUCCESS);
}
