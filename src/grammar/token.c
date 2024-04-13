/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:25:49 by pedro             #+#    #+#             */
/*   Updated: 2024/04/13 11:31:56 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_terminals	token_type(t_dlst **lex)
{
	t_token	*token;

	token = (t_token *)(*lex)->data;
	return (token->flag & TOK_TYPE);
}

t_token	*pop_token(t_dlst **lex)
{
	t_token	*token;
	t_dlst	*current;

	if (*lex == NULL)
		return (NULL);
	token = (*lex)->data;
	current = *lex;
	*lex = current->next;
	(*lex)->prev = NULL;
	ft_free(current);
	return (token);
}
