/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:24:29 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/19 14:59:51 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrappers.h"

void	ft_execve(const char *filename, char *const argv[], char *const envp[])
{
	if (execve(filename, argv, envp) < 0)
		unix_error("execve error");
}
