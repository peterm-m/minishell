/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 01:05:58 by pedro             #+#    #+#             */
/*   Updated: 2024/04/08 17:01:03 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#undef LOGS 
#define LOGS 0

t_element	*make_element(t_word_list *word, t_redirect *redir)
{
	t_element	*element;

	dbg("│\t│\t├─%s\n", "make element");
	element = (t_element *)ft_malloc(sizeof(t_element));
	element->word = word;
	element->redirect = redir;
	return (element);
}

void	clean_element(t_element *element)
{
	clean_word(&(element->word));
	clean_redirection(&(element->redirect));
	ft_free(element);
	dbg("├─%s\n", "clean_element");
}

t_element	*join_element(t_element *element1, t_element *element2)
{
	dbg("│\t│\t├─%s\n", "join_element");
	if (element1 == NULL)
		return (element2);
	if (element2 == NULL)
		return (element1);
	join_word(&(element1->word), element2->word);
	join_redir(&(element1->redirect), element2->redirect);
	ft_free(element1);
	return (element2);
}
