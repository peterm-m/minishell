/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:00:59 by pedro             #+#    #+#             */
/*   Updated: 2023/12/14 21:19:20 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlst.h"

t_dlst	*ft_dlstnew(void *data)
{
	t_dlst	*new_node;

	new_node = malloc(sizeof(t_dlst));
	if (new_node != NULL)
	{
		new_node->data = data;
		new_node->next = NULL;
		new_node->prev = NULL;
	}
	return (new_node);
}
