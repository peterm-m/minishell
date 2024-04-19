/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:56:58 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/19 17:07:30 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTER_H
# define EXECUTER_H

# include "minishell.h"

# define STATUS_CMD_NOT_FOUND 127
# define STATUS_CMD_NOT_EXEC 126

# define PID_BUILTIN -1

typedef struct s_pipe
{
	int	len_pipe;
	int	*fds;
}	t_pipe;

typedef struct s_file_name
{
	char	file_name[NAME_MAX];
}	t_file_name;

typedef struct s_path_name
{
	char	path_name[PATH_MAX];
}	t_path_name;

void	ft_execle(t_word *args);

void	wait_pipe(pid_t pid, t_pipe *p);
void	wait_command(pid_t pid);

int		execute(t_command *cmd);
int		execute_builtin(t_command *cmd, t_pipe *p, int index_cmd);
void	execute_simple(t_command *cmd, t_pipe *p, int index_cmd);
void	execute_subshell(t_command *cmd, t_pipe *p, int index_cmd);

void	open_redir(t_redir *redirections);

void	connect_pipe(t_pipe *pipe, int index_cmd);
void	close_pipe(t_pipe *pipe);
int		len_pipe(t_command *cmd);
int		make_pipe(t_pipe **p, int num_pipes);

#endif