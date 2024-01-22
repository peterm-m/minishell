/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:56:58 by pedromar          #+#    #+#             */
/*   Updated: 2024/01/21 20:04:26 by pedromar         ###   ########.fr       */
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

// rules in grammar
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

void	rules_accept(t_dlst **lex, t_state **state, int rule);
void	rules_program(t_dlst **lex, t_state **state, int rule);
void	rules_and_or(t_dlst **lex, t_state **state, int rule);
void	rules_pipeline(t_dlst **lex, t_state **state, int rule);
void	rules_command(t_dlst **lex, t_state **state, int rule);
void	rules_compound(t_dlst **lex, t_state **state, int rule);
void	rules_group(t_dlst **lex, t_state **state, int rule);
void	rules_subshell(t_dlst **lex, t_state **state, int rule);
void	rules_simple_cmd1(t_dlst **lex, t_state **state, int rule);
void	rules_simple_cmd2(t_dlst **lex, t_state **state, int rule);
void	rules_cmd_prefix(t_dlst **lex, t_state **state, int rule);
void	rules_cmd_suffix(t_dlst **lex, t_state **state, int rule);
void	rules_redirect_list(t_dlst **lex, t_state **state, int rule);
void	rules_io_redirect1(t_dlst **lex, t_state **state, int rule);
void	rules_io_redirect2(t_dlst **lex, t_state **state, int rule);
void	rules_io_redirect3(t_dlst **lex, t_state **state, int rule);

int		table_action(int state, int token);
int		table_goto(int state, int n_terminal);
void	(*table_reduce(int rule))(t_dlst **, t_state **, int);
int		table_nt_generate(int rule_id);

void	pop_elements(t_dlst **lex, t_dlst **state, int n);

void	syntax(t_dlst *lex);

#endif
