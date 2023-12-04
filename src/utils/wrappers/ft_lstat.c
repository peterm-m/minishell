/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 19:27:17 by pedromar          #+#    #+#             */
/*   Updated: 2023/12/03 20:14:32 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_wrappers.h"

void	ft_lstat(const char *filename, struct stat *buf)
{
	if (lstat(filename, buf) < 0)
		unix_error("Stat error");
}

/*
	The fstat() obtains the same information about
	except in the case where the named file is a symbolic link;
	lstat() returns information about the link
 	while stat() returns information about the file the link references
	an open file known by the file descriptor fildes.
	SEE: stat()
*/