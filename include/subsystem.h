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

typedef struct s_env_lst
{
	char			*key;
    char            *value;
	struct s_env_lst	*next;
	struct s_env_lst	*prev;
} t_env_lst;

t_env_lst   *get_enviroment(const char **env, t_env_lst **head);
// env_list_utils.c

t_env_lst	*ft_envlstnew(void *key, void *value);
void	    ft_envlstaddb(t_env_lst **head, t_env_lst *node);
void	    ft_envlstadd(t_env_lst *prev, t_env_lst *node);
t_env_lst	*ft_envlstlast(t_env_lst *envlst);
void	    ft_envlstiter(t_env_lst *envlst, void (*f)(void *));
void	    ft_envlstclear(t_env_lst **envlst, void (*del)(void*));

#endif