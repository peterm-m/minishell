/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:56:58 by pedromar          #+#    #+#             */
/*   Updated: 2024/02/08 01:28:44 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYNTAX_H
# define SYNTAX_H

# include "minishell.h"

// tokens in grammar
# define NUM_TOKEN 15

// non terminals in grammar 
# define NUM_NTERMINALS 13

// states in grammar
# define NUM_STATES 55

// rule in grammar
# define NUM_RULES 38

// ID state 0 and ID rule 0
# define CHR_STATE0 32
# define CHR_RULE0 87

// shift operation range
# define SHIFT0 0
# define SHIFT54 54

// reduce operations range
# define REDUCE0 55
# define REDUCE37 92

// accept operation
# define ACCEPT 93

// grammar error
# define GRAMMAR_ERROR 94
# define UNDEFINED -1

// Parser state
typedef t_dlst	t_state;

// Non terminals
typedef enum e_non_terminal
{
	nt_accept,
	nt_program,
	nt_and_or,
	nt_pipeline,
	nt_command,
	nt_simple_command,
	nt_compound_command,
	nt_redirect_list,
	nt_brace_group,
	nt_subshell,
	nt_cmd_prefix,
	nt_cmd_suffix,
	nt_io_redirect
}	t_non_terminal;

void	rule_nothing(t_dlst **lst, t_state **state);

void	rule_and_or1(t_dlst **lex, t_state **state);
void	rule_and_or2(t_dlst **lex, t_state **state);

void	rule_pipeline(t_dlst **lex, t_state **state);

void	rule_command(t_dlst **lex, t_state **state);

void	rule_group(t_dlst **lex, t_state **state);

void	rule_subshell(t_dlst **lex, t_state **state);

void	rule_simple1(t_dlst **lex, t_state **state);
void	rule_simple2(t_dlst **lex, t_state **state);
void	rule_simple3(t_dlst **lex, t_state **state);
void	rule_simple4(t_dlst **lex, t_state **state);
void	rule_simple5(t_dlst **lex, t_state **state);

void	rule_prefix1(t_dlst **lex, t_state **state);
void	rule_prefix2(t_dlst **lex, t_state **state);
void	rule_prefix3(t_dlst **lex, t_state **state);
void	rule_prefix4(t_dlst **lex, t_state **state);

void	rule_suffix1(t_dlst **lex, t_state **state);
void	rule_suffix2(t_dlst **lex, t_state **state);
void	rule_suffix3(t_dlst **lex, t_state **state);
void	rule_suffix4(t_dlst **lex, t_state **state);

void	rule_redir_list(t_dlst **lex, t_state **state);

void	rule_redir1(t_dlst **lex, t_state **state);
void	rule_redir2(t_dlst **lex, t_state **state);
void	rule_redir3(t_dlst **lex, t_state **state);
void	rule_redir4(t_dlst **lex, t_state **state);
void	rule_redir5(t_dlst **lex, t_state **state);
void	rule_redir6(t_dlst **lex, t_state **state);
void	rule_redir7(t_dlst **lex, t_state **state);
void	rule_redir8(t_dlst **lex, t_state **state);

int		table_action(int state, int token);
int		table_goto(int state, int n_terminal);
void	(*table_reduce(int rule))(t_dlst **, t_state **);
int		table_nt_generate(int rule_id);

void	pop_elements(t_dlst **lex, t_dlst **state, int n);

void	syntax(t_dlst *lex);

#endif
