/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:51:36 by pedromar          #+#    #+#             */
/*   Updated: 2024/01/07 18:54:11 by pedromar         ###   ########.fr       */
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
		(void) 0;
	else if (rule == 25)
		pop_elements(lex, state, 1);
	else if (rule == 26)
		(void) 0;
	else if (rule == 27)
		pop_elements(lex, state, 1);
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
		pop_elements(lex, state, 1);
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
}
