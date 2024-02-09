/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 22:00:53 by pedro             #+#    #+#             */
/*   Updated: 2024/02/09 18:02:58 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"

void	ft_lstaddf(t_lst **lst, t_lst *node)
{
	node->next = *lst;
	*lst = node;
}

void	ft_lstaddb(t_lst **lst, t_lst *node)
{
	t_lst	*last;

	last = ft_lstlast(*lst);
	if (last == NULL)
		*lst = node;
	else
		last->next = node;
}
