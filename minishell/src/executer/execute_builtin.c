/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:26:54 by pedromar          #+#    #+#             */
/*   Updated: 2024/03/21 18:28:53 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// TODO: He leido que las built in no se ejecutan en un proces por separado.
//	Por tanto no hay que hacer un fork
//		IMPLEMENTAR:
//			Las redirecciones no se hacen con dup2 cambiando la salida por el archivo
//			Creo que lo mas facil es que los print o cualquier salida la cambies por
//			writes que envien la salida al archivo


int	execute_builtin(t_word_list *words)
{
	char	**argv;

	argv = list_to_arr(words);
	if (ft_strncmp(argv[0], "cd", 3) == 0)
		return (cd_main(argv, fd));
	else if (ft_strncmp(argv[0], "echo", 5) == 0)
		return (echo_main(argv, fd));
	else if (ft_strncmp(argv[0], "env", 4) == 0)
		return (env_main(fd));
	else if (ft_strncmp(argv[0], "exit", 5) == 0)
		return (exit_main(argv));
	else if (ft_strncmp(argv[0], "export", 7) == 0)
		return (export_main(argvfd));
	else if (ft_strncmp(argv[0], "pwd", 4) == 0)
		return (pwd_main(fd));
	else if (ft_strncmp(argv[0], "unset", 6) == 0)
		return (unset_main(argv));
	return (-1);
}
