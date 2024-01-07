/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:50:36 by pedromar          #+#    #+#             */
/*   Updated: 2024/01/07 19:32:15 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
compound_command : brace_group (rule 11)
				 | subshell    (rule 12)
*/

void	rules_compound(t_dlst **lex, t_state **state, int rule)
{
	(void)lex;
	(void)state;
	if (rule == 11)
		(void) 0;
	else if (rule == 12)
		(void) 0;
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
}
