/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subsystem.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:56:58 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/17 18:24:16 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUBSYSTEM_H
# define SUBSYSTEM_H

# include "minishell.h"

int		search_character(char *str, char c);

int		get_pathname(char *name, t_path_name *path);

char	*get_prompt(void);
void	setup_term(void);

void	make_redir(t_redir *redirections);
void	open_redir(t_redir *redirections);

void	close_pipe(int fd_in, int fd_out);
void	make_pipe(int fd_in, int fd_out);

void	initial_signals(void);
void	wait_signals(void);
void	child_signals(void);
void	sigint_handler(int sig);

int		num_files_dir(char *name);
char	**get_file_names(char *name);

char	**list_to_argv(t_word *words);
void	clean_argv(char **arr);
char	**ft_copyarg(char **argv);

char	*heredoc(t_redir *redir, char *delimiter);
char	*ft_temfile(void);

void	ft_initenv(void);

#endif
