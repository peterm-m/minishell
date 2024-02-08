/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:05:30 by pedromar          #+#    #+#             */
/*   Updated: 2024/02/07 21:17:37 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#undef LOGS
#define LOGS 1

void	print_word(t_word_list *word)
{
	if (word != NULL)
	{
		fprintf(stderr,"%s,", word->word->str);
		print_word(word->next);
	}
	else
		fprintf(stderr,"\n");
}

void	clean_word(t_word_list *word)
{
	if (word != NULL)
	{
		clean_word(word->next);
		ft_free(word);
	}
	dbg("│\t│\t├─%s\n","clean_word");
}

t_word_list	*make_word(t_token *word)
{dbg("│\t│\t├─%s\n", "make word");
	t_word_list	*new;

	if (word == NULL)
		return (NULL);
	new = (t_word_list *)ft_malloc(sizeof(t_word_list));
	new->word = word;
	word->str = NULL;
	free_token(word);
	new->next = NULL;
	return (new);
}

t_word_list	*join_word(t_word_list *word1, t_word_list *word2)
{
	dbg("│\t│\t├─%s\n", "join word");
	t_word_list	*tmp;

	if (word1 == NULL)
		return (word2);
	tmp = word1;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = word2;
	ft_free(word1);
	return (word2);
}
#undef LOGS
#define LOGS 1

