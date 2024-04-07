/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:50:36 by pedromar          #+#    #+#             */
/*   Updated: 2024/02/06 06:20:50 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// POSIX RULE 11
// compound_command : brace_group 

// POSIX RULE 12
// compound_command : subshell 

// POSIX RULE 13
// brace_group : '{' and_or '}'

void	rule_group(t_dlst **lex, t_state **state)
{
	void	**out;
	void	*and_or;

	dbg("│\t├─rule_group%s\n", "");
	out = &(*lex)->prev->data;
	and_or = (*lex)->prev->prev->data;
	*out = make_group(and_or);
	pop_elements(lex, state, 2);
}

// POSIX RULE 14
// subshell : '(' and_or ')'

void	rule_subshell(t_dlst **lex, t_state **state)
{
	void	**out;
	void	*and_or;

	dbg("│\t├─rule_subshell%s\n", "");
	out = &(*lex)->prev->data;
	and_or = (*lex)->prev->prev->data;
	*out = make_subshell(and_or);
	pop_elements(lex, state, 2);
}

// POSIX RULE 15
// simple_command : cmd_prefix WORD cmd_suffix

void	rule_simple1(t_dlst **lex, t_state **state)
{
	void		**out;
	t_element	*cmd_prefix;
	t_element	*cmd_suffix;
	void		*word;

	dbg("│\t├─rule_simple1 %s\n", "");
	out = &(*lex)->prev->data;
	cmd_prefix = (*lex)->prev->prev->prev->data;
	word = (*lex)->prev->prev->data;
	cmd_suffix = (*lex)->prev->data;
	*out = make_simple(cmd_prefix, make_word(word), cmd_suffix);
	pop_elements(lex, state, 2);
}

// POSIX RULE 16
// simple_command : cmd_prefix WORD

void	rule_simple2(t_dlst **lex, t_state **state)
{
	void	**out;
	void	*cmd_prefix;
	void	*word;

	dbg("│\t├─rule_simple2 %s\n", "");
	out = &(*lex)->prev->data;
	word = (*lex)->prev->data;
	cmd_prefix = (*lex)->prev->prev->data;
	*out = make_simple(cmd_prefix, word, NULL);
	pop_elements(lex, state, 1);
}

// POSIX RULE 17
// simple_command : cmd_prefix

void	rule_simple3(t_dlst **lex, t_state **state)
{
	void		**out;
	t_element	*cmd_prefix;

	dbg("│\t├─rule_simple3 %s\n", "");
	(void)state;
	out = &(*lex)->prev->data;
	cmd_prefix = (*lex)->prev->data;
	*out = make_simple(cmd_prefix, NULL, NULL);
}
