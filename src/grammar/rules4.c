/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:05:12 by pedromar          #+#    #+#             */
/*   Updated: 2024/01/24 21:17:07 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
redirect_list    :               io_redirect (rule 28)
                 | redirect_list io_redirect (rule 29)
*/

void	rules_redirect_list(t_dlst **lex, t_state **state, int rule)
{
	dbg("rule %d\n", rule);
	t_redirect	*redir1;
	t_redirect	*redir2;

	redir1 = (t_redirect *)(*lex)->prev->data;
	redir2 = (t_redirect *)(*lex)->data;
	if (rule == 29)
	{
		redir2 = join_redir(redir1, redir2);
		pop_elements(lex, state, 1);
	}
}

/*
io_redirect      :           '<'    WORD (rule 30) // CAMBIAR POR INT
                 |           '>'    WORD (rule 31) // CAMBIAR POR INT
                 |           DGREAT WORD (rule 32) // CAMBIAR POR INT
                 | IO_NUMBER '<'    WORD (rule 33) // CAMBIAR POR INT
                 | IO_NUMBER '>'    WORD (rule 34) // CAMBIAR POR INT
                 | IO_NUMBER DGREAT WORD (rule 35) // CAMBIAR POR INT
                 |           DLESS  WORD (rule 36) // CAMBIAR POR INT
                 | IO_NUMBER DLESS  WORD (rule 37) // CAMBIAR POR INT
*/

// TODO push_heredoc
// TODO IO_NUMBERS

void	rules_io_redirect1(t_dlst **lex, t_state **state, int rule)
{
	dbg("rule %d\n", rule);
	t_unit_io	source;
	t_unit_io	dest;

	if (rule == 30)
	{
		source.dest = 0;
		dest.filename = (*lex)->data;
		(*lex)->data = make_redirection(&source, r_input_direction, &dest, 0);
		pop_elements(lex, state, 1);
	}
	else if (rule == 31)
	{
		source.dest = 1;
		dest.filename = ((*lex)->data);
		(*lex)->data = make_redirection(&source, r_output_direction, &dest, 0);
		pop_elements(lex, state, 1);
	}
	else if (rule == 32)
	{
		source.dest = 0;
		dest.filename = (*lex)->data;
		(*lex)->data = make_redirection(&source, r_appending_to, &dest, 0);
		pop_elements(lex, state, 1);
	}
}

void	rules_io_redirect2(t_dlst **lex, t_state **state, int rule)
{
	dbg("rule %d\n", rule);
	t_unit_io	source;
	t_unit_io	dest;

	if (rule == 33)
	{
		source.filename = (*lex)->prev->prev->data; //TODO tokens con ints
		dest.filename = (*lex)->data;
		(*lex)->data = make_redirection(&source, r_input_direction, &dest, 0);
		pop_elements(lex, state, 2);
	}
	else if (rule == 34)
	{
		source.filename = (*lex)->prev->prev->data; //TODO tokens con ints
		dest.filename = (*lex)->data;
		(*lex)->data = make_redirection(&source, r_output_direction, &dest, 0);
		pop_elements(lex, state, 2);
	}
	else if (rule == 35)
	{
		source.filename = (*lex)->prev->prev->data; //TODO tokens con ints
		dest.filename = (*lex)->data;
		(*lex)->data = make_redirection(&source, r_appending_to, &dest, 0);
		pop_elements(lex, state, 2);
	}
}

void	rules_io_redirect3(t_dlst **lex, t_state **state, int rule)
{
	dbg("rule %d\n", rule);
	t_unit_io	source;
	t_unit_io	dest;

	if (rule == 36)
	{
		source.dest = 0;
		dest.filename = (*lex)->data;
		(*lex)->data = make_redirection(&source, r_reading_until, &dest, 0);
		// push_heredoc
		pop_elements(lex, state, 1);
	}
	else if (rule == 37)
	{
		source.filename = (*lex)->prev->prev->data; //TODO tokens con ints
		dest.filename = (*lex)->data;
		(*lex)->data = make_redirection(&source, r_reading_until, &dest, 0);
		// push_heredoc
		pop_elements(lex, state, 2);
	}
}
