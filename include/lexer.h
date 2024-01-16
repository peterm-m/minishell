/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:56:58 by pedromar          #+#    #+#             */
/*   Updated: 2024/01/16 21:26:18 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "minishell.h"

// Terminals Tokens

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

int is_token(int c);
int	is_blankspace(char c);
int is_quotes(char c);
int	in_word(char c);

// tokenize_utils.c

t_token *add_token(char *str, int i, int j, int type);
t_token	*init_token(void);
void free_token(t_token *tok);
void search_w_q(void *t);

// get_tokens.c

int get_word(char *str, int i, t_dlst **head);
int get_string(char *str, int i, t_dlst **head);
int get_dolar_type(char *str, int i);
int get_dolar(char *str, int i, t_dlst **head);
int get_dolar2(char *str, int i, t_dlst **head);

// tokenize.c

t_dlst *tokenize(char *input, t_dlst **head);
int get_token(char *str, int i, t_dlst **head);
int get_token2(char *str, int i, t_dlst **head);
int get_next_token(char *input, int i, t_dlst **head);
int get_ionumber(char *str, int i, t_dlst **head);

#endif