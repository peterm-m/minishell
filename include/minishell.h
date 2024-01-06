/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:56:58 by pedromar          #+#    #+#             */
/*   Updated: 2024/01/06 13:16:06 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// Standar header
# include <sys/types.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

// Extern header
# include <readline/readline.h>
# include <readline/history.h>
# include "ft_dlst.h"
# include "libft.h"
# include "wrappers.h"

// Intern header
# include "lexer.h"
# include "syntax.h"
# include "semantics.h"
# include "executer.h"
# include "subsystem.h"

// Color
# define BHBLK "\e[1;90m"
# define BHRED "\e[1;91m"
# define BHGRN "\e[1;92m"
# define BHYEL "\e[1;93m"
# define BHBLU "\e[1;94m"
# define BHMAG "\e[1;95m"
# define BHCYN "\e[1;96m"
# define BHWHT "\e[1;97m"
# define END   "\e[0m"

typedef enum identifier
{
    IO_NUMBER,
    WORD,
    PIPE,
    OR,
    AND,
    LESS,
    HEREDOC,
    REDIR,
    APPEND,
    DOLAR,
    L_BRAKET,
    R_BRAKET,
    L_BRACE,
    R_BRACE, 
}   type;

typedef enum expand
{
    NONE,
    PARAM_E, //${}, $word
    COMMD_SUB, //$()
}expand;

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef struct s_token 
{
    int     type;
    int    expand;
    char    *str;
}   t_token;

typedef struct s_data
{
    t_dlst      *lexlist;
    t_dlst      *sytxtree; //tree de syntax, creo que habría que meterlo al igual que la lista de lexer
    const char  **env;
}   t_data;

#endif
