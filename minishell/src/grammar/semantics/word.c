/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:05:30 by pedromar          #+#    #+#             */
/*   Updated: 2024/03/20 21:09:22 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#undef LOGS
#define LOGS 0

void	print_word(t_word_list *word)
{
	if (word != NULL)
	{
		fprintf(stderr, "%s,", word->word);
		print_word(word->next);
	}
	else
		fprintf(stderr, "\n");
}

void	clean_word(t_word_list **word)
{
	t_word_list	*aux;

	while (*word)
	{
		aux = (*word)->next;
		ft_free(*word);
		*word = aux;
	}
	dbg("├─%s\n", "clean_word");
}

t_word_list	*make_word(t_token *word)
{
	t_word_list	*new;

	dbg("│\t│\t├─%s\n", "make word");
	if (word == NULL)
		return (NULL);
	new = (t_word_list *)ft_malloc(sizeof(t_word_list));
	new->next = NULL;
	new->word = word->str;
	ft_free(word);
	//printf("word a checkear expansion: %s\n", word->str);
/* 	if (word->flag | EXPAND)
		expander(new); */
	return (new);
}

int	make_number(t_token *word)
{
	int	fd;

	dbg("│\t│\t├─%s\n", "make number");
	if (word == NULL)
		return (-1);
	fd = ft_atoi(word->str);
	free_token(word);
	return (fd);
}

void	join_word(t_word_list **word1, t_word_list *word2)
{
	t_word_list	*tmp;

	dbg("│\t│\t├─%s\n", "join word");
	if (*word1 == NULL)
	{
		*word1 = word2;
		return ;
	}
	tmp = *word1;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = word2;
}
