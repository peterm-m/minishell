/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_simple.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:56:16 by pedromar          #+#    #+#             */
/*   Updated: 2024/03/27 18:13:16 by pedro            ###   ########.fr       */
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

/* Execute a simple command that is hopefully defined in a disk file
   somewhere.

   1) fork
	child:	
   		2) change signals
   		3) connect pipes
   		4) do redirections
   		5) execve
		6) exit
	father:
		2) change signals
		3) wait status
		4) restore signals

*/

static	void	wait_simple(pid_t pid, int fd_in, int fd_out)
{
	int			status;

	wait_signals();
	if (fd_in == NO_PIPE && fd_out == NO_PIPE)
	{
		ft_waitpid(pid, &status, WUNTRACED);
		if (WIFEXITED(status))
			g_exit_status = WEXITSTATUS(status);
	}
	initial_signals();
}

void	execute_simple(t_command *cmd, int fd_in, int fd_out)
{
	pid_t		pid;
	t_simple	*command;

	command = cmd->value.simple;
	pid = ft_fork();
	if (pid == 0)
	{
		child_signals();
		make_pipe(fd_in, fd_out);
		make_redir(command->redirects);
		ft_execle(command->words);
		exit (EXIT_SUCCESS);
	}
	else
		wait_simple(pid, fd_in, fd_out);
	return ;
}

// TODO: gestionar error.