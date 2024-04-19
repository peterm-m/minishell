/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:56:58 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/19 17:06:30 by pedromar         ###   ########.fr       */
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

# include "wrappers.h"
# include "ft_dlst.h"
# include "libft.h"

// Intern header
# include "lexer.h"
# include "syntax.h"
# include "executer.h"
# include "subsystem.h"
# include "expansion.h"
# include "builtins.h"

# include "colors.h"

extern int	g_exit_status;

#endif
