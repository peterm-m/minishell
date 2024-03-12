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

// TODO push_heredoc

// POSIX RULE 34
// io_redirect : IO_NUMBER '>' WORD

void	rule_redir5(t_dlst **lex, t_state **state)
{
	void		**out;
	t_token		*word;
	t_token		*io_number;
	t_unit_io	source;
	t_unit_io	dest;

	dbg("│\t├─rule_redir5 %s\n", "");
	out = &(*lex)->prev->data;
	word = (*lex)->prev->data;
	io_number = (*lex)->prev->prev->prev->data;
	source.fd = make_number(io_number);
	dest.filename = make_filename(word);
	*out = make_redirection(&source, r_output_direction, &dest, 0);
	pop_elements(lex, state, 2);
}

// POSIX RULE 35
// io_redirect : IO_NUMBER DGREAT WORD

void	rule_redir6(t_dlst **lex, t_state **state)
{
	void		**out;
	t_token		*word;
	t_token		*io_number;
	t_unit_io	source;
	t_unit_io	dest;

	dbg("│\t├─rule_redir6 %s\n", "");
	out = &(*lex)->prev->data;
	word = (*lex)->prev->data;
	io_number = (*lex)->prev->prev->prev->data;
	source.fd = make_number(io_number);
	dest.filename = make_filename(word);
	*out = make_redirection(&source, r_appending_to, &dest, 0);
	pop_elements(lex, state, 2);
}

// POSIX RULE 36
// io_redirect :           DLESS  WORD

void	rule_redir7(t_dlst **lex, t_state **state) // CHECK
{
	void		**out;
	t_token		*word;
	t_unit_io	source;
	t_unit_io	dest;

	dbg("│\t├─rule_redir7 %s\n", "");
	out = &(*lex)->prev->data;
	word = (*lex)->prev->data;
	source.fd = STDIN_FILENO;
	dest.filename = make_filename(word);
	*out = make_redirection(&source, r_reading_until, &dest, 0);
	//TODO: push_heredoc
	pop_elements(lex, state, 1);
}

// POSIX RULE 37
// io_redirect : IO_NUMBER DLESS WORD

void	rule_redir8(t_dlst **lex, t_state **state)
{
	void		**out;
	t_token		*word;
	t_token		*io_number;
	t_unit_io	source;
	t_unit_io	dest;

	dbg("│\t├─rule_redir8 %s\n", "");
	out = &(*lex)->prev->data;
	word = (*lex)->prev->data;
	io_number = (*lex)->prev->prev->prev->data;
	source.fd = make_number(io_number);
	dest.filename = make_filename(word);
	*out = make_redirection(&source, r_reading_until, &dest, 0);
	//TODO: push_heredoc
	pop_elements(lex, state, 2);
}
