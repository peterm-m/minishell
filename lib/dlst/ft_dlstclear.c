/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:59:09 by pedro             #+#    #+#             */
/*   Updated: 2023/12/14 20:43:02 by pedromar         ###   ########.fr       */
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
