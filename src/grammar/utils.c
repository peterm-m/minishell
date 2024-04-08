/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 20:38:02 by pedro             #+#    #+#             */
/*   Updated: 2024/04/08 12:58:48 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
	elimina los n nodos previos de state y lex
	TODO: traducir
*/

void	pop_elements(t_dlst **lex, t_dlst **state, int n)
{
	t_dlst	*node;
	t_dlst	*tmp;

	dbg("│\t└%s\n", "pop_element");
	node = (*lex)->prev;
	while (n)
	{
		tmp = (*state)->next;
		ft_dlstdelone(*state, ft_free);
		*state = tmp;
		tmp = node->prev;
		if (tmp->prev != NULL)
			tmp->prev->next = node;
		node->prev = tmp->prev;
		tmp->data = NULL;
		ft_dlstdelone(tmp, ft_free);
		n--;
	}
}
