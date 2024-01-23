/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 20:38:02 by pedro             #+#    #+#             */
/*   Updated: 2024/01/21 21:25:22 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
	Delete n element of lex and state
*/

// TODO: revisar la limpieza de cada elementos

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
		free_token(tmp->data);
		ft_dlstdelone(tmp, free);
		n--;
	}
}