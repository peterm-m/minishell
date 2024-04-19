/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:30:59 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/19 15:27:00 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrappers.h"

pid_t	minish_fork(void)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		minish_error("fork error");
	return (pid);
}
