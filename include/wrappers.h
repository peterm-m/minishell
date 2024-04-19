/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrappers.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:50:50 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/19 15:25:57 by pedromar         ###   ########.fr       */
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
int			minish_error(char *msg);

int			ft_open(const char *pathname, int flags, mode_t mode);
int			minish_open(const char *pathname, int flags, mode_t mode);

void		ft_execve(const char *filename, char *const argv[],
				char *const envp[]);
t_handler	*ft_signal(int signum, t_handler *handler);
int			ft_dup2(int fd1, int fd2);
pid_t		minish_fork(void);

int			minish_pipe(int pipefd[2]);

void		*ft_malloc(size_t size);
void		ft_free(void *ptr);

#endif
