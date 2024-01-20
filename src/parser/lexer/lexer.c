/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:56:16 by pedromar          #+#    #+#             */
/*   Updated: 2024/01/16 23:04:14 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h" 

/*
States table 
	     \s,  |,  ',  <,  ",  >,  &,  *?, $?,  (?,  )?
*/
int	states(int i, int j)
{
	static const int states[15][8]= \
	{ 
		{ 0, 11,  2, 11,  1, 11, 11, 14}, // 0 Empty input
		{ 1,  1,  1,  1, 12,  1,  1,  1}, // 1 Double quotes -> "
		{ 2,  2, 12,  2,  2,  2,  2,  2}, // 2 Single quotes -> '
		{13, 11,  2, 11, 11,  1, 11, 14}, // 3 OR        	 -> ||
		{13,  3,  2,  7,  1, 11, 11, 14}, // 4 Pipe      	 -> |
		{13, 11,  2, 11,  1, 11,  6, 11}, // 5 Ampersand 	 -> &
		{13, 11,  2, 11,  1, 11, 11, 14}, // 6 AND 			 -> &&
		{13, 11,  2,  8,  1, 11, 11, 14}, // 7 Less			 -> <
		{13, 11,  2, 11,  1, 11, 11, 14}, // 8 Heredoc		 ->	<<
		{13, 11,  2, 11,  1, 10, 11, 14}, // 9 Redirection 	 -> > 
		{13, 11,  2, 11,  1, 11, 11, 14}, // 10 Append		 -> >>
		{11, 11, 11, 11, 11, 11, 11, 11}, // 11 Invalid Input
		{12,  4,  2,  7,  1,  9,  5, 14}, // 12 String
		{13,  1,  2,  1,  1,  1,  1, 14}, // 13 Spaces without words
		{12,  4,  2,  7,  1,  9,  5, 14}, // 14 Not operators
	  //{13, 11,  2, 11,  1, 11, 11, 15, 14}, // 15 Wildcard     -> *
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
int in_abc(char c)
{
	int	i;
	char *abc;

	abc = " |'<\">&";
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
int evaluate_state(char *str)
{
	int state;
	size_t len;
	size_t i;

	i = 0;
	state = 0;
	len = ft_strlen(str);
	while (i < len)
		state = states(state, in_abc(str[i++]));
	return (state);
}

/**
 * The function "lexer" takes a string as input, evaluates its state, 
 * and returns a tokenized doubly linked list if the input is valid.
 * 
 * @param read_line The input line to be tokenized.
 * @param head The "head" parameter is a pointer to a doubly linked list (t_dlst). It is used to keep
 * track of the head of the list, which is updated by the "tokenize" function.
 * 
 * @return The function `lexer` is returning a pointer to a `t_dlst` structure.
 */
t_dlst	*lexer(char *read_line, t_dlst **head)
{
	int state;

	state = evaluate_state(read_line);
	printf ("estado: %i\n", state);
	if (state != 14 && state != 12)
	{
		printf(BHRED"Invalid Input\n"END);
		return (NULL);
	}
	printf(BHGRN"Valid Input: Go to tokenizer:\n"END);
	return (tokenize(read_line, head));
}
