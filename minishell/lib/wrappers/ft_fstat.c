/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fstat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:25:13 by pedromar          #+#    #+#             */
/*   Updated: 2023/12/03 20:14:38 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrappers.h"

void	ft_fstat(int fd, struct stat *buf)
{
	if (fstat(fd, buf) < 0)
		unix_error("Fstat error");
}

/*
	The fstat() obtains the same information about
	an open file known by the file descriptor fildes.
	SEE: stat()
*/