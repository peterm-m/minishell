/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 20:51:01 by pedro             #+#    #+#             */
/*   Updated: 2024/01/06 19:58:32 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
accept       : program $end (rule 0)
*/

void	rules_accept(t_dlst **lex, t_state **state, int rule)
{
	(void)lex;
	if (rule == 0)
		(void) 0;
	printf("applay rules_accept %d and go to %d \n", rule, *((int *)(*state)->data));
}

/*
program          : and_or    (rule 1)
                 | /empty/   (rule 2)      
*/

void	rules_program(t_dlst **lex, t_state **state, int rule)
{
	(void)lex;
	if (rule == 1)
		(void) 0;
	else if (rule == 2)
		(void) 0;
	printf("applay rules_program %d and go to %d \n", rule, *((int *)(*state)->data));
}

/*
and_or           :               pipeline (rule 3)
                 | and_or AND_IF pipeline (rule 4)
                 | and_or OR_IF  pipeline (rule 5)
*/

void	rules_and_or(t_dlst **lex, t_state **state, int rule)
{
	if (rule == 3)
		(void) 0;
	else if (rule == 4)
	{
		//(*lex)->data = make_conection((*lex)->prev->prev->data,
		//	(*lex)->data,
		//	tt_and_if);
		pop_elements(lex, state, 2);
	}
	else if (rule == 5)
	{
		//(*lex)->data = make_conection((*lex)->prev->prev->data,
		//	(*lex)->data,
		//	tt_or_if);
		pop_elements(lex, state, 2);
	}
	printf("applay rules_and_or %d and go to %d \n", rule, *((int *)(*state)->data));
}

/*
pipeline         : command              (rule 6)
                 | pipeline '|' command (rule 7)
*/

void	rules_pipeline(t_dlst **lex, t_state **state, int rule)
{
	if (rule == 6)
		(void) 0;
	else if (rule == 7)
	{
		//(*lex)->data = make_conection((*lex)->prev->prev->data,
		//	(*lex)->data,
		//	tt_pipe);
		pop_elements(lex, state, 2);
	}
	printf("applay rules_pipeline %d and go to %d \n", rule, *((int *)(*state)->data));
}

/*
command          : simple_command                 (rule 8)
                 | compound_command               (rule 9)
                 | compound_command redirect_list (rule 10)
*/

void	rules_command(t_dlst **lex, t_state **state, int rule)
{
	if (rule == 8)
		(void) 0;
	else if (rule == 9)
		(void) 0;
	else if (rule == 10)
	{
		pop_elements(lex, state, 1);
	}
	printf("applay rules_command %d and go to %d \n", rule, *((int *)(*state)->data));
}

/*
compound_command : brace_group (rule 11)
				 | subshell    (rule 12)
*/

void	rules_commpound(t_dlst **lex, t_state **state, int rule)
{
	(void)lex;
	if (rule == 11)
		(void) 0;
	else if (rule == 12)
		(void) 0;
	printf("applay rules_commpound %d and go to %d \n", rule, *((int *)(*state)->data));
}

/*
brace_group      : '{' and_or '}' (rule 13)
*/

void	rules_group(t_dlst **lex, t_state **state, int rule)
{
	if (rule == 13)
	{
		//(*lex)->data = make_group((*lex)->prev->data);
		pop_elements(lex, state, 2);
	}
	printf("applay rules_group %d and go to %d \n", rule, *((int *)(*state)->data));
}

/*
subshell         : '(' and_or ')' (rule 14)
*/

void	rules_subshell(t_dlst **lex, t_state **state, int rule)
{
	if (rule == 14)
	{
		//(*lex)->data = make_subshell((*lex)->prev->data);
		pop_elements(lex, state, 2);
	}
	printf("applay rules_subshell %d and go to %d \n", rule, *((int *)(*state)->data));
}

/*
simple_command   : cmd_prefix WORD cmd_suffix (rule 15)
                 | cmd_prefix WORD            (rule 16)
                 | cmd_prefix                 (rule 17)
                 | WORD cmd_suffix            (rule 18)
                 | WORD                       (rule 19)
*/

