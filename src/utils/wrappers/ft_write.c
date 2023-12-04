/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:19:30 by pedromar          #+#    #+#             */
/*   Updated: 2023/12/02 17:38:12 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrappers.h"

ssize_t	ft_write(int fd, const void *buf, size_t count)
{
	ssize_t	rc;

	rc = write(fd, buf, count);
	if (rc < 0)
		unix_error("Write error");
	return (rc);
}
