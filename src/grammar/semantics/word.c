/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:05:30 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/08 17:01:03 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#undef LOGS
#define LOGS 0

void	clean_word(t_word_list **word)
{
	t_word_list	*aux;

	while (*word)
	{
		aux = (*word)->next;
		ft_free((*word)->word);
		ft_free(*word);
		*word = aux;
	}
	dbg("├─%s\n", "clean_word");
}

t_word_list	*make_word(t_token *token)
{
	t_word_list	*new;

	dbg("│\t│\t├─%s\n", "make word");
	if (token == NULL)
		return (NULL);
	expander(token);
	new = (t_word_list *)ft_malloc(sizeof(t_word_list));
	new->next = NULL;
	new->word = token->str;
	ft_free(token);
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
