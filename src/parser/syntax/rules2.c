/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:50:36 by pedromar          #+#    #+#             */
/*   Updated: 2024/01/21 21:22:51 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
command          : simple_command                 (rule 8)
                 | compound_command               (rule 9)
                 | compound_command redirect_list (rule 10)
*/

void	rules_command(t_dlst **lex, t_state **state, int rule)
{
	t_redirect	*redir;
	t_command	*cmd;

	redir = (*lex)->data;
	cmd = (*lex)->prev->data;
	if (rule == 10)
	{
		(*lex)->data = join_command_redir(cmd, redir);
		pop_elements(lex, state, 1);
	}
}

/*
compound_command : brace_group (rule 11)
				 | subshell    (rule 12)
*/

void	rules_compound(t_dlst **lex, t_state **state, int rule)
{
	(void)lex;
	(void)state;
	(void)rule;
}

/*
brace_group      : '{' and_or '}' (rule 13)
*/

void	rules_group(t_dlst **lex, t_state **state, int rule)
{
	if (rule == 13)
	{
		(*lex)->data = make_group((*lex)->prev->data);
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
		(*lex)->data = make_subshell((*lex)->prev->data);
		pop_elements(lex, state, 2);
	}
}
