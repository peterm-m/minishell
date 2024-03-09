/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wait.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:26:29 by pedromar          #+#    #+#             */
/*   Updated: 2024/02/29 20:35:18 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrappers.h"

pid_t	ft_wait(int *status)
{
	pid_t	pid;

	pid = wait(status);
	if (pid < 0)
		unix_error("Wait error");
	return (pid);
}

/*
	The wait() function suspends execution of its calling process until
	stat_loc information is available for a terminated child process,
	or a signal is received.
	On return from a successful wait() call, the stat_loc area contains
	termination information about the process that exited as defined below.
*/

//pid_t	ft_wait3(int *stat_loc, int options, struct rusage *rusage)
//{
//	
//}

/*
	The older wait3() call is the same as wait4() with a pid value of -1.
*/

//pid_t	ft_wait4(pid_t pid, int *stat_loc, int options, struct rusage *rusage)
//{
//	
//}

/*
	The wait4() call provides a more general interface for programs that need
	to wait for certain child processes, that need resource utilization
	statistics accumulated by child processes, or that require options.
*/