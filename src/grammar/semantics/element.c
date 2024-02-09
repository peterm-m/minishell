/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 01:05:58 by pedro             #+#    #+#             */
/*   Updated: 2024/02/09 18:32:00 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#undef LOGS 
#define LOGS 1

t_element	*make_element(t_word_list *word, t_redirect *redir)
{
	dbg("│\t│\t├─%s\n","make element");
	t_element	*element;

	element = (t_element *)ft_malloc(sizeof(t_element));
	element->word = word;
	element->redirect = redir;
	return (element);
}

void	clean_element(t_element *element)
{
	dbg("│\t│\t├─%s\n","clean_element");
	clean_word(element->word);
	clean_redirection(element->redirect);
	ft_free(element);
}

void	join_element(t_element *element1, t_element *element2)
{
	if (element1 != NULL && element2 != NULL)
	{
		join_word(&(element1->word), element2->word);
		join_redirection(&(element1->redirect), element2->redirect);
	}
	else if (element1 == NULL && element2 != NULL)
		return (element2);
	else if (element2 == NULL && element1 != NULL)
		return (element2);
	else
		return (NULL);
}
