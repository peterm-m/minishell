/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:36:39 by adiaz-uf          #+#    #+#             */
/*   Updated: 2024/04/15 20:14:04 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h" 

/**
 * The function extracts an IO number from a string and adds 
 * it as a token to a doubly linked list.
 * 
 * @param str A pointer to a character array (string) that contains the input.
 * @param i The current index in the string `str`. It is used to keep
 * track of the position while parsing the string.
 * 
 * @return the index position of the next character after the token.
 */
int	get_ionumber(char *str, int i, t_token *token)
{
	int	j;

	j = 0;
	while (ft_isdigit(str[i + j]))
		j++;
	while (is_blankspace(str[i + j]))
		j++;
	if (str[i + j] == '>' || str[i + j] == '<')
	{
		set_token(str + i, j, tt_word, token);
		token->flag = tt_io_number;
	}
	else if (!in_word(str[i + j]))
	{
		while (!in_word(str[i + j]) && str[i + j] && str[i + j] != ')'
			&& str[i + j] != '}')
			j++;
		set_token(str + i, j, tt_word, token);
	}
	else
		set_token(str + i, j, tt_word, token);
	if (token->flag == LEX_ERROR)
		return (LEX_ERROR);
	return (i + j);
}

/**
 * The function adds tokens to a doubly linked list based on 
 * specific characters in a string.
 * 
 * @param str A pointer to a character array (string) that contains the input.
 * @param i The current index position in the string `str`.
 * It is used to iterate through the characters of the string.
 * 
 * @return the updated value of the variable 'i'.
 */
int	get_token(char *str, int i, t_token *token)
{
	if (str[i] == '|' && str[i + 1] != '|')
		set_token(str + i, 1, tt_pipe, token);
	else if (str[i] == '<' && str[i + 1] != '<')
		set_token(str + i, 1, tt_less, token);
	else if (str[i] == '>' && str[i + 1] != '>')
		set_token(str + i, 1, tt_great, token);
	else if (str[i] == '(' || str[i] == '{'
		|| str[i] == ')' || str[i] == '}' )
		return (get_braket_token(str, i, token));
	else
		return (get_token2(str, i, token));
	if (token->flag == LEX_ERROR)
		return (LEX_ERROR);
	i++;
	return (i);
}

/**
 * The function adds tokens to a doubly linked list based on 
 * specific characters in a string.
 * 
 * @param str A pointer to a character array (string) that contains the input.
 * @param i The current index position in the string
 * `str`. It is used to determine the position of the token in the string.
 *  
 * @return the updated value of the variable 'i'.
 */
int	get_token2(char *str, int i, t_token *token)
{
	if (str[i] == '|' && str[i + 1] == '|')
		set_token(str + i, 2, tt_or_if, token);
	else if (str[i] == '>' && str[i + 1] == '>')
		set_token(str + i, 2, tt_dgreat, token);
	else if (str[i] == '&' && str[i + 1] == '&')
		set_token(str + i, 2, tt_and_if_aux, token);
	else if (str[i] == '<' && str[i + 1] == '<')
		set_token(str + i, 2, tt_dless, token);
	if (token->flag == LEX_ERROR)
		return (LEX_ERROR);
	return (i + 2);
}

int	get_braket_token(char *str, int i, t_token *token)
{
	if (str[i] == '(')
		set_token(&str[i], 1, tt_lbraket, token);
	else if (str[i] == ')')
		set_token(&str[i], 1, tt_rbraket, token);
	else if (str[i] == '{')
		set_token(&str[i], 1, tt_lbrace, token);
	else if (str[i] == '}')
		set_token(&str[i], 1, tt_rbrace, token);
	if (token->flag == LEX_ERROR)
		return (LEX_ERROR);
	return (i + 1);
}