void	rules_simple_cmd(t_dlst **lex, t_state **state, int rule)
{
	if (rule == 15)
	{
		pop_elements(lex, state, 2);
	}
	else if (rule == 16)
	{
		pop_elements(lex, state, 1);
	}
	else if (rule == 17)
		(void) 0;
	else if (rule == 18)
	{
		pop_elements(lex, state, 1);
	}
	else if (rule == 19)
		(void) 0;
	printf("applay rules_simple_cmd %d and go to %d \n", rule, *((int *)(*state)->data));
}

/*
cmd_prefix       :            io_redirect     (rule 20)
                 | cmd_prefix io_redirect     (rule 21)
                 |            ASSIGNMENT_WORD (rule 22)
                 | cmd_prefix ASSIGNMENT_WORD (rule 23)
*/

void	rules_cmd_prefix(t_dlst **lex, t_state **state, int rule)
{
	if (rule == 20)
		(void) 0;
	else if (rule == 21)
	{
		pop_elements(lex, state, 1);
	}
	else if (rule == 22)
		(void) 0;
	else if (rule == 23)
	{
		pop_elements(lex, state, 1);
	}
	printf("applay rules_cmd_prefix %d and go to %d \n", rule, *((int *)(*state)->data));
}

/*
cmd_suffix       :            io_redirect (rule 24)
                 | cmd_suffix io_redirect (rule 25)
                 |            WORD        (rule 26)
                 | cmd_suffix WORD        (rule 27)
*/

void	rules_cmd_suffix(t_dlst **lex, t_state **state, int rule)
{
	if (rule == 24)
		(void) 0;
	else if (rule == 25)
	{
		pop_elements(lex, state, 1);
	}
	else if (rule == 26)
		(void) 0;
	else if (rule == 27)
	{
		pop_elements(lex, state, 1);
	}
	printf("applay rules_cmd_suffix %d and go to %d \n", rule, *((int *)(*state)->data));
}

/*
redirect_list    :               io_redirect (rule 28)
                 | redirect_list io_redirect (rule 29)
*/

void	rules_redirect_list(t_dlst **lex, t_state **state, int rule)
{
	if (rule == 28)
		(void) 0;
	else if (rule == 29)
	{
		pop_elements(lex, state, 1);
	}
	printf("applay rules_redirect_list %d and go to %d \n", rule, *((int *)(*state)->data));
}

/*
io_redirect      :           '<'    WORD (rule 30)
                 |           '>'    WORD (rule 31)
                 |           DGREAT WORD (rule 32)
                 | IO_NUMBER '<'    WORD (rule 33)
                 | IO_NUMBER '>'    WORD (rule 34)
                 | IO_NUMBER DGREAT WORD (rule 35)
                 |           DLESS  WORD (rule 36)
                 | IO_NUMBER DLESS  WORD (rule 37)
*/

void	rules_io_redirect(t_dlst **lex, t_state **state, int rule)
{
	if (rule == 30)
	{
		//make_redirection(&source, type, &dest, flag);
		pop_elements(lex, state, 1);
	}
	else if (rule == 31)
	{
		//make_redirection(&source, type, &dest, flag);
		pop_elements(lex, state, 1);
	}
	else if (rule == 32)
	{
		//make_redirection(&source, type, &dest, flag);
		pop_elements(lex, state, 1);
	}
	else if (rule == 33)
	{
		//make_redirection(&source, type, &dest, flag);
		pop_elements(lex, state, 2);
	}
	else if (rule == 34)
	{
		//make_redirection(&source, type, &dest, flag);
		pop_elements(lex, state, 2);
	}
	else if (rule == 35)
	{
		//make_redirection(&source, type, &dest, flag);
		pop_elements(lex, state, 2);
	}
	else if (rule == 36)
	{
		//make_redirection(&source, type, &dest, flag);
		pop_elements(lex, state, 1);
	}
	else if (rule == 37)
	{
		//make_redirection(&source, type, &dest, flag);
		pop_elements(lex, state, 2);
	}
	
	printf("applay rules_io_redirect %d and go to %d \n", rule, *((int *)(*state)->data));
}
