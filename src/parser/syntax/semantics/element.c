/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 01:05:58 by pedro             #+#    #+#             */
/*   Updated: 2024/01/06 19:38:12 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_element	*make_element(t_dlst *lex, t_state *state, int rule)
{
	t_element	*element;

	element = (t_element *)ft_malloc(sizeof(t_element));
	return (element);
}

void	append_element(t_dlst *lex, t_state *state, int rule)
{
	return ;
}


//WORD_LIST *
//make_word_list (word, wlink)
//     WORD_DESC *word;
//     WORD_LIST *wlink;
//{
//  WORD_LIST *temp;
//
//  ocache_alloc (wlcache, WORD_LIST, temp);
//
//  temp->word = word;
//  temp->next = wlink;
//  return (temp);
//}
//