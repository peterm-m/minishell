/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:25:49 by pedro             #+#    #+#             */
/*   Updated: 2024/04/15 12:47:52 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_command	*parser_error(t_dlst **lex, t_command *command)
{
	static char	*terminals[15] = {"&&", "||", "|", "{", "}", "(", ")",
		"", "newline", "<", ">", ">>", "newline", "<<", "newline"};

	clean_command(command);
	if (lex == NULL || *lex == NULL)
		return (NULL);
	if (type_token(lex) == tt_word)
		printf("minishell: syntax error near unexpected token `%s' \n",
			((t_token *)((*lex)->data))->str);
	else
		printf("minishell: syntax error near unexpected token `%s' \n",
			terminals[type_token(lex)]);
	ft_dlstclear(lex, free_token);
	return (NULL);
}

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
