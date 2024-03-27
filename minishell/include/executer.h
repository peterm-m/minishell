/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:56:58 by pedromar          #+#    #+#             */
/*   Updated: 2024/03/27 16:29:06 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTER_H
# define EXECUTER_H

# include "minishell.h"

# define STATUS_CMD_NOT_FOUND 127
# define STATUS_CMD_NOT_EXEC 126

# define NO_PIPE -1

# define LAST_IN_PIPE 1
# define IGNORE_STATUS 2

typedef struct s_file_name
{
	char	file_name[NAME_MAX];
}	t_file_name;

typedef struct s_path_name
{
	char	path_name[PATH_MAX];
}	t_path_name;

typedef struct s_process
{
	struct s_process	*next;
	char				**argv;
	pid_t				pid;
	char				completed;
	char				stopped;
	int					status;
}	t_process;

typedef struct s_mjob
{
	struct s_mjob	*next;
	char			*command;
	t_process		*first_process;
	pid_t			pgid;
	char			notified;
	struct termios	tmode;
	int				stdin;
	int				stdout;
	int				stderr;
}	t_mjob;

void	ft_execle(t_word_list *args);
char	**list_to_arr(t_word_list *words);

void	execute_simple(t_command *cmd, int fd_in, int fd_out);
int		execute_builtin(t_word_list *words);
int		execute_command(t_command *cmd, int fd_in, int fd_out);
int		execute_pipe(t_command *cmd, int fd_in, int fd_out);
int		execute_connection(t_command *cmd, int fd_in, int fd_out);
void	execute_subshell(t_subshell *cmd, int fd_in, int fd_out);

#endif