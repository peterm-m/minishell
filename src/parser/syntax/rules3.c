/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:51:36 by pedromar          #+#    #+#             */
/*   Updated: 2024/01/15 21:15:03 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
		(void) 0;//(*lex)->data = make_element(NULL, NULL);
	else if (rule == 25)
	{
		//join_redir(&((t_element *)((*lex)->prev->data))->redirect,
		//	(*lex)->data);
		pop_elements(lex, state, 1);
	}
	else if (rule == 26)
		(void) 0;//(*lex)->data = make_element(make_word(((t_token *)(*lex)->data)->str) ,NULL);
	else if (rule == 27)
	{
		//join_word(&((t_element *)((*lex)->prev->data))->word, (*lex)->data);
		pop_elements(lex, state, 1);
	}
}

/*
redirect_list    :               io_redirect (rule 28)
                 | redirect_list io_redirect (rule 29)
*/

void	rules_redirect_list(t_dlst **lex, t_state **state, int rule)
{
	//t_redirect	*redir2;

	//redir1 = (t_redirect *)(*lex)->prev->data;
	//redir2 = (t_redirect *)(*lex)->data;
	if (rule == 29)
	{
		//join_redir(&redir1, redir2);
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

// TODO: push_heredoc

void	rules_io_redirect(t_dlst **lex, t_state **state, int rule)
{
	t_unit_io	source;
	t_unit_io	dest;

	if (rule == 30)
	{
		source.dest = "0";
		dest.filename = ((t_token *)((*lex)->data))->str;
		(*lex)->data = make_redirection(&source, r_input_direction, &dest, 0);
		pop_elements(lex, state, 1);
	}
	else if (rule == 31)
	{
		source.dest = "1";
		dest.filename = ((t_token *)((*lex)->data))->str;
		(*lex)->data = make_redirection(&source, r_output_direction, &dest, 0);
		pop_elements(lex, state, 1);
	}
	else if (rule == 32)
	{
		source.dest = "0";
		dest.filename = ((t_token *)((*lex)->data))->str;
		(*lex)->data = make_redirection(&source, r_appending_to, &dest, 0);
		pop_elements(lex, state, 1);
	}
	else if (rule == 33)
	{
		source.dest = ((t_token *)((*lex)->prev->prev->data))->str;
		dest.filename = ((t_token *)((*lex)->data))->str;
		(*lex)->data = make_redirection(&source, r_input_direction, &dest, 0);
		pop_elements(lex, state, 2);
	}
	else if (rule == 34)
	{
		source.dest = ((t_token *)((*lex)->prev->prev->data))->str;
		dest.filename = ((t_token *)((*lex)->data))->str;
		(*lex)->data = make_redirection(&source, r_output_direction, &dest, 0);
		pop_elements(lex, state, 2);
	}
	else if (rule == 35)
	{
		source.dest = ((t_token *)((*lex)->prev->prev->data))->str;
		dest.filename = ((t_token *)((*lex)->data))->str;
		(*lex)->data = make_redirection(&source, r_appending_to, &dest, 0);
		pop_elements(lex, state, 2);
	}
	else if (rule == 36)
	{
		source.dest = "0";
		dest.filename = ((t_token *)((*lex)->data))->str;
		(*lex)->data = make_redirection(&source, r_reading_until, &dest, 0);
		// push_heredoc
		pop_elements(lex, state, 1);
	}
	else if (rule == 37)
	{
		source.dest = ((t_token *)((*lex)->prev->prev->data))->str;
		dest.filename = ((t_token *)((*lex)->data))->str;
		(*lex)->data = make_redirection(&source, r_reading_until, &dest, 0);
		// push_heredoc
		pop_elements(lex, state, 2);
	}
}
