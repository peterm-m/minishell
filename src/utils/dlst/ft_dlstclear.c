/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:59:09 by pedro             #+#    #+#             */
/*   Updated: 2023/08/13 13:12:52 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlst.h"

void	ft_dlstclear(t_dlst **dlst, void (*del)(void*))
{
	t_dlst	*aux;

	aux = *dlst;
	while (aux != NULL)
	{
		*dlst = aux->next;
		del(aux->data);
		free(aux);
		aux = *dlst;
	}
}
