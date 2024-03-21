/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:56:58 by pedromar          #+#    #+#             */
/*   Updated: 2024/03/20 20:57:20 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTER_H
# define EXECUTER_H

# include "minishell.h"

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

void	execute_simple(t_simple *cmd);
int		execute_builtin(t_word_list *words);
int		execute_command(t_command *cmd);
int		execute_connection(t_connection *cmd);
int		execute_subshell(t_subshell *cmd);

#endif