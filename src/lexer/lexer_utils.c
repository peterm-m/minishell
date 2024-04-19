/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:36:35 by adiaz-uf          #+#    #+#             */
/*   Updated: 2024/04/19 18:09:55 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h" 

/**
 * The function checks if a given character is a token 
 * (one of the following: '|', '<', '>', '(', ')', ';', or '&')
 * 
 * @param c The parameter `c` is an integer representing a character.
 * 
 * @return The function is_operator is returning 1 if the input 
 * character c is a token Otherwise, it is returning 0.
 */
int	is_operator(int c)
{
	return (c == '|' || c == '<' || c == '>'
		|| c == '&');
}

/**
 * The function checks if a character is a blank space or a whitespace character.
 * 
 * @param c The parameter "c" is of type char and represents a character.
 * 
 * @return Boolean value indicating if the character is a blank space or not.
 */
int	is_blankspace(char c)
{
	return (c == ' ' || (c > 8 && c < 14));
}

/**
 * The function checks if a character is a single or double quote.
 * 
 * @param c The parameter `c` is the character that we want to check.
 * 
 * @return returns 1 if the character c is either a single quote (') or 
 * a double quote (") and returns 0 otherwise.
 */
int	is_quotes(char c)
{
	return (c == '\'' || c == '"');
}

/**
 * The function checks if a character is part of a word by checking if 
 * it is a quote, token, dollar sign, blank space, or null character.
 * 
 * @param c The parameter "c" is a character that is being checked 
 * to determine if it is part of a word.
 * 
 * @return a boolean value.
 */
int	in_word(char c)
{
	return (is_operator(c) || is_blankspace(c) || c == '\0');
}

t_braket_count	check_braces(int state, t_braket_count b_count)
{
	if (state == 15)
		b_count.state_braket++;
	else if (state == 16)
		b_count.state_braket--;
	else if (state == 17)
		b_count.state_brace++;
	else if (state == 18)
		b_count.state_brace--;
	return (b_count);
}
