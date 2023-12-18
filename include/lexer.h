/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:56:58 by pedromar          #+#    #+#             */
/*   Updated: 2023/12/13 20:24:46 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

typedef struct s_token t_token;
typedef struct s_dlst t_dlst;

// lexer.c

int    lexer(char *read_line);

// tokenize_utils.c

t_token *add_token(char *str, int i, int j, int type);
t_token	*init_token(void);
t_dlst	*init_list(t_dlst *list);

// lexer_utils.c

int is_token(int c);
int	is_blankspace(char c);
int is_quotes(char c);
int	in_word(char c);
void	*ft_memalloc(size_t size);

// tokenize.c

t_dlst *tokenize(char *input, t_dlst *head);
///int get_string(char *str, int i, t_token *token);
//int get_token(char *str, int i, t_token *token);

void tok_p(void *t);

#endif