/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:56:16 by pedromar          #+#    #+#             */
/*   Updated: 2023/11/21 17:29:43 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h" 
// Link Makefile bien y borrar
#include <stdio.h>
#define BHBLK "\e[1;90m"
#define BHRED "\e[1;91m"
#define BHGRN "\e[1;92m"
#define BHYEL "\e[1;93m"
#define BHBLU "\e[1;94m"
#define BHMAG "\e[1;95m"
#define BHCYN "\e[1;96m"
#define BHWHT "\e[1;97m"
#define END "\e[0m"
//							   ^^
// Link Makefile bien y borrar ||
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
		{13, 11,  2, 11,  1, 11,  6, 14}, // 5 Ampersand 	 -> &
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
int ft_strlen(char *s)
{
	int i;

	i = 0;
	while(s[i])
		i++;
	return (i);
}
int evaluate_state(char *str)
{
	int state;
	int i;

	i = -1;
	state = 0;
	while (++i < ft_strlen(str))
		state = states(state, in_abc(str[i]));
	if (state == 14 || state == 12)
		printf(BHGRN"Valid Input\n"END);
	else
		printf(BHRED"Invalid Input\n"END);
	return (state);
}

int	lexer(char *read_line)
{
	int s;
	s = evaluate_state(read_line);
	printf ("estado: %i\n", s);
	return (1);
}

/* int main()
{
	lexer("echo \"'hola ****||||1<<<>>>>'\"; cat *; ls | ls -la > outfile.txt");
} */