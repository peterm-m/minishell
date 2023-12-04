/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_kill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:29:40 by pedromar          #+#    #+#             */
/*   Updated: 2023/12/02 16:30:43 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrappers.h"

void	ft_kill(pid_t pid, int signum)
{
	int	rc;

	rc = kill(pid, signum);
	if (rc < 0)
		unix_error("Kill error");
}
