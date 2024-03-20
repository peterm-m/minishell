/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:56:16 by pedromar          #+#    #+#             */
/*   Updated: 2024/03/19 20:28:07 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


/* int	search_builtin(char *name, t_path_name *path)
{
	static char	*builtins[8] = \
	{"cd", "echo", "env", "pwd", "export", "unset", "exit", NULL};
	int			i;

	if (ft_strlen(name) > 6)
		return (FALSE);
	i = 0;
	while (builtins[i])
	{
		if (ft_strncmp(name, builtins[i], ft_strlen(builtins[i]) + 1) == 0)
			break ;
		i++;
	}
	if (builtins[i] == NULL)
		return (FALSE);
	ft_strlcpy(path->path_name, BUILTINS_DIR, PATH_MAX);
	ft_strlcat(path->path_name, "/", PATH_MAX);
	ft_strlcat(path->path_name, name, PATH_MAX);
	 return (TRUE);
}*/

int	search_builtin(t_word_list *words)
{
	char **argv;

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


//NO: Si no nombre del comando no tiene barras, intenta localizarlo en las funciones

//SI: Si no es una funcion. Se busca en la lista de built-in
//SI: Si no funcion ni built-in busca en PATH. Mirar descripcion 
//SI: Si la busqueda es satisfactoria o si el nombre tiene barras, se ejecuta en shell por separado
// 		usando el resto de argumentos como parametros.
//SI: Si falla 

//NO: Si no se lanza de forma asincrona, la shell espera a que se complete el comando y recopila su salida.

void	executer(t_simple *cmd)
{
	pid_t		pid;
	int			status;

	if (search_builtin(cmd->words) != -1)
		return ;
	open_redir(cmd->redirects);
	pid = ft_fork();
	if (pid == 0)
	{
		child_signals();
		make_redir(cmd->redirects);
		ft_execle(cmd->words);
	}
	else
	{
		wait_signals();
		waitpid(pid, &status, WUNTRACED);
		initial_signals();
	}
	return ;
}

// TODO: gestionar error.