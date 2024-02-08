/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 20:38:02 by pedro             #+#    #+#             */
/*   Updated: 2024/02/06 21:58:01 by pedro            ###   ########.fr       */
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
{ dbg("│\t└%s\n", "pop_element");
	t_dlst	**node;
	t_dlst	*tmp;

	node = &(*lex)->prev;
	while (n)
	{
		tmp = (*state)->next;
		ft_dlstdelone(*state, ft_free);
		*state = tmp;
		tmp = (*node)->prev;
		if (tmp->prev != NULL)
			tmp->prev->next = *node;
		(*node)->prev = tmp->prev;
		tmp->data =NULL;
		ft_dlstdelone(tmp, ft_free);
		n--;
	}
}
