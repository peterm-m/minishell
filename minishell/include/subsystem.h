/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subsystem.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:56:58 by pedromar          #+#    #+#             */
/*   Updated: 2024/03/12 19:42:06 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUBSYSTEM_H
# define SUBSYSTEM_H

# include "minishell.h"

void	subsystem(void);

typedef struct s_env
{
	char	*key;
	char	**value;
}	t_env;

void	initial_signals(void);
void	sigint_handler(int sig);

//get_env.c
t_dlst	*get_enviroment(const char **env, t_dlst **head);
char	**make_char(t_dlst *head);

// env_list_utils.c
t_env	*new_t_env(void);
void	free_t_env(t_env *tok);
void	open_redir(t_redirect *redirections);
void	make_redir(t_redirect *redirections);

#endif