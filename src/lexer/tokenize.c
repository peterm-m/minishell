/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:35:54 by adiaz-uf          #+#    #+#             */
/*   Updated: 2024/04/07 13:10:06 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h" 

int	in_brakets(int c)
{
	return (c == '(' || c == ')'
		|| c == '{' || c == '}');
}

/**
 * The function takes an input string, an index, and a doubly linked list head
 * pointer, and returns the index of the next token in the input string.
 * 
 * @param input A pointer to a character array representing the input string.
 * @param i The parameter `i` is an integer that represents the current 
 * index position in the `input` string. It is used to keep track of 
 * the progress while parsing the input string.
 * 
 * @return The function `get_next_token` returns an integer value.
 */
int	get_next_token(char *input, int i, t_token *token)
{
	while (is_blankspace(input[i]))
		i++;
	if (!input[i])
		return (i);
	if (input[i] == '$')
		return (get_dolar(input, i, token));
	if (is_quotes(input[i]) && input[i] == '\'')
		return (get_string(input, i, token, 0));
	else if (is_quotes(input[i]) && input[i] == '\"')
		return (get_string(input, i, token, 1));
	else if (is_operator(input[i]) || in_brakets(input[i]))
		return (get_token(input, i, token));
	else if (!in_word(input[i]) && !ft_isdigit(input[i]))
		return (get_word(input, i, token));
	else if (ft_isdigit(input[i]))
		return (get_ionumber(input, i, token));
	return (i);
}

/**
 * The function takes an input string and creates a doubly linked list of tokens.
 * 
 * @param input A pointer to a character array representing the input string.
 * 
 * @return the pointer to the head of the doubly linked list.
 */
t_dlst	*tokenize(char *input)
{
	int		i;
	t_dlst	*head;
	t_token	*token;

	i = 0;
	head = NULL;
	while (1)
	{
		token = new_token();
		i = get_next_token(input, i, token);
		if (token->flag == 0)
		{
			token->flag = tt_end;
			ft_dlstaddb(&head, ft_dlstnew(token));
			ft_dlstiter(head, search_w_q);
			break ;
		}
		else if (i == LEX_ERROR)
		{
			ft_dlstclear(&head, ft_free);
			return (NULL);
		}
		ft_dlstaddb(&head, ft_dlstnew(token));
	}
	return (head);
}
