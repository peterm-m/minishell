/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrappers.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:50:50 by pedromar          #+#    #+#             */
/*   Updated: 2023/12/03 19:28:31 by pedromar         ###   ########.fr       */
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

typedef void	t_handler(int);

void		unix_error(char *msg);
void		*ft_malloc(size_t size);
void		ft_free(void *ptr);
int			ft_open(const char *pathname, int flags, mode_t mode);
ssize_t		ft_read(int fd, void *buf, size_t count);
ssize_t		ft_write(int fd, const void *buf, size_t count);
void		ft_close(int fd);
void		ft_stat(const char *filename, struct stat *buf);
void		ft_lstat(const char *filename, struct stat *buf);
void		ft_execve(const char *filename, char *const argv[],
				char *const envp[]);
void		ft_fstat(int fd, struct stat *buf);
pid_t		ft_wait(int *status);
pid_t		ft_waitpid(pid_t pid, int *iptr, int options);
void		ft_kill(pid_t pid, int signum);
pid_t		ft_fork(void);
t_handler	*ft_signal(int signum, t_handler *handler);
void		ft_sigemptyset(sigset_t *set);
void		ft_sigaddset(sigset_t *set, int signum);

#endif

/**
 * TODO: funciones que aun no tienen wrap
 *	ioctl
 *	getenv
 *	tcsetattr
 *	tcgetattr
 *	tgetent
 *	tgetflag
 *	tgetnum
 *	tgetstr
 *	tgoto
 *	tputs
 *	wait3
 *	wait4
 *	exit
 *	dup
 *	printf
 *	access
 *	getcwd
 *	chdir
 *	 lstat
 *	unlink,
 *	pipe
 *	opendir
 *	readdir
 *	closedir
 *	isatty
 *	ttyname
 *	ttyslot
 *
 * ? Deberian los errores notificarse de esta manera? 
**/