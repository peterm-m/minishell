/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:56:58 by pedromar          #+#    #+#             */
/*   Updated: 2023/12/13 20:24:54 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "lexer.h"
# include "syntax.h"
# include "executer.h"
# include "subsystem.h"
# include "ft_dlst.h"
# include <sys/types.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <readline/readline.h>
# include <readline/history.h>

# define BHBLK "\e[1;90m"
# define BHRED "\e[1;91m"
# define BHGRN "\e[1;92m"
# define BHYEL "\e[1;93m"
# define BHBLU "\e[1;94m"
# define BHMAG "\e[1;95m"
# define BHCYN "\e[1;96m"
# define BHWHT "\e[1;97m"
# define END "\e[0m"

# define QUOTED 0
# define WORD 1
# define IO_NUMBER 2

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
    t_dlst   **list;
}   t_data;

#endif
