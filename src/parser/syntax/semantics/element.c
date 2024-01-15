/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 01:05:58 by pedro             #+#    #+#             */
/*   Updated: 2024/01/15 20:46:52 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// TODO: word es tipo t_word, cambio temporal
t_element	*make_element(char *word, t_redirect *redir)
{
	t_element	*element;

	element = (t_element *)ft_malloc(sizeof(t_element));
	return (element);
}

//void	append_element(t_dlst *lex, t_state *state, int rule)
//{
//	return ;
//}


// TODO: word es tipo t_word, cambio temporal
t_word_list	*make_word(char *word)
{
	t_word_list	*new;

	new = (t_word_list *)ft_malloc(sizeof(t_word_list));
	new->word = word;
	return (new);
}

// TODO: word es tipo t_word, cambio temporal
void			join_word(t_word_list **list, char *word)
{
	t_word_list	*tmp;

	if (list == NULL)
		*list = word;
	else
	{
		tmp = *list;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = make_word(word);
	}
}
	