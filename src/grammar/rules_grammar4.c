/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:05:12 by pedromar          #+#    #+#             */
/*   Updated: 2024/02/06 06:21:47 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// cmd_prefix : cmd_prefix ASSIGNMENT_WORD (rule 23)

void	rule_prefix4(t_dlst **lex, t_state **state)
{dbg("│\t├─rule_prefix4 %s\n", "");
	void		**out;
	void		*word;
	t_element	*cmd_prefix;

	out = &(*lex)->prev->data;
	word = (*lex)->prev->data;
	cmd_prefix = (*lex)->prev->prev->data;
	*out = join_word(cmd_prefix->word, make_word(word));
	pop_elements(lex, state, 1);
}

// cmd_suffix  :            io_redirect (rule 24) OK

void	rule_suffix1(t_dlst **lex, t_state **state)
{dbg("│\t├─rule_suffix1 %s\n", "");
	void	**out;
	void	*io_redirect;

	(void)state;
	out = &(*lex)->prev->data;
	io_redirect = (*lex)->prev->data;
	*out = make_element(NULL, io_redirect);
}

// cmd_suffix  : cmd_suffix io_redirect (rule 25) OK

void	rule_suffix2(t_dlst **lex, t_state **state)
{dbg("│\t├─rule_suffix2 %s\n", "");
	void		**out;
	void		*io_redirect;
	t_element	*cmd_suffix;

	out = &(*lex)->prev->data;
	io_redirect = (*lex)->prev->data;
	cmd_suffix = (*lex)->prev->prev->data;
	cmd_suffix->redirect = join_redir(cmd_suffix->redirect, io_redirect);
	*out = cmd_suffix;
	pop_elements(lex, state, 1);
}

// cmd_suffix  :            WORD        (rule 26) OK

void	rule_suffix3(t_dlst **lex, t_state **state)
{dbg("│\t├─rule_suffix3 %s\n", "");
	void	**out;
	void	*word;

	(void)state;
	out = &(*lex)->prev->data;
	word = (*lex)->prev->data;
	*out = make_element(make_word(word), NULL);
}

// cmd_suffix  : cmd_suffix WORD        (rule 27) OK

void	rule_suffix4(t_dlst **lex, t_state **state)
{dbg("│\t├─rule_suffix4 %s\n", "");
	void		**out;
	void		*word;
	t_element	*cmd_suffix;

	out = &(*lex)->prev->data;
	word = (*lex)->prev->data;
	cmd_suffix = (*lex)->prev->prev->data;
	cmd_suffix->word = join_word(cmd_suffix->word, make_word(word));
	*out = cmd_suffix;
	pop_elements(lex, state, 1);
}
