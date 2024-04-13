/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:44:28 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/13 11:50:37 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_word	*new_word(void)
{
	t_word	*word;

	word = ft_malloc(sizeof(t_word));
	word->next = NULL;
	word->word = NULL;
	return (word);
}

t_word	*make_word(t_dlst **lex)
{
	t_word	*word_list;
	t_token	*word;
	
	word_list = new_word();
	if (word_list == NULL)
		return (NULL);
	if (token_type(lex) == tt_word)
		word = pop_token(lex);
	else
	{
		ft_free(word_list);
		return (NULL);
	}
	expander(word);
	word_list->word = word->str;
	ft_free(word);
	return (word_list);
}

void	add_word(t_word **word_list, t_word *new)
{
	t_word	*tmp;

	if (*word_list == NULL)
	{
		*word_list = new;
		return ;
	}
	tmp = *word_list;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

void	clean_word(t_word **word)
{
	t_word	*aux;

	while (*word)
	{
		aux = (*word)->next;
		ft_free((*word)->word);
		ft_free(*word);
		*word = aux;
	}
}