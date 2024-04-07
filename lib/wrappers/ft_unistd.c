/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unistd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:07:17 by pedromar          #+#    #+#             */
/*   Updated: 2023/12/02 16:15:11 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrappers.h"

int	ft_open(const char *pathname, int flags, mode_t mode)
{
	int	rc;

	rc = open(pathname, flags, mode);
	if (rc < 0)
		unix_error("Open error");
	return (rc);
}

ssize_t	ft_read(int fd, void *buf, size_t count)
{
	ssize_t	rc;

	rc = read(fd, buf, count);
	if (rc < 0)
		unix_error("Read error");
	return (rc);
}

ssize_t	ft_write(int fd, const void *buf, size_t count)
{
	ssize_t	rc;

	rc = write(fd, buf, count);
	if (rc < 0)
		unix_error("Write error");
	return (rc);
}

void	ft_close(int fd)
{
	int	rc;

	rc = close(fd);
	if (rc < 0)
		unix_error("Close error");
}
