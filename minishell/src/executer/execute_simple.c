/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_simple.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:56:16 by pedromar          #+#    #+#             */
/*   Updated: 2024/03/21 16:23:39 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//NO: Si no nombre del comando no tiene barras, intenta localizarlo en las funciones

//SI: Si no es una funcion. Se busca en la lista de built-in
//SI: Si no funcion ni built-in busca en PATH. Mirar descripcion 
//SI: Si la busqueda es satisfactoria o si el nombre tiene barras, se ejecuta en shell por separado
// 		usando el resto de argumentos como parametros.
//SI: Si falla 

//NO: Si no se lanza de forma asincrona, la shell espera a que se complete el comando y recopila su salida.

void	execute_simple(t_simple *cmd)
{
	pid_t		pid;

	pid = ft_fork();
	if (pid == 0)
	{
		make_redir(cmd->redirects);
		child_signals();
		ft_execle(cmd->words);
	}
	else
	{
		wait_signals();
		ft_waitpid(pid, g_exit_status, WUNTRACED);
		initial_signals();
	}
	//printf("---> statsu%d\n", g_exit_status);
	return ;
}

// TODO: gestionar error.