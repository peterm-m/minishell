/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_grammar5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 06:16:11 by pedro             #+#    #+#             */
/*   Updated: 2024/02/06 06:25:31 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// redirect_list :               io_redirect (rule 28) OK
// rule_nothing

// redirect_list    : redirect_list io_redirect (rule 29)

void	rule_redir_list(t_dlst **lex, t_state **state)
{dbg("│\t├─rule_redir_list%s\n", "");
	void	**out;
	t_redirect	*redirect_list;
	t_redirect	*io_redirect;

	out = &(*lex)->prev->data;
	redirect_list = (*lex)->prev->prev->data;
	io_redirect = (*lex)->prev->data;
	*out = join_redir(redirect_list, io_redirect);
	pop_elements(lex, state, 1);
}

// TODO push_heredoc
// TODO IO_NUMBERS
// TODO : LEAK provenientes de t_unit_io, no se les hace free

// io_redirect :           '<'    WORD (rule 30) // CAMBIAR POR INT LEAK

void	rule_redir1(t_dlst **lex, t_state **state)
{dbg("│\t├─rule_redir1 %s\n", "");
	void	**out;
	t_token		*word;
	t_unit_io	source;
	t_unit_io	dest;

	word = (*lex)->prev->data;
	out = &(*lex)->prev->data;
	source.dest = 1;
	dest.filename = word;
	*out = make_redirection(&source,r_input_direction, &dest, 0);
		pop_elements(lex, state, 1);
}

// io_redirect :           '>'    WORD (rule 31) // CAMBIAR POR INT  LEAKS

void	rule_redir2(t_dlst **lex, t_state **state)
{dbg("│\t├─rule_redir2 %s\n", "");
	void	**out;
	t_token		*word;
	t_unit_io	source;
	t_unit_io	dest;

	word = (*lex)->prev->data;
	out = &(*lex)->prev->data;
	source.dest = 1;
	dest.filename = word;
	*out = make_redirection(&source, r_output_direction, &dest, 0);
	pop_elements(lex, state, 1);
}

// io_redirect :           DGREAT WORD (rule 32) // CAMBIAR POR INT LEAK

void	rule_redir3(t_dlst **lex, t_state **state)
{dbg("│\t├─rule_redir3 %s\n", "");
	void	**out;
	t_token		*word;
	t_unit_io	source;
	t_unit_io	dest;

	word = (*lex)->prev->data;
	out = &(*lex)->prev->data;
	source.dest = 0;
	dest.filename = word;
	*out = make_redirection(&source, r_appending_to, &dest, 0);
	pop_elements(lex, state, 1);
}

// io_redirect : IO_NUMBER '<'    WORD (rule 33) // CAMBIAR POR INT LEAK

void	rule_redir4(t_dlst **lex, t_state **state)
{dbg("│\t├─rule_redir4 %s\n", "");
	void	**out;
	t_token		*word;
	t_token		*io_number;
	t_unit_io	source;
	t_unit_io	dest;

	out = &(*lex)->prev->data;
	word = (*lex)->prev->data;
	io_number = (*lex)->prev->prev->prev->data;
	source.filename = io_number; //TODO tokens con ints
	dest.filename = word;
	*out = make_redirection(&source, r_input_direction, &dest, 0);
	pop_elements(lex, state, 2);
}

