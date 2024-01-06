/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 20:38:02 by pedro             #+#    #+#             */
/*   Updated: 2024/01/06 19:05:28 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
	Delete n element of lex and state
*/

void	pop_elements(t_dlst **lex, t_dlst **state, int n)
{
	t_dlst	*tmp;
	
	while (n)
	{
		tmp = (*state)->next;
		ft_dlstdelone(*state, free);
		*state = tmp;
		tmp = (*lex)->prev;
		tmp->prev->next = (*lex);
		(*lex)->prev = tmp->prev;
		ft_dlstdelone(tmp, free);
		n--;
	}
}
