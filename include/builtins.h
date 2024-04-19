/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:48:36 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/19 17:36:57 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"

int		cd_main(char **argv, int fd);
int		echo_main(char **argv, int fd);
int		env_main(char **argv, int fd);
int		exit_main(char **argv, int fd);
int		export_main(char **argv, int fd);
int		pwd_main(char **argv, int fd);
int		unset_main(char **argv, int fd);

// UTILS
int		get_arr_len(char **env);
void	sort_env(void);

#endif