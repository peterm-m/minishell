/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 22:46:49 by pedro             #+#    #+#             */
/*   Updated: 2023/08/12 22:48:55 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LST_H
# define FT_LST_H

# include <stdlib.h>

typedef struct s_lst
{
	void			*data;
	struct s_lst	*next;
}	t_lst;

t_lst	*ft_lstnew(void *data);
int		ft_lstsize(t_lst *lst);
void	ft_lstaddf(t_lst **lst, t_lst *node);
void	ft_lstaddb(t_lst **lst, t_lst *node);
void	ft_lstdelone(t_lst *lst, void (*del)(void*));
void	ft_lstclear(t_lst **lst, void (*del)(void*));
void	ft_lstiter(t_lst *lst, void (*f)(void *));
t_lst	*ft_lstlast(t_lst *lst);
t_lst	*ft_lstmap(t_lst *lst, void *(*f)(void *), void (*del)(void *));

#endif