/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:25:49 by pedro             #+#    #+#             */
/*   Updated: 2024/04/13 16:13:33 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	redirection_token(t_dlst **lex)
{
	t_terminals	type;

	type = type_token(lex);
	return (type == tt_less || type == tt_dless \
		|| type == tt_great || type == tt_dgreat);
}

t_terminals	type_token(t_dlst **lex)
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
