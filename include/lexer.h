/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:56:58 by pedromar          #+#    #+#             */
/*   Updated: 2023/12/17 13:57:16 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

typedef struct s_token t_token;
typedef struct s_dlst t_dlst;

// lexer.c

t_dlst	*lexer(char *read_line, t_dlst **head);

// lexer_utils.c

int is_token(int c);
int	is_blankspace(char c);
int is_quotes(char c);
int	in_word(char c);
void	*ft_memalloc(size_t size);

// tokenize_utils.c

t_token *add_token(char *str, int i, int j, int type);
t_token	*init_token(void);
void free_list(void *head);

// get_tokens.c

int get_word(char *str, int i, t_dlst **head);
int get_string(char *str, int i, t_dlst **head);
int get_dolar_type(char *str, int i);
int get_dolar(char *str, int i, t_dlst **head);
int get_dolar2(char *str, int i, t_dlst **head, int type);

// tokenize.c

t_dlst *tokenize(char *input, t_dlst **head);
int get_token(char *str, int i, t_dlst **head);
int get_token2(char *str, int i, t_dlst **head);
int get_next_token(char *input, int i, t_dlst **head);
int get_ionumber(char *str, int i, t_dlst **head);

#endif