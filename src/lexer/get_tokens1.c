/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:36:44 by adiaz-uf          #+#    #+#             */
/*   Updated: 2024/04/07 13:22:53 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * The function determines the type of a dollar sign ($) in a given string.
 * 
 * @param str String that contains the input text.
 * @param i The index of the character in
 * the string `str` where the dollar sign ($) is located.
 * 
 * @return the type of dollar symbol found in the given string.
 */
int	get_dolar_type(char *str, int i)
{
	if (str[i] == '$' && str[i + 1] == '(')
		return (COMMD_SUB | EXPAND);
	else
		return (PARAM_E | EXPAND);
}

/**
 * The function takes a string, an index, and a doubly linked list 
 * as arguments, and adds a token to the linked list based on the 
 * quoted substring starting from the given index in the string.
 * 
 * @param str string that contains the input data.
 * @param i The starting index of the string `str` from where the function should
 * start processing.
 * 
 * @return The index position of the next character after this quoted token.
 */
int	get_string(char *str, int i, t_token *token, int d_quote)
{
	int	j;

	j = 1;
	while (!is_quotes(str[i + j]))
	{
		if (str[i + j] == '$' && d_quote && !is_blankspace(str[i + j + 1])
			&& !is_quotes(str[i + j + 1]))
			token->flag |= get_dolar_type(str, i + j);
		j++;
	}
	if (!in_word(str[i + j]) && !ft_isdigit(str[i + j]))
	{
		while (!in_word(str[i + j]) && str[i + j] && str[i + j] != ')')
		{
			if (str[i + j] == '$' && !is_blankspace(str[i + j + 1])
				&& !is_quotes(str[i + j + 1]) && d_quote)
				token->flag |= get_dolar_type(str, i + j);
			j++;
		}
	}
	set_token(&str[i], j, tt_word, token);
	return (i + j);
}

/**
 * The function takes a string, an index, and a double linked 
 * list as input, and adds a new token representing a word to the 
 * double linked list starting from the given index in the string.
 * 
 * @param str String that contains the input text.
 * @param i The starting index in the string `str` from where we need to start
 * extracting the word.
 * 
 * @return The index position of the next character after this token.
 */
int	get_word(char *str, int i, t_token *token)
{
	int	j;

	j = 0;
	while (!in_word(str[i + j]) && str[i + j])
	{
		if (str[i + j] == '$' && str[i + j] != '\"' && str[i + j + 1]
			&& !is_blankspace(str[i + j + 1]) && !is_quotes(str[i + j + 1]))
		{
			token->flag |= get_dolar_type(str, i + j);
			while (!is_blankspace(str[i + j + 1]) && str[i + j + 1])
				j++;
		}
		if (in_brakets(str[i + j]))
			break ;
		j++;
	}
	set_token(&str[i], j, tt_word, token);
	if (token->flag == LEX_ERROR)
		return (LEX_ERROR);
	return (i + j);
}

/**
 * The function parses a string and adds a token to a doubly linked list 
 * based on the type of expansion specified by the characters 
 * following a '$' symbol.
 * 
 * @param str A pointer to a character array (string) that contains the input.
 * @param i The index of the current character in the string `str`.
 * @param type The "type" parameter is an integer that represents the type 
 * of expansion being performed. It can have one of the following values:
 * 
 * @return The index position of the next character after the token.
 */
int	get_dolar2(char *str, int i, t_token *token)
{
	int	j;

	j = 2;
	token->flag = tt_word | EXPAND;
	if (str[i] == '$' && str[i + 1] == '(')
	{
		token->flag |= COMMD_SUB;
		while (str[i + j] != ')')
			j++;
	}
	else if (str[i] == '$' && str[i + 1] == '{')
	{
		token->flag |= PARAM_E;
		while (str[i + j] != '}')
			j++;
	}
	set_token(&str[i], j + 1, token->flag, token);
	if (token->flag == LEX_ERROR)
		return (LEX_ERROR);
	return (i + j + 1);
}

/**
 * The function adds a token to a doubly linked list if it encounters a
 * dollar sign followed by a word.
 * 
 * @param str String that contains the input text.
 * @param i The index of the current character in the string `str`. It is used to
 * keep track of the position in the string while parsing it.
 * @return The index position of the next character after the token.
 */
int	get_dolar(char *str, int i, t_token *token)
{
	int	j;

	j = 1;
	if (str[i + j] == '(' || str[i + j] == '{')
		return (get_dolar2(str, i, token));
	else
	{
		while (!is_blankspace(str[i + j]) && str[i + j])
			j++;
	}
	set_token(&str[i], j, EXPAND | PARAM_E | tt_word, token);
	if (token->flag == LEX_ERROR)
		return (LEX_ERROR);
	return (i + j);
}
