/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrappers.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:50:50 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/19 13:15:42 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRAPPERS_H
# define WRAPPERS_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <signal.h>
# include <errno.h>

# include "libft.h"

extern char	**environ;

void		*ft_malloc(size_t size);
void		ft_free(void *ptr);

typedef void \
			t_handler(int);


void		unix_error(char *msg);

int			ft_open(const char *pathname, int flags, mode_t mode);
void		ft_execve(const char *filename, char *const argv[],
				char *const envp[]);
pid_t		ft_waitpid(pid_t pid, int *iptr, int options);
pid_t		ft_fork(void);
t_handler	*ft_signal(int signum, t_handler *handler);
void		ft_sigemptyset(sigset_t *set);
void		ft_sigaddset(sigset_t *set, int signum);
int			ft_dup2(int fd1, int fd2);

#endif
