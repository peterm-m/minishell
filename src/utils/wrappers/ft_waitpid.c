/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_waitpid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:28:33 by pedromar          #+#    #+#             */
/*   Updated: 2023/12/02 16:29:22 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrappers.h"

pid_t	ft_waitpid(pid_t pid, int *iptr, int options)
{
	pid_t	retpid;

	retpid = waitpid(pid, iptr, options);
	if (retpid < 0)
		unix_error("Waitpid error");
	return (retpid);
}
