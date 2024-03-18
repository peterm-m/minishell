/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:56:16 by pedromar          #+#    #+#             */
/*   Updated: 2024/03/15 20:19:38 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	if path_name find put this in path
	else path emty string
*/

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

int	search_builtin2(char *name, char **argv)
{
	if (ft_strncmp(name, "cd", 3) == 0)
		return (cd_main(argv));
	else if (ft_strncmp(name, "echo", 5) == 0) // ECHO OK
		return (echo_main(argv));
	else if (ft_strncmp(name, "env", 4) == 0) // ENV OK
		return (env_main(environ));
	else if (ft_strncmp(name, "exit", 5) == 0) // EXIT OK
		return (exit_main(argv));
	else if (ft_strncmp(name, "export", 7) == 0)
		return (export_main(argv));
	else if (ft_strncmp(name, "pwd", 4) == 0) // PWD OK
		return (pwd_main());
	else if (ft_strncmp(name, "unset", 6) == 0)
		return (unset_main(argv));
	return (-1);
}

// TODO: testear que pasa si NULL en input
//		 testear PATH no existe
//		 testear que pasa si no se encuentra dir
//		 testear que pasa si existe pero sin permisos de ejecucion

int	search_path(char *name, t_path_name *path)
{
	int			i;
	int			find;
	char		**directorys;

	i = 0;
	find = 0;
	directorys = ft_split(ft_getenv("PATH"), ':');
	while (directorys && directorys[i])
	{
		if (find == 0)
		{
			ft_strlcpy(path->path_name, directorys[i], PATH_MAX);
			ft_strlcat(path->path_name, "/", PATH_MAX);
			ft_strlcat(path->path_name, name, PATH_MAX);
			if (access(path->path_name, X_OK) == 0)
				find = 1;
		}
		ft_free(directorys[i++]);
	}
	ft_free(directorys);
	return (find);
}

char	**list_to_arr(t_word_list *words)
{
	size_t		n_word;
	char		**arr;
	t_word_list	*tmp;

	n_word = 0;
	tmp = words;
	while (tmp)
	{
		tmp = tmp->next;
		n_word++;
	}
	arr = ft_malloc((n_word +1) * sizeof(char *));
	arr[n_word] = NULL;
	n_word = 0;
	tmp = words;
	while (tmp)
	{
		arr[n_word++] = tmp->word;
		tmp = tmp->next;
	}
	return (arr);
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
	t_path_name	filename;
	char		**argv;
	int			status;

	argv = list_to_arr(cmd->words);
	status = search_builtin2(cmd->words->word, argv);
	if (status != -1)
		return ;
	search_path(cmd->words->word, &filename);
	status = 0;
	open_redir(cmd->redirects);
	pid = ft_fork();
	if (pid == 0)
	{
		make_redir(cmd->redirects);
		ft_signal(SIGINT, SIG_DFL);
		ft_execve(filename.path_name, argv, environ);
		// TODO: gestionar error.
	}
	else
		waitpid(pid, &status, WUNTRACED);
	return ;
}
