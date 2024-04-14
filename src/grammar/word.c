/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:44:28 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/14 14:45:39 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_word	*make_word(t_dlst **lex)
{
	t_word	*word_list;
	t_token	*word;

	word_list = ft_calloc(1, sizeof(t_word));
	if (word_list == NULL)
		return (NULL);
	if (type_token(lex) == tt_word)
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

int	add_word(t_word **word_list, t_dlst **lex)
{
	t_word	*new;
	t_word	*tmp;

	new = make_word(lex);
	if (new == NULL)
		return (EXIT_FAILURE);
	if (word_list == NULL || *word_list == NULL)
	{
		*word_list = new;
		return (EXIT_SUCCESS);
	}
	tmp = *word_list;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	return (EXIT_SUCCESS);
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
