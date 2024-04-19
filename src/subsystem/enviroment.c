/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enviroment.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 20:11:11 by adiaz-uf          #+#    #+#             */
/*   Updated: 2024/04/19 15:15:09 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_initenv(void)
{
	char	**new_env;
	int		i;

	new_env = ft_calloc(get_arr_len(environ) + 1, sizeof(char **));
	if (new_env == NULL)
	{
		minish_error("Environment initialization");
		exit(EXIT_FAILURE);
	}
	i = -1;
	while (environ[++i])
	{
		new_env[i] = ft_strdup(environ[i]);
		if (new_env[i] == NULL)
		{
			while (--i > 0)
				ft_free(new_env[i]);
			minish_error("Environment initialization");
			exit(EXIT_FAILURE);
		}
	}
	new_env[i] = NULL;
	return (new_env);
}

char	*ft_environ(char *parameter, int action, int index)
{
	static char	**my_environ;

	if (my_environ == NULL)
		my_environ = ft_initenv();
	if (action == GET)
		return (ft_getenv(parameter, my_environ));
	else if (action == ADD)
		my_environ = ft_putenv(parameter, my_environ);
	else if (action == UNSET)
		my_environ = ft_unsetenv(parameter, my_environ);
	else if (action == CLEAN)
		clean_argv(my_environ);
	else if (action == INDEX)
		return (my_environ[index]);
	return (NULL);
}
