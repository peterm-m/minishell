/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:40:36 by pedro             #+#    #+#             */
/*   Updated: 2023/08/13 11:45:52 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"

t_lst	*ft_lstmap(t_lst *lst, void *(*f)(void *), void (*del)(void *))
{
	t_lst	*new_lst;
	t_lst	*elem;

	if (!lst)
		return (NULL);
	new_lst = 0;
	while (lst)
	{
		elem = ft_lstnew(f(lst->data));
		if (!elem)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstaddb(&new_lst, elem);
		lst = lst->next;
	}
	return (new_lst);
}
