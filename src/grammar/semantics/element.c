/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 01:05:58 by pedro             #+#    #+#             */
/*   Updated: 2024/02/15 23:17:12 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#undef LOGS 
#define LOGS 0

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
{dbg("├─%s\n","clean_element");
	clean_word(&(element->word));
	clean_redirection(&(element->redirect));
	ft_free(element);
}

t_element	*join_element(t_element *element1, t_element *element2)
{dbg("│\t│\t├─%s\n","join_element");
	if (element1 == NULL)
		return (element2);
	if (element2 == NULL)
		return (element1);
	join_word(&(element1->word), element2->word);
	join_redir(&(element1->redirect), element2->redirect);
	ft_free(element1);
	return (element2);
}
