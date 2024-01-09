/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 20:51:01 by pedro             #+#    #+#             */
/*   Updated: 2024/01/09 21:35:29 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
accept       : program $end (rule 0)
*/

void	rules_accept(t_dlst **lex, t_state **state, int rule)
{
	(void)lex;
	(void)state;
	if (rule == 0)
		(void) 0;
}

/*
program          : and_or    (rule 1)
                 | /empty/   (rule 2)
*/

void	rules_program(t_dlst **lex, t_state **state, int rule)
{
	(void)lex;
	(void)state;
	if (rule == 1)
		(void) 0;
	else if (rule == 2)
		(void) 0;
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
		(*lex)->data = make_connection((*lex)->prev->prev->data,
			(*lex)->data, tt_and_if);
		pop_elements(lex, state, 2);
	}
	else if (rule == 5)
	{
		(*lex)->data = make_connection((*lex)->prev->prev->data,
			(*lex)->data, tt_or_if);
		pop_elements(lex, state, 2);
	}
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
		(*lex)->data = make_connection((*lex)->prev->prev->data,
			(*lex)->data, tt_pipe);
		pop_elements(lex, state, 2);
	}
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
}
