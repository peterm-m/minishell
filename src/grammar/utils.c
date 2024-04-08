/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 20:38:02 by pedro             #+#    #+#             */
/*   Updated: 2024/02/26 20:09:40 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
	elimina los n nodos previos de state y lex
	TODO: traducir
*/

void	pop_elements(t_dlst **lex, t_dlst **state, int n)
{
	t_dlst	**node;
	t_dlst	*tmp;

	dbg("│\t└%s\n", "pop_element");
	node = &(*lex)->prev;
	while (n)
	{
		tmp = (*state)->next;
		ft_dlstdelone(*state, ft_free);
		*state = tmp;
		printf("prev= %s\n", ((t_token *)(*node)->prev->data)->str);
		tmp = (*node)->prev; //TODO: Error porque aquí (*node)->prev es NULL
		if (tmp->prev != NULL)
			tmp->prev->next = *node;
		(*node)->prev = tmp->prev;
		tmp->data = NULL;
		ft_dlstdelone(tmp, ft_free);
		n--;
	}
}
