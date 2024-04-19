/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:18:01 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/19 15:26:41 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrappers.h"

int	ft_open(const char *pathname, int flags, mode_t mode)
{
	int	rc;

	rc = open(pathname, flags, mode);
	if (rc < 0)
		unix_error((char *)pathname);
	return (rc);
}

int	minish_open(const char *pathname, int flags, mode_t mode)
{
	int	rc;

	rc = open(pathname, flags, mode);
	if (rc < 0)
		minish_error((char *)pathname);
	return (rc);
}
