/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:51:36 by pedromar          #+#    #+#             */
/*   Updated: 2024/02/06 06:21:28 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#undef LOGS 
#define LOGS 0
// POSIX RULE 18
// simple_command : WORD cmd_sufix

void	rule_simple4(t_dlst **lex, t_state **state)
{
	void	**out;
	void	*cmd_suffix;
	void	*word;

	dbg("│\t├─rule_simple4%s\n", "");
	out = &(*lex)->prev->data;
	cmd_suffix = (*lex)->prev->data;
	word = (*lex)->prev->prev->data;
	*out = make_simple(NULL, make_word(word), cmd_suffix);
	pop_elements(lex, state, 1);
}

// POSIX RULE 19
// simple_command : WORD

void	rule_simple5(t_dlst **lex, t_state **state)
{
	void	**out;
	void	*word;

	dbg("│\t├─rule_simple5%s\n", "");
	(void)state;
	out = &(*lex)->prev->data;
	word = (*lex)->prev->data;
	*out = make_simple(NULL, make_word(word), NULL);
}

// POSIX RULE 20
// cmd_prefix : io_redirect

void	rule_prefix1(t_dlst **lex, t_state **state)
{
	void	**out;
	void	*io_redirect;

	dbg("│\t├─rule_prefix1 %s\n", "");
	(void)state;
	out = &(*lex)->prev->data;
	io_redirect = (*lex)->prev->data;
	*out = make_element(NULL, io_redirect);
}

// POSIX RULE 21
// cmd_prefix : cmd_prefix io_redirect

void	rule_prefix2(t_dlst **lex, t_state **state)
{
	void		**out;
	t_element	*cmd_prefix;
	t_redirect	*io_redirect;

	dbg("│\t├─rule_prefix2 %s\n", "");
	out = &(*lex)->prev->data;
	io_redirect = (*lex)->prev->data;
	cmd_prefix = (*lex)->prev->prev->data;
	join_redir(&(cmd_prefix->redirect), io_redirect);
	*out = cmd_prefix;
	pop_elements(lex, state, 1);
}

// POSIX RULE 22
// cmd_prefix : ASSIGNMENT_WORD

void	rule_prefix3(t_dlst **lex, t_state **state)
{
	void	**out;
	void	*assignment_word;

	dbg("│\t├─rule_prefix3 %s\n", "");
	(void)state;
	out = &(*lex)->prev->data;
	assignment_word = (*lex)->prev->data;
	*out = make_element(make_word(assignment_word), NULL);
}
