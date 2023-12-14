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

<<<<<<< HEAD
// lexer.c

int    lexer(char *read_line);
=======
int	lexer(char *read_line);
>>>>>>> 6766b907b9d77a199826d4821e1a2884437f300c

// tokenize_utils.c

int is_token(int c);
int	is_blankspace(char c);
int is_quotes(char c);

// tokenize.c

int tokenize(char *read_line);
int get_string(char *str);
int get_token(char *str);

#endif