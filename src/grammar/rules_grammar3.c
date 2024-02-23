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

// simple_command :            WORD cmd_suffix (rule 18) OK

void	rule_simple4(t_dlst **lex, t_state **state)
{dbg("│\t├─rule_simple4%s\n", "");
	void	**out;
	void	*cmd_suffix;
	void	*word;

	out = &(*lex)->prev->data;
	cmd_suffix = (*lex)->prev->data;
	word = (*lex)->prev->prev->data;
	*out = make_simple(NULL, make_word(word), cmd_suffix);
	pop_elements(lex, state, 1);
}

// simple_command :            WORD            (rule 19) OK

void	rule_simple5(t_dlst **lex, t_state **state)
{dbg("│\t├─rule_simple5%s\n", "");
	void	**out;
	void	*word;

	(void)state;
	out = &(*lex)->prev->data;
	word = (*lex)->prev->data;
	*out = make_simple(NULL, make_word(word), NULL);
}

// cmd_prefix :            io_redirect     (rule 20) FIX: leak

void	rule_prefix1(t_dlst **lex, t_state **state)
{dbg("│\t├─rule_prefix1 %s\n", "");
	void	**out;
	void	*io_redirect;

	(void)state;
	out = &(*lex)->prev->data;
	io_redirect = (*lex)->prev->data;
	*out = make_element(NULL, io_redirect);
}

// cmd_prefix : cmd_prefix io_redirect     (rule 21) FIX: segmentation

void	rule_prefix2(t_dlst **lex, t_state **state)
{dbg("│\t├─rule_prefix2 %s\n", "");
	void	**out;
	t_element	*cmd_prefix;
	t_redirect	*io_redirect;

	out = &(*lex)->prev->data;
	io_redirect = (*lex)->prev->data;
	cmd_prefix = (*lex)->prev->prev->data;
	join_redir(&(cmd_prefix->redirect), io_redirect);
	*out = cmd_prefix;
	pop_elements(lex, state, 1);
}

// cmd_prefix :            ASSIGNMENT_WORD (rule 22) OK

void	rule_prefix3(t_dlst **lex, t_state **state)
{dbg("│\t├─rule_prefix3 %s\n", "");
	void	**out;
	void		*assignment_word;
	
	(void)state;
	out = &(*lex)->prev->data;
	assignment_word = (*lex)->prev->data;
	*out = make_element(make_word(assignment_word), NULL);
}
