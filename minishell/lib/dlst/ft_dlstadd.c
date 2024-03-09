/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 12:19:26 by pedro             #+#    #+#             */
/*   Updated: 2024/01/25 19:06:35 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlst.h"

void	ft_dlstaddf(t_dlst **dlst, t_dlst *node)
{
	if (node != NULL)
	{
		node->next = *dlst;
		node->prev = NULL;
	}
	if (*dlst != NULL)
		(*dlst)->prev = node;
	*dlst = node;
}

void	ft_dlstaddb(t_dlst **dlst, t_dlst *node)
{
	t_dlst	*last;

	node->next = NULL;
	last = ft_dlstlast(*dlst);
	if (last == NULL)
		*dlst = node;
	else
	{
		last->next = node;
		node->prev = last;
	}
}

void	ft_dlstadd(t_dlst *prev, t_dlst *node)
{
	if (prev == NULL)
	{
		node->next = NULL;
		node->prev = NULL;
		prev = node;
	}
	else
	{
		node->next = prev->next;
		prev->next = node;
		node->prev = prev;
		if (node->next != NULL)
			node->next->prev = node;
	}
}
