/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:52:05 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/19 15:28:22 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrappers.h"

int	minish_pipe(int pipefd[2])
{
	int	rc;

	rc = pipe(pipefd);
	if (rc < 0)
		minish_error("pipe error");
	return (rc);
}
