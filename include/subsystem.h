/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subsystem.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:56:58 by pedromar          #+#    #+#             */
/*   Updated: 2023/12/14 20:05:58 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUBSYSTEM_H
# define SUBSYSTEM_H

void	subsystem(void);

typedef struct s_env
{
	char			*key;
    char            **value;

} t_env;

//get_env.c
t_dlst   *get_enviroment(const char **env, t_dlst **head);
void    set_env(char *key, char *value, t_env *tok);
char    **make_char(t_dlst *head);
char    *get_env_value(char *str, char **env);

// env_list_utils.c
t_env *new_t_env(void);
void free_t_env(t_env *tok);

#endif