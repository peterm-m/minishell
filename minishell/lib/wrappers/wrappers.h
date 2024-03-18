/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrappers.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:50:50 by pedromar          #+#    #+#             */
/*   Updated: 2024/03/15 20:25:22 by adiaz-uf         ###   ########.fr       */
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

//# define DEBUG 1

// conditional
# ifdef DEBUG

typedef struct s_mem_info
{
	void				*ptr;
	const char			*filename;
	const char			*functionname;
	size_t				bytes;
	int					line;
	struct s_mem_info	*next;
	struct s_mem_info	*prev;
}	t_mem_info;

typedef struct s_reserve
{
	size_t		bytes;
	int			line;
	char		*file;
	const char	*func;
}	t_reserve;

void		*ft_malloc(t_reserve reserve);
void		ft_free(void *ptr);
void		ft_leaks(void);

# else

void		*ft_malloc(size_t size);
void		ft_free(void *ptr);

# endif

# ifndef LOGS
#  define LOGS 0
# endif

# define dbg(fmt,...) \
			do { if (LOGS) fprintf(stderr,  "%-60s:%-3d:%-30s" fmt, __FILE__,\
			__LINE__, __func__, __VA_ARGS__); } while (0)

typedef void	t_handler(int);

void		unix_error(char *msg);
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

char		*ft_getenv(const char *name);
int			ft_setenv(const char *name, const char *value, int overwrite);
int			ft_unsetenv(const char *name);
int			ft_putenv(char *string);
int			ft_clearenv(void);

#endif

/**
 * TODO: funciones que aun no tienen wrap
 * 
 *	ioctl
 *
 *	tcsetattr
 *	tcgetattr
 *	tgetent
 *	tgetflag
 *	tgetnum
 *	tgetstr
 *	tgoto
 *	tputs
 *
 *	wait3
 *	wait4
 *	exit
 *	dup
 *	printf
 *	pipe
 *
 *
 *	access
 *	chdir
 *	lstat
 *	unlink,
 *
 *	opendir
 *	readdir
 *	closedir
 *
 *	isatty
 *	ttyname
 *	ttyslot
 *
 * ? Deberian los errores notificarse de esta manera? 
**/
