/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:05:30 by pedromar          #+#    #+#             */
/*   Updated: 2024/02/09 18:24:20 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#undef LOGS
#define LOGS 1

void	print_word(t_word_list *word)
{
	if (word != NULL)
	{
		fprintf(stderr,"%s,", word->word);
		print_word(word->next);
	}
	else
		fprintf(stderr,"\n");
}

void	clean_word(t_word_list *word)
{dbg("│\t│\t├─%s\n","clean_word");
	if (word != NULL)
	{
		if (word->next)
			clean_word(word->next);
		ft_free(word);
	}
}

t_word_list	*make_word(t_token *word)
{dbg("│\t│\t├─%s\n", "make word");
	t_word_list	*new;

	if (word == NULL)
		return (NULL);
	new = (t_word_list *)ft_malloc(sizeof(t_word_list));
	new->next = NULL;
	new->flag = word->flag;
	new->word = word->str;
	ft_free(word);
	return (new);
}

int	make_number(t_token *word)
{dbg("│\t│\t├─%s\n", "make number");
	int	fd;

	if (word == NULL)
		return (-1);
	fd = ft_atoi(word->str);
	free_token(word);
	return (fd);
}

void	join_word(t_word_list **word1, t_word_list *word2)
{dbg("│\t│\t├─%s\n", "join word");
	t_word_list	*tmp;
	
	if (*word1 == NULL)
		*word1 = word2;
	else
	{
		tmp = *word1;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = word2;
	}
}

#undef LOGS
#define LOGS 1
