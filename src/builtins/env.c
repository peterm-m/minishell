/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 19:50:20 by adiaz-uf          #+#    #+#             */
/*   Updated: 2024/04/14 16:59:09 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_main(char **argv, int fd)
{
	int	i;

	(void)argv;
	i = -1;
	while (environ[++i])
		ft_putendl_fd(environ[i], fd);
	return (EXIT_SUCCESS);
}
