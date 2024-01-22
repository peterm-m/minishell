/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 20:51:01 by pedro             #+#    #+#             */
/*   Updated: 2024/01/21 21:21:50 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
accept       : program $end (rule 0)
*/

// TODO: dejar solo un nodeo en la lista que sea lo que hay que ejecutar

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

// TODO: comprobar los empty

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
	if (rule == 4)
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
