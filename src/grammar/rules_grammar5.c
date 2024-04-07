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

// TODO push_heredoc
// TODO : LEAK de redirecciones que no tiene io_number

// POSIX RULE 28
// redirect_list : io_redirect

// POSIX RULE 29
// redirect_list : redirect_list io_redirect

void	rule_redir_list(t_dlst **lex, t_state **state)
{
	void		**out;
	t_redirect	*redirect_list;
	t_redirect	*io_redirect;

	dbg("│\t├─rule_redir_list%s\n", "");
	(void) out;
	out = &(*lex)->prev->data;
	redirect_list = (*lex)->prev->prev->data;
	io_redirect = (*lex)->prev->data;
	join_redir(&redirect_list, io_redirect);
	pop_elements(lex, state, 1);
}

// POSIX RULE 30
// io_redirect : '<' WORD

void	rule_redir1(t_dlst **lex, t_state **state)
{
	void		**out;
	t_token		*word;
	t_unit_io	source;
	t_unit_io	dest;

	dbg("│\t├─rule_redir1 %s\n", "");
	word = (*lex)->prev->data;
	out = &(*lex)->prev->data;
	source.fd = STDOUT_FILENO;
	dest.filename = make_filename(word);
	*out = make_redirection(&source, r_input_direction, &dest, 0);
	pop_elements(lex, state, 1);
}

// POSIX RULE 31
// io_redirect : '>' WORD

void	rule_redir2(t_dlst **lex, t_state **state)
{
	void		**out;
	t_token		*word;
	t_unit_io	source;
	t_unit_io	dest;

	dbg("│\t├─rule_redir2 %s\n", "");
	out = &(*lex)->prev->data;
	word = (*lex)->prev->data;
	source.fd = STDOUT_FILENO;
	dest.filename = make_filename(word);
	*out = make_redirection(&source, r_output_direction, &dest, 0);
	pop_elements(lex, state, 1);
}

// POSIX RULE 32
// io_redirect :  DGREAT WORD

void	rule_redir3(t_dlst **lex, t_state **state)
{
	void		**out;
	t_token		*word;
	t_unit_io	source;
	t_unit_io	dest;

	dbg("│\t├─rule_redir3 %s\n", "");
	out = &(*lex)->prev->data;
	word = (*lex)->prev->data;
	source.fd = STDOUT_FILENO;
	dest.filename = make_filename(word);
	*out = make_redirection(&source, r_appending_to, &dest, 0);
	pop_elements(lex, state, 1);
}

// POSIX RULE 33
// io_redirect : IO_NUMBER '<' WORD

void	rule_redir4(t_dlst **lex, t_state **state)
{
	void		**out;
	t_token		*word;
	t_token		*io_number;
	t_unit_io	source;
	t_unit_io	dest;

	dbg("│\t├─rule_redir4 %s\n", "");
	out = &(*lex)->prev->data;
	word = (*lex)->prev->data;
	io_number = (*lex)->prev->prev->prev->data;
	source.fd = make_number(io_number);
	dest.filename = make_filename(word);
	*out = make_redirection(&source, r_input_direction, &dest, 0);
	pop_elements(lex, state, 2);
}
