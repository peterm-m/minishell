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

// compound_command : brace_group (rule 11)
//	rule_nothing

// compound_command : subshell (rule 12)
//	rule_nothing

// brace_group : '{' and_or '}' (rule 13) TODO: Error en lexer

void	rule_group(t_dlst **lex, t_state **state)
{dbg("│\t├─rule_group%s\n", "");
	void	**out;
	void	*and_or;

	out = &(*lex)->prev->data;
	and_or = (*lex)->prev->prev->data;
	*out = make_group(and_or);
	pop_elements(lex, state, 2);
}

// subshell : '(' and_or ')' (rule 14) TODO: Error en lexer

void	rule_subshell(t_dlst **lex, t_state **state)
{dbg("│\t├─rule_subshell%s\n", "");
	void	**out;
	void	*and_or;

	out = &(*lex)->prev->data;
	and_or = (*lex)->prev->prev->data;
	*out = make_subshell(and_or);
	pop_elements(lex, state, 2);
}

// simple_command : cmd_prefix WORD cmd_suffix (rule 15) FIX: Segmentation

void	rule_simple1(t_dlst **lex, t_state **state)
{dbg("│\t├─rule_simple1 %s\n", "");
	void		**out;
	t_element	*cmd_prefix;
	t_element	*cmd_suffix;
	void		*word;

	out = &(*lex)->prev->data;
	cmd_prefix = (*lex)->prev->prev->prev->data;
	word = (*lex)->prev->prev->data;
	cmd_suffix = (*lex)->prev->data;
	*out = make_simple(cmd_prefix, make_word(word), cmd_suffix);
	pop_elements(lex, state, 2);
}

// simple_command : cmd_prefix WORD            (rule 16)

void	rule_simple2(t_dlst **lex, t_state **state)
{dbg("│\t├─rule_simple2 %s\n", "");
	void	**out;
	void	*cmd_prefix;
	void	*word;

	out = &(*lex)->prev->data;
	word = (*lex)->prev->data;
	cmd_prefix = (*lex)->prev->prev->data;
	*out = make_simple(cmd_prefix, word, NULL);
	pop_elements(lex, state, 1);
}

// simple_command : cmd_prefix                 (rule 17) FIX: leak

void	rule_simple3(t_dlst **lex, t_state **state)
{dbg("│\t├─rule_simple3 %s\n", "");
	void		**out;
	t_element	*cmd_prefix;

	(void)state;
	out = &(*lex)->prev->data;
	cmd_prefix = (*lex)->prev->data;
	*out = make_simple(cmd_prefix, NULL, NULL);
}
