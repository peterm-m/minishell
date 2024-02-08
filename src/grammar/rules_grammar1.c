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
{dbg("│\t├─rule_nothing%s\n", "");
	(void )lst;
	(void)state;
}

// accept       : program $end (rule 0) OK
// rule_nothing

// program: and_or (rule 1) OK
// rule_nothing

// program: ε (rule 2) OK
// rule_nothing

//and_or : pipeline (rule 3) OK
//	rule_nothing

//and_or : and_or AND_IF pipeline (rule 4) TODO: error en lexer

void	rule_and_or1(t_dlst **lex, t_state **state)
{dbg("│\t├─rule_and_or1%s\n", "");
	void		**out;
	t_command	*pipeline;
	t_command	*and_or;

	out = &(*lex)->prev->data;
	pipeline = (*lex)->prev->data;
	and_or = (*lex)->prev->prev->prev->data;
	*out = make_connection(and_or, pipeline, tt_and_if);
	pop_elements(lex, state, 2);
}

//and_or : and_or OR_IF  pipeline (rule 5) OK

void	rule_and_or2(t_dlst **lex, t_state **state)
{dbg("│\t├─rule_and_or2%s\n", "");
	void		**out;
	t_command	*pipeline;
	t_command	*and_or;

	out = &(*lex)->prev->data;
	pipeline = (*lex)->prev->data;
	and_or = (*lex)->prev->prev->prev->data;
	*out = make_connection(and_or, pipeline, tt_or_if);
	pop_elements(lex, state, 2);
}

//pipeline : command              (rule 6) OK
//	rule_nothing

//pipeline : pipeline '|' command (rule 7) OK

void	rule_pipeline(t_dlst **lex, t_state **state)
{dbg("│\t├─rule_pipeline%s\n", "");
	void		**out;
	t_command	*command;
	t_command	*pipeline;

	out = &(*lex)->prev->data;
	command = (*lex)->prev->data;
	pipeline = (*lex)->prev->prev->prev->data;
	*out = make_connection(pipeline, command, tt_pipe);
	pop_elements(lex, state, 2);
}

//command  : simple_command                 (rule 8) OK
//	rule_nothing

//command  : compound_command               (rule 9) OK
//	rule_nothing

//command  : compound_command redirect_list (rule 10)

void	rule_command(t_dlst **lex, t_state **state)
{dbg("│\t├─rule_command%s\n", "");
	void		**out;
	t_redirect	*redirect_list;
	t_command	*compound_command;

	out = &(*lex)->prev->data;
	redirect_list = (*lex)->prev->data;
	compound_command = (*lex)->prev->prev->data;
	*out = join_command_redir(compound_command, redirect_list);
	pop_elements(lex, state, 1);
}
