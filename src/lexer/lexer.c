/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:36:26 by adiaz-uf          #+#    #+#             */
/*   Updated: 2024/04/15 20:32:48 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
States table 
*	0 Empty input
*	1 Double quotes    -> "
*	2 Single quotes    -> '
*	3 OR        		-> ||
*	4 Pipe      		-> |
*	5 Ampersand 		-> &
*	6 AND 				   -> &&
*	7 Less			    -> <
*	8 Heredoc			-><<
*	9 Redirection 		-> > 
*	10 Append			-> >>
*	11 Invalid Input
*	12 String
*	13 Spaces without words
*	14 Not operators
*	15 lbraket        -> (
*	16 rbraket        -> )
*	17 lbrace         -> {
*	18 rbrace         -> }
*	 \s,  |,  ',  <,  ",  >,  &,  (, ),  {,  }.
*/
int	states(int i, int j)
{
	static const int	states[19][12] = \
	{
	{0, 11, 2, 7, 1, 9, 11, 15, 16, 17, 18, 14},
	{1, 1, 1, 1, 12, 1, 1, 1, 1, 1, 1, 1},
	{2, 2, 12, 2, 2, 2, 2, 2, 2, 2, 2, 2},
	{13, 11, 2, 11, 11, 1, 11, 15, 16, 17, 18, 14},
	{13, 3, 2, 7, 1, 11, 11, 15, 16, 17, 18, 14},
	{11, 11, 2, 11, 1, 11, 6, 11, 11, 11, 11, 14},
	{13, 11, 2, 11, 1, 11, 11, 15, 16, 17, 18, 14},
	{13, 11, 2, 8, 1, 11, 11, 15, 16, 17, 18, 14},
	{13, 11, 2, 11, 1, 11, 11, 15, 16, 17, 18, 14},
	{13, 11, 2, 11, 1, 10, 11, 15, 16, 17, 18, 14},
	{13, 11, 2, 11, 1, 11, 11, 15, 16, 17, 18, 14},
	{11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 14},
	{12, 4, 2, 7, 1, 9, 5, 15, 16, 17, 18, 14},
	{13, 4, 2, 7, 1, 9, 5, 15, 16, 17, 18, 14},
	{12, 4, 2, 7, 1, 9, 5, 15, 16, 17, 18, 14},
	{13, 11, 2, 11, 1, 11, 11, 15, 16, 17, 18, 14},
	{13, 4, 2, 7, 1, 9, 5, 15, 16, 17, 18, 14},
	{13, 11, 2, 11, 1, 11, 11, 15, 16, 17, 18, 14},
	{13, 4, 2, 7, 1, 9, 5, 15, 16, 17, 18, 14},
	};

	return (states[i][j]);
}

/**
 * The function "in_abc" returns the index of a character 
 * in a given string if it is found, otherwise it returns 
 * the length of the string.
 * 
 * @param c The parameter "c" is a character that is being 
 * checked against the characters in the string " |'<\">&". 
 * The function "in_abc" returns the index of the character 
 * in the string if it is found, or the length of the string 
 * if it is not found.
 * 
 * @return the index of the character 'c' in the string " |'<\">&". 
 * If the character is not found in the string, it will 
 * return the length of the string.
 */
int	in_abc(char c)
{
	int		i;
	char	*abc;

	abc = " |'<\">&(){}";
	i = -1;
	while (abc[++i])
		if (abc[i] == c)
			return (i);
	return (i);
}

/**
 * The function evaluates the state of a given string 
 * based on states table conditions.
 * 
 * @param str The parameter `str` is a pointer to a character 
 * array (string) that represents the input state.
 * 
 * @return the value of the variable "state".
 */
int	evaluate_state(char *str)
{
	int				state;
	size_t			i;
	t_braket_count	b_counter;

	b_counter.state_brace = 0;
	b_counter.state_braket = 0;
	i = 0;
	state = 0;
	while (i < ft_strlen(str))
	{
		state = states(state, in_abc(str[i++]));
		if (state == 11)
		{
			printf("minishell: parse error near `%c'\n", str[i - 1]);
			return (LEX_ERROR);
		}
		b_counter = check_braces(state, b_counter);
	}
	if (b_counter.state_brace != 0 || b_counter.state_braket != 0)
	{
		printf("minishell: parse error near `%c'\n", str[i - 1]);
		return (LEX_ERROR);
	}
	return (state);
}
/* 		if (b_counter.state_brace < 0 || b_counter.state_braket < 0)
			return (LEX_ERROR); */

/**
 * The function "lexer" takes a string as input, evaluates its state, 
 * and returns a tokenized doubly linked list if the input is valid.
 * 
 * @param read_line The input line to be tokenized.
 * 
 * @return A pointer to a `t_dlst` structure.
 */
t_dlst	*lexer(char *read_line)
{
	int	state;

	state = evaluate_state(read_line);
	if (state != 12 && state != 14 && state != 16 && state != 18 && state != 13)
		return (NULL);
	return (tokenize(read_line));
}
