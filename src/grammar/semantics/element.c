/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 01:05:58 by pedro             #+#    #+#             */
/*   Updated: 2024/01/24 21:24:27 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_element	*make_element(t_token *word, t_redirect *redir)
{
	dbg("%s\n","");
	t_element	*element;

	element = (t_element *)ft_malloc(sizeof(t_element));
	if (word != NULL)
		element->word = make_word(word);
	if (redir != NULL)
		element->redirect = redir;
	return (element);
}

void	clean_element(t_element *element)
{
	dbg("%s\n","");
	clean_word(element->word);
	clean_redirection(element->redirect);
	free(element);
}
