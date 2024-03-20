/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:07:17 by pedromar          #+#    #+#             */
/*   Updated: 2024/03/20 19:32:26 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrappers.h"

void	ft_close(int fd)
{
	int	rc;
	printf("LOG %d\n", fd);
	rc = close(fd);
	if (rc < 0)
		unix_error("Close error");
}
