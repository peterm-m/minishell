/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 19:50:17 by adiaz-uf          #+#    #+#             */
/*   Updated: 2024/04/14 17:00:34 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pwd_main(char **argv, int fd)
{
	char	pwd[PATH_MAX];

	(void)argv;
	if (getcwd(pwd, PATH_MAX) == NULL)
	{
		ft_putendl_fd("pwd: Error\n", fd);
		return (EXIT_FAILURE);
	}
	ft_putendl_fd(pwd, fd);
	return (EXIT_SUCCESS);
}
