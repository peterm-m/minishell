/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:26:54 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/02 20:53:05 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int is_builtin(char *str)
{
	if (ft_strncmp(str, "cd", 3) == 0)
		return (1);
	else if (ft_strncmp(str, "echo", 5) == 0)
		return (1);
	else if (ft_strncmp(str, "env", 4) == 0)
		return (1);
	else if (ft_strncmp(str, "exit", 5) == 0)
		return (1);
	else if (ft_strncmp(str, "export", 7) == 0)
		return (1);
	else if (ft_strncmp(str, "pwd", 4) == 0)
		return (1);
	else if (ft_strncmp(str, "unset", 6) == 0)
		return (1);
	return (0);
}

// TODO: He leido que las built in no se ejecutan en un proces por separado.
//	Por tanto no hay que hacer un fork
//		IMPLEMENTAR:
//			Las redirecciones no se hacen con dup2 cambiando la salida por el archivo
//			Creo que lo mas facil es que los print o cualquier salida la cambies por
//			writes que envien la salida al archivo


int	execute_builtin(t_word_list *words, int fd_in, int fd_out)
{
	char	**argv;
	int 	fd = 1; // TODO: Cambiar

	argv = list_to_arr(words);
	if (ft_strncmp(argv[0], "cd", 3) == 0)
		return (cd_main(argv, fd_in));
	else if (ft_strncmp(argv[0], "echo", 5) == 0)
		return (echo_main(argv, fd_in));
	else if (ft_strncmp(argv[0], "env", 4) == 0)
		return (env_main(fd_in));
	else if (ft_strncmp(argv[0], "exit", 5) == 0)
		return (exit_main(argv));
	else if (ft_strncmp(argv[0], "export", 7) == 0)
		return (export_main(argv, fd_in));
	else if (ft_strncmp(argv[0], "pwd", 4) == 0)
		return (pwd_main(fd_in));
	else if (ft_strncmp(argv[0], "unset", 6) == 0)
		return (unset_main(argv));
	return (-1);
}