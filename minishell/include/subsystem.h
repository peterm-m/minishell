/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subsystem.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:56:58 by pedromar          #+#    #+#             */
/*   Updated: 2024/03/12 20:27:16 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUBSYSTEM_H
# define SUBSYSTEM_H

# include "minishell.h"

typedef struct s_env
{
	char	*key;
	char	**value;
}	t_env;

void	make_redir(t_redirect *redirections);
void	open_redir(t_redirect *redirections);

void	initial_signals(void);
void	sigint_handler(int sig);

#endif