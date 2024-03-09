/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 22:46:49 by pedro             #+#    #+#             */
/*   Updated: 2024/02/23 19:56:26 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DLST_H
# define FT_DLST_H

# include <stdlib.h>

typedef struct s_dlst
{
	void			*data;
	struct s_dlst	*next;
	struct s_dlst	*prev;
}	t_dlst;

t_dlst	*ft_dlstnew(void *data);

void	ft_dlstaddf(t_dlst **dlst, t_dlst *node);
void	ft_dlstaddb(t_dlst **dlst, t_dlst *node);
void	ft_dlstadd(t_dlst *prev, t_dlst *node);
t_dlst	*ft_dlstlast(t_dlst *dlst);
void	ft_dlstclear(t_dlst **dlst, void (*del)(void*));
void	ft_dlstiter(t_dlst *dlst, void (*f)(void *));
void	ft_dlstdelone(t_dlst *dlst, void (*del)(void*));

#endif
