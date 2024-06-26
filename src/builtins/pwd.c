/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 19:50:17 by adiaz-uf          #+#    #+#             */
/*   Updated: 2024/04/11 19:33:56 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pwd_main(int fd)
{
	char pwd[PATH_MAX];

	if (getcwd(pwd, PATH_MAX) == NULL)
	{
		ft_putendl_fd("pwd: Error\n", fd);
		return (EXIT_FAILURE);
	}
	ft_putendl_fd(pwd, fd);
	return (EXIT_SUCCESS);
}
