/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subsystem.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:56:58 by pedromar          #+#    #+#             */
/*   Updated: 2024/03/27 10:45:52 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUBSYSTEM_H
# define SUBSYSTEM_H

# include "minishell.h"

void	make_redir(t_redirect *redirections);
void	open_redir(t_redirect *redirections);

void	close_pipe(int fd_in, int fd_out);
void	make_pipe(int fd_in, int fd_out);

void	initial_signals(void);
void	wait_signals(void);
void	child_signals(void);
void	sigint_handler(int sig);

#endif