/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:38:31 by pedromar          #+#    #+#             */
/*   Updated: 2024/02/06 06:13:21 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// TODO: dejar solo un nodeo en la lista que sea lo que hay que ejecutar

void	rule_nothing(t_dlst **lst, t_state **state)
{
	dbg("│\t├─rule_nothing%s\n", "");
	(void )lst;
	(void)state;
}

// POSIX RULE 0
//	accept : program $end

// POSIX RULE 1
//	program: and_or

// POSIX RULE 2
// program: <empty_string>

// POSIX RULE 3
//	and_or : pipeline

// POSIX RULE 4
//	and_or : and_or AND_IF pipeline

void	rule_and_or1(t_dlst **lex, t_state **state)
{
	void		**out;
	t_command	*pipeline;
	t_command	*and_or;

	dbg("│\t├─rule_and_or1%s\n", "");
	out = &(*lex)->prev->data;
	pipeline = (*lex)->prev->data;
	and_or = (*lex)->prev->prev->prev->data;
	*out = make_connection(and_or, pipeline, tt_and_if);
	pop_elements(lex, state, 2);
}

// POSIX RULE 5
//and_or : and_or OR_IF pipeline

void	rule_and_or2(t_dlst **lex, t_state **state)
{
	void		**out;
	t_command	*pipeline;
	t_command	*and_or;

	dbg("│\t├─rule_and_or2%s\n", "");
	out = &(*lex)->prev->data;
	pipeline = (*lex)->prev->data;
	and_or = (*lex)->prev->prev->prev->data;
	*out = make_connection(and_or, pipeline, tt_or_if);
	pop_elements(lex, state, 2);
}

// POSIX RULE 6
//pipeline : command

// POSIX RULE 7
//pipeline : pipeline '|' command

void	rule_pipeline(t_dlst **lex, t_state **state)
{
	void		**out;
	t_command	*command;
	t_command	*pipeline;

	dbg("│\t├─rule_pipeline%s\n", "");
	out = &(*lex)->prev->data;
	command = (*lex)->prev->data;
	pipeline = (*lex)->prev->prev->prev->data;
	*out = make_connection(pipeline, command, tt_pipe);
	pop_elements(lex, state, 2);
}

// POSIX RULE 8
//command  : simple_command

// POSIX RULE 9
//command  : compound_command

// POSIX RULE 10
//command  : compound_command redirect_list

void	rule_command(t_dlst **lex, t_state **state)
{
	void		**out;
	t_redirect	*redirect_list;
	t_command	*compound_command;

	dbg("│\t├─rule_command%s\n", "");
	out = &(*lex)->prev->data;
	redirect_list = (*lex)->prev->data;
	compound_command = (*lex)->prev->prev->data;
	*out = join_command_redir(compound_command, redirect_list);
	pop_elements(lex, state, 1);
}
