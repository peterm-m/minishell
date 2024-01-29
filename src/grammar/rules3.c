/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:51:36 by pedromar          #+#    #+#             */
/*   Updated: 2024/01/29 20:02:12 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
simple_command   : cmd_prefix WORD cmd_suffix (rule 15)
                 | cmd_prefix WORD            (rule 16)
                 | cmd_prefix                 (rule 17)
                 |            WORD cmd_suffix (rule 18)
                 |            WORD            (rule 19)
*/

void	rules_simple_cmd1(t_dlst **lex, t_state **state, int rule)
{
	dbg("rule %d\n", rule);
	t_element	*elem1;
	t_element	*elem2;

	if (rule == 15)
	{
		//elem1 = (*lex)->prev->prev->data;
		//elem2 = (*lex)->data;
		//(*lex)->data = make_simple(elem1, ((*lex)->prev->data), elem2);
		pop_elements(lex, state, 2);
	}
	else if (rule == 16)
	{
		//elem1 = (*lex)->prev->data;
		//(*lex)->data = make_simple(elem1, ((*lex)->data), NULL);
		pop_elements(lex, state, 1);
	}
	//else if (rule == 17)
	//{
	//	elem1 = (*lex)->data;
	//	(*lex)->data = make_simple(elem1, NULL, NULL);
	//}
}

void	rules_simple_cmd2(t_dlst **lex, t_state **state, int rule)
{
	dbg("rule %d\n", rule);
	t_element	*elem2;

	if (rule == 18)
	{
		//elem2 = (*lex)->data;
		//(*lex)->data = make_simple(NULL, ((*lex)->prev->data), elem2);
		pop_elements(lex, state, 1);
	}
	else if (rule == 19)
		(*lex)->data = make_simple(NULL, ((*lex)->data), NULL);
}

/*
cmd_prefix       :            io_redirect     (rule 20)
                 | cmd_prefix io_redirect     (rule 21)
                 |            ASSIGNMENT_WORD (rule 22)
                 | cmd_prefix ASSIGNMENT_WORD (rule 23)
*/

void	rules_cmd_prefix(t_dlst **lex, t_state **state, int rule)
{
	dbg("rule %d\n", rule);
	t_element	elem1;
	t_element	elem2;

	if (rule == 20)
		(void) 0;// (*lex)->data = make_element(NULL, (*lex)->data);
	else if (rule == 21)
	{
		//elem1.redirect = (*lex)->prev->data;
		//elem2.redirect = (*lex)->data;
		//(*lex)->data = join_redir(elem1.redirect, elem2.redirect);
		pop_elements(lex, state, 1);
	}
	else if (rule == 22)
		(void) 0;//(*lex)->data = make_element((*lex)->data, NULL);
	else if (rule == 23)
	{
		//elem1.word = (*lex)->prev->data;
		//elem2.word = make_word((*lex)->data);
		//(*lex)->data = join_word(elem1.word, elem2.word);
		pop_elements(lex, state, 1);
	}
}
/*
cmd_suffix       :            io_redirect (rule 24)
                 | cmd_suffix io_redirect (rule 25)
                 |            WORD        (rule 26)
                 | cmd_suffix WORD        (rule 27)
*/

void	rules_cmd_suffix(t_dlst **lex, t_state **state, int rule)
{
	dbg("rule %d\n", rule);
	t_element	elem1;
	t_element	elem2;

	if (rule == 24)
		(void)0; //(*lex)->data = make_element(NULL, (*lex)->data);
	else if (rule == 25)
	{
		//elem1.redirect = (*lex)->prev->data;
		//elem2.redirect = (*lex)->data;
		//(*lex)->data = join_redir(elem1.redirect, elem2.redirect);
		pop_elements(lex, state, 1);
	}
	else if (rule == 26)
		(void)0;//(*lex)->data = make_element((*lex)->data, NULL);
	else if (rule == 27)
	{
		//elem1.word = (*lex)->prev->data;
		//elem2.word = make_word((*lex)->data);
		//(*lex)->data = join_word(elem1.word, elem2.word);
		pop_elements(lex, state, 1);
	}
}
