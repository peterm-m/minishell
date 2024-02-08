/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 06:16:47 by pedro             #+#    #+#             */
/*   Updated: 2024/02/06 06:24:13 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// io_redirect : IO_NUMBER '>' WORD (rule 34) // CAMBIAR POR INT LEAK

void	rule_redir5(t_dlst **lex, t_state **state)
{dbg("│\t├─rule_redir5 %s\n", "");
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
	*out = make_redirection(&source, r_output_direction, &dest, 0);
	pop_elements(lex, state, 2);
}

// io_redirect : IO_NUMBER DGREAT WORD (rule 35) // CAMBIAR POR INT LEAK

void	rule_redir6(t_dlst **lex, t_state **state)
{dbg("│\t├─rule_redir6 %s\n", "");
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
	*out = make_redirection(&source, r_appending_to, &dest, 0);
	pop_elements(lex, state, 2);
}

// io_redirect :           DLESS  WORD (rule 36) // CAMBIAR POR INT LEAK

void	rule_redir7(t_dlst **lex, t_state **state)
{dbg("│\t├─rule_redir7 %s\n", "");
	void	**out;
	t_token		*word;
	t_unit_io	source;
	t_unit_io	dest;

	out = &(*lex)->prev->data;
	word = (*lex)->prev->data;
	source.dest = 0;
	dest.filename = word;
	*out = make_redirection(&source, r_reading_until, &dest, 0);
	// push_heredoc
	pop_elements(lex, state, 1);
}

// io_redirect : IO_NUMBER DLESS  WORD (rule 37) // CAMBIAR POR INT LEAK

void	rule_redir8(t_dlst **lex, t_state **state)
{dbg("│\t├─rule_redir8 %s\n", "");
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
	*out = make_redirection(&source, r_reading_until, &dest, 0);
	// push_heredoc
	pop_elements(lex, state, 2);
}
