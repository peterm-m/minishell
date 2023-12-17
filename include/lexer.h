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

// lexer.c

int    lexer(char *read_line);

// tokenize_utils.c

int is_token(int c);
int	is_blankspace(char c);
int is_quotes(char c);

// tokenize.c

int tokenize(char *read_line);
int get_string(char *str);
int get_token(char *str);

#endif