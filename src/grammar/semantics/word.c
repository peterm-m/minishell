/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:05:30 by pedromar          #+#    #+#             */
/*   Updated: 2024/01/21 19:53:34 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clean_word(t_word_list *word)
{
	if (word)
	{
		clean_word(word->next);
		free(word);
	}
}

t_word_list	*make_word(t_token *word)
{
	t_word_list	*new;

	if (word == NULL)
		return (NULL);
	new = (t_word_list *)ft_malloc(sizeof(t_word_list));
	new->word = word;
	new->next = NULL;
	return (new);
}

t_word_list	*join_word(t_word_list *word1, t_word_list *word2)
{
	t_word_list	*tmp;

	if (word1 == NULL)
		return (word2);
	tmp = word1;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = word2;
	return (word2);
}
