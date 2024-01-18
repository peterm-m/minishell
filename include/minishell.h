/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:56:58 by pedromar          #+#    #+#             */
/*   Updated: 2024/01/18 22:42:26 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// conditional
# ifdef DEBUG
    # define dbg(fmt, ...) \
			do { if (DEBUG) fprintf(stderr,  "%s:%d:%s(): " fmt, __FILE__,\
			__LINE__, __func__, __VA_ARGS__); } while (0)
#endif

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

//typedef enum e_bool
//{
//	FALSE,
//	TRUE
//}	t_bool;
//
typedef struct s_data
{
    t_dlst      *lexlist;
    t_dlst      *sytxtree; //tree de syntax, creo que habría que meterlo al igual que la lista de lexer
    const char  **env;
}   t_data;

#endif
