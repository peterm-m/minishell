/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 20:38:02 by pedro             #+#    #+#             */
/*   Updated: 2024/01/30 21:15:42 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
	Delete n element of lex and state
*/

//void free_token(t_token *tok)
//{
//	dbg("%s\n","");
//	if (tok != NULL)
//		return ;
//	if (tok->str != NULL)
//		ft_free(tok->str);
//}


// TODO: revisar la limpieza de cada elementos

void	pop_elements(t_dlst **lex, t_dlst **state, int n)
{
	t_dlst	*tmp;

	dbg("%s\n", (*lex)->data);
	while (n)
	{
		tmp = (*state)->next;
		ft_dlstdelone(*state, ft_free);
		*state = tmp;
		tmp = (*lex)->prev;
		tmp->prev->next = (*lex);
		(*lex)->prev = tmp->prev;
		ft_dlstdelone(tmp, ft_free);
		n--;
	}
}
