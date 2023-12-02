/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wait.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:26:29 by pedromar          #+#    #+#             */
/*   Updated: 2023/12/02 16:27:29 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrappers.h"

pid_t	ft_wait(int *status)
{
	pid_t	pid;

	pid = wait(status);
	if (pid < 0)
		unix_error("Wait error");
	return (pid);
}
