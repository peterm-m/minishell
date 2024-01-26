/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 20:38:02 by pedro             #+#    #+#             */
/*   Updated: 2024/01/24 23:54:57 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
	Delete n element of lex and state
*/

void free_token(t_token *tok)
{
	dbg("%s\n","");
	if (tok != NULL)
		return ;
	if (tok->str != NULL)
		ft_free(tok->str);
}


// TODO: revisar la limpieza de cada elementos

void	pop_elements(t_dlst **lex, t_dlst **state, int n)
{
	dbg("%s\n","");
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
		ft_dlstdelone(tmp, ft_free);
		n--;
	}
	dbg("%s\n", (*lex)->data);
}
