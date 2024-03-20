/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:26:54 by pedromar          #+#    #+#             */
/*   Updated: 2024/03/20 20:55:25 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execute_builtin(t_word_list *words)
{
	char	**argv;

	argv = list_to_arr(words);
	if (ft_strncmp(argv[0], "cd", 3) == 0)
		return (cd_main(argv));
	else if (ft_strncmp(argv[0], "echo", 5) == 0) // ECHO OK
		return (echo_main(argv));
	else if (ft_strncmp(argv[0], "env", 4) == 0) // ENV OK
		return (env_main());
	else if (ft_strncmp(argv[0], "exit", 5) == 0) // EXIT OK
		return (exit_main(argv));
	else if (ft_strncmp(argv[0], "export", 7) == 0)
		return (export_main(argv));
	else if (ft_strncmp(argv[0], "pwd", 4) == 0) // PWD OK
		return (pwd_main());
	else if (ft_strncmp(argv[0], "unset", 6) == 0)
		return (unset_main(argv));
	return (-1);
}
