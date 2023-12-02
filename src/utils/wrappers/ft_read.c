/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:18:30 by pedromar          #+#    #+#             */
/*   Updated: 2023/12/02 16:18:58 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrappers.h"

ssize_t	ft_read(int fd, void *buf, size_t count)
{
	ssize_t	rc;

	rc = read(fd, buf, count);
	if (rc < 0)
		unix_error("Read error");
	return (rc);
}
