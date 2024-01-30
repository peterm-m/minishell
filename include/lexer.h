/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:56:58 by pedromar          #+#    #+#             */
/*   Updated: 2024/01/16 22:53:55 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "minishell.h"

// Terminals Tokens
typedef struct s_braket_count
{
	int	len;
	int	state_braket;
	int	state_brace;
}	t_braket_count;
typedef enum e_terminals
{
	tt_and_if,
	tt_or_if,
	tt_pipe,
	tt_lbrace,
	tt_rbrace,
	tt_lbraket,
	tt_rbraket,
	tt_word,
	tt_assignment_word,
	tt_less,
	tt_great,
	tt_dgreat,
	tt_io_number,
	tt_dless,
	tt_end
}	t_terminals;

# define TOK_TYPE 15

# define LEX_ERROR -1
# define PARAM_E 16
# define COMMD_SUB 32
# define WILDCARD 64
# define QUEST 128
# define EXPAND 256
typedef struct s_token
{
	char	*str;
	int		flag;
}	t_token;

//typedef enum expand
//{
//	NONE,
//	PARAM_E, //${}, $word
//	COMMD_SUB, //$()
//	WILDCARD, // *
//	QUEST, // ?
//}   expand;


// lexer.c

t_dlst	*lexer(char *read_line, t_dlst **head);

// lexer_utils.c

int is_operator(int c);
int	is_blankspace(char c);
int is_quotes(char c);
int	in_word(char c);
t_braket_count check_braces(int state, t_braket_count b_count);

// tokenize_utils.c
t_token *new_token(void);
void	set_token(char *str, int i, int j, int type, t_token *token);
t_token	*init_token(void);
void free_token(t_token *token);
void search_w_q(void *t);

// get_tokens1.c

int get_word(char *str, int i, t_token *token);
int	get_string(char *str, int i, t_token *token);
int get_dolar_type(char *str, int i);
int get_dolar(char *str, int i, t_token *token);
int get_dolar2(char *str, int i, t_token *token);

// get_tokens2.c

int get_token(char *str, int i, t_token *token);
int get_token2(char *str, int i, t_token *token);
int get_ionumber(char *str, int i, t_token *token);
int get_braket_token(char *str, int i, t_token *token);
int get_brace_token(char *str, int i, t_token *token);


// tokenize.c

t_dlst *tokenize(char *input, t_dlst **head);
int get_next_token(char *input, int i, t_token *token);

#endif