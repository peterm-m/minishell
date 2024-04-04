/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:56:58 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/04 20:11:02 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTER_H
# define EXECUTER_H

# include "minishell.h"

# define STATUS_CMD_NOT_FOUND 127
# define STATUS_CMD_NOT_EXEC 126

# define NO_PIPE -1

# define LAST_IN_PIPE 1
# define IN_PIPE 2

typedef struct s_file_name
{
	char	file_name[NAME_MAX];
}	t_file_name;

typedef struct s_path_name
{
	char	path_name[PATH_MAX];
}	t_path_name;

void	ft_execle(t_word_list *args);
char	**list_to_arr(t_word_list *words);

int		execute_command(t_command *cmd, int fd_in, int fd_out);
void	execute_simple(t_command *cmd, int fd_in, int fd_out);
int		execute_builtin(t_word_list *words, int fd_out);
int		execute_connection(t_command *cmd, int fd_in, int fd_out);
void	execute_subshell(t_subshell *cmd, int fd_in, int fd_out);

int		is_builtin(char *str);

#endif