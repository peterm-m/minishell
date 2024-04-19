/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subsystem.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:56:58 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/19 17:06:51 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUBSYSTEM_H
# define SUBSYSTEM_H

# include "minishell.h"

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

char	**ft_initenv(void);
char	*ft_environ(char *parameter, int action, int index);
char	**ft_unsetenv(char *name, char **my_environ);
char	*ft_getenv(char *name, char **my_environ);
char	**ft_putenv(char *string, char **my_environ);

int		search_character(char *str, char c);

char	*get_prompt(void);
void	setup_term(void);

void	initial_signals(void);
void	wait_signals(void);
void	child_signals(void);
void	sigint_handler(int sig);

int		num_files_dir(char *name);
char	**get_file_names(char *name);

char	**list_to_argv(t_word *words);
void	clean_argv(char **arr);

char	*ft_temfile(void);

#endif
