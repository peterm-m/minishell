/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:56:16 by pedromar          #+#    #+#             */
/*   Updated: 2023/12/06 12:24:32 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h" 

char *abc = " |'\"<>&";

int	states(int i, int j)
{	  // \s,  |,  ',  <,  ",  >,  &,  *?, $?,  (?,  )?
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
	if (state == 14 || state == 12)
	{
		printf(BHGRN"Valid Input\n"END);
	}
	else
		printf(BHRED"Invalid Input\n"END);
	return (state);
}

t_dlst	*lexer(char *read_line, t_dlst **head)
{
	int state;
    //t_dlst          *head;

	//head = NULL;
	state = evaluate_state(read_line);
	printf ("estado: %i\n", state);
	if (state != 14 || state == 12)
	{
		printf(BHGRN"Valid Input\n"END);
	}
	return (tokenize(read_line, head));
}