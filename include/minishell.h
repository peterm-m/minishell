/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:56:58 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/17 19:07:08 by adiaz-uf         ###   ########.fr       */
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

typedef enum e_env
{
	GET,
	ADD,
	UNSET,
	CLEAN,
	INDEX
}	t_env;

#endif
