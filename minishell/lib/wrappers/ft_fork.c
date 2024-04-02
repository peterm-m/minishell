/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:30:59 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/02 19:27:04 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrappers.h"

pid_t	ft_fork(void)
{
	char	*shlvl_value;
	int		shlvl;
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		unix_error("Fork error");
	if (pid == 0)
	{
		shlvl = 1;
		shlvl_value = ft_getenv("SHLVL");
		if (shlvl_value != NULL)
			shlvl = ft_atoi(shlvl_value) + 1;
		shlvl_value = ft_itoa(shlvl);
		ft_setenv("SHLVL", shlvl_value, 1);
		free(shlvl_value);
	}
	return (pid);
}
