/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:36:17 by adiaz-uf          #+#    #+#             */
/*   Updated: 2024/03/18 21:08:33 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h" 

t_token	*new_token(void)
{
	t_token	*token;

	token = ft_malloc(sizeof(t_token));
	token->str = NULL;
	token->flag = 0;
	return (token);
}

void	set_token(char *str, int j, int type, t_token *token)
{
	if ((type & TOK_TYPE) == tt_word || (type & TOK_TYPE) == tt_io_number
		|| (type & TOK_TYPE) == tt_assignment_word)
	{
		token->str = ft_substr(str, 0, j);
		if (!token->str)
		{
			token->flag = LEX_ERROR;
			return ;
		}
	}
	token->flag |= type;
}

void	free_token(void *tok)
{
	t_token	*t;

	t = (t_token *) tok;
	if (t->str)
		ft_free(t->str);
	ft_free((void *)t);
}

void	search_w_q(void *t)
{
	t_token	*token;

	token = (t_token *) t;
	if (token != NULL && token->str != NULL && !is_quotes(token->str[0]))
	{
		if (ft_strchr(token->str, '*') != 0)
			token->flag |= (EXPAND | WILDCARD);
		if (ft_strchr(token->str, '?') != 0)
			token->flag |= (EXPAND | QUEST);
	}
	else if (token != NULL && token->str == NULL)
	{
		if (token->flag == tt_and_if_aux)
			token->flag = tt_and_if;
	}
}
