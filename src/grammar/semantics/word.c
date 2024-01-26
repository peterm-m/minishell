/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:05:30 by pedromar          #+#    #+#             */
/*   Updated: 2024/01/24 21:40:31 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clean_word(t_word_list *word)
{
	dbg("%s\n","");
	if (word)
	{
		clean_word(word->next);
		free(word);
	}
}

t_word_list	*make_word(t_token *word)
{
	dbg("%s\n", "");
	t_word_list	*new;

	new = (t_word_list *)ft_malloc(sizeof(t_word_list));
	new->word = word;
	new->next = NULL;
	dbg("%s\n", "");
	return (new);
}

t_word_list	*join_word(t_word_list *word1, t_word_list *word2)
{
	dbg("%s\n", "");
	t_word_list	*tmp;

	if (word1 == NULL)
		return (word2);
	tmp = word1;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = word2;
	return (word2);
}
