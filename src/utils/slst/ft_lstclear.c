/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:59:09 by pedro             #+#    #+#             */
/*   Updated: 2023/08/13 11:45:52 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"

void	ft_lstclear(t_lst **lst, void (*del)(void*))
{
	t_lst	*aux;

	aux = *lst;
	while (aux != NULL)
	{
		*lst = aux->next;
		del(aux->data);
		free(aux);
		aux = *lst;
	}
}
