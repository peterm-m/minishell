/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:56:58 by pedromar          #+#    #+#             */
/*   Updated: 2024/03/11 16:02:21 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTER_H
# define EXECUTER_H

# include "minishell.h"
# include <limits.h>

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
} t_process;

typedef struct s_mjob
{
	struct t_mjob	*next;
	char			*command;
	t_process		*first_process;
	pid_t			pgid;
	char			notified;
	struct termios	tmode;
	int				stdin;
	int				stdout;
	int				stderr;
} t_mjob;


void	executer(t_simple *cmd);
//void	expander(t_data *data, char *input);

#endif