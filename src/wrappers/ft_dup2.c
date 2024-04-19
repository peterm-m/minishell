/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:22:17 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/19 14:26:59 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrappers.h"

int	ft_dup2(int fd1, int fd2)
{
	int	rc;

	rc = dup2(fd1, fd2);
	if (rc < 0)
		unix_error("dup2 error");
	return (rc);
}
