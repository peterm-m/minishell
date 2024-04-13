/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:56:58 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/13 11:54:36 by pedromar         ###   ########.fr       */
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
# include <dirent.h>

// Extern header
# include <readline/readline.h>
# include <readline/history.h>
# include <termios.h>

# include "ft_dlst.h"
# include "libft.h"
# include "wrappers.h"

// Intern header
# include "lexer.h"
# include "syntax.h"
# include "executer.h"
# include "subsystem.h"
# include "expansion.h"
# include "builtins.h"

# include "colors.h"

extern int	g_exit_status;

// Bool
# define TRUE 1
# define FALSE 0

# ifdef DEBUG
#  define ft_malloc(bytes) ft_malloc((t_reserve ){bytes,__LINE__, __FILE__ , __FUNCTION__})
# endif

#endif
