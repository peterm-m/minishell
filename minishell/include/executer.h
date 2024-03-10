/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:56:58 by pedromar          #+#    #+#             */
/*   Updated: 2024/03/10 20:16:07 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTER_H
# define EXECUTER_H

# include "minishell.h"

typedef struct s_file_name
{
	char	file_name[NAME_MAX];
}	t_file_name;

typedef struct s_path_name
{
	char	path_name[PATH_MAX];
}	t_path_name;

void	executer(void);
//void	expander(t_data *data, char *input);

#endif