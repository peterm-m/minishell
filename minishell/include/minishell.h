/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:56:58 by pedromar          #+#    #+#             */
/*   Updated: 2024/03/11 16:32:25 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define LOGS 0

// Standar header
# include <sys/types.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>

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
# include "expansion.h"

# include "colors.h"

extern int  g_exit_status;

// Bool
# define TRUE 1
# define FALSE 0

// Path

# define MAX_PATH 4096
# define PROMPT "\e[1;95mminishell42->\e[0m"

# ifdef DEBUG
#  define ft_malloc(bytes) ft_malloc((t_reserve ){bytes,__LINE__, __FILE__ , __FUNCTION__})
# endif

int	interactive_loop(int argc, char **argv);

#endif
