/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:24:29 by pedromar          #+#    #+#             */
/*   Updated: 2024/03/15 20:04:20 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrappers.h"

void	ft_execve(const char *filename, char *const argv[], char *const envp[])
{
	if (execve(filename, argv, envp) < 0)
		unix_error("Execve error");
}
