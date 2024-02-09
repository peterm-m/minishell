/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:00:59 by pedro             #+#    #+#             */
/*   Updated: 2023/08/13 11:45:52 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"

t_lst	*ft_lstnew(void *data)
{
	t_lst	*new_node;

	new_node = malloc(sizeof(t_lst));
	if (new_node != NULL)
	{
		new_node->data = data;
		new_node->next = NULL;
	}
	return (new_node);
}
