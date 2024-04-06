/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subsystem.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:56:58 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/06 17:15:12 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUBSYSTEM_H
# define SUBSYSTEM_H

# include "minishell.h"

# define PROMPT "minishell42"

int		search_character(char *str, char c);

int		get_pathname(char *name, t_path_name *path);

char	*get_prompt(void);
void	setup_term(void);

void	make_redir(t_redirect *redirections);
void	open_redir(t_redirect *redirections);

void	close_pipe(int fd_in, int fd_out);
void	make_pipe(int fd_in, int fd_out);

void	initial_signals(void);
void	wait_signals(void);
void	child_signals(void);
void	sigint_handler(int sig);

int		num_files_dir(char *name);
char	**get_file_names(char *name);

char	**list_to_arr(t_word_list *words);
void	clean_arr(char **arr);

void	heredoc(t_redirect *redir, char *delimiter);

#endif
