/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enviroment.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 20:11:11 by adiaz-uf          #+#    #+#             */
/*   Updated: 2024/04/17 19:28:48 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* #include "wrappers.h"

void	ft_initenv(void)
{
	int	i;

	i = 0;
	while (environ[i])
		ft_putenv(ft_strdup(environ[i++]));
	if (ft_getenv("MINISHLVL") == NULL)
		ft_putenv(ft_strdup("MINISHLVL=1"));
	else
	{
		i = ft_atoi(ft_getenv("MINISHLVL"));
		i++;
		ft_putenv(ft_strjoin("MINISHLVL=", ft_itoa(i)));
	}
} */

char	**ft_initenv(void)
{
	char	**new_env;
	int		i;

	new_env = ft_calloc(get_arr_len(environ) + 1, sizeof(char **));
	i =	-1;
	while (environ[++i])
		new_env[i] = ft_strdup(environ[i]);
	new_env[i] = NULL;
	//new_env = ft_copyarg(environ);
/* 	if (ft_environ("MINISHLVL", 0) == NULL)
		ft_putenv(ft_strdup("MINISHLVL=1"), new_env);
	else
	{
		i = ft_atoi(ft_getenv("MINISHLVL"));
		i++;
		ft_putenv(ft_strjoin("MINISHLVL=", ft_itoa(i)));
	}*/
	return (new_env);
}

char	*ft_environ(char *parameter, int action, int index)
{
	static char	**my_environ;

	if (my_environ == NULL)
		my_environ = ft_initenv();
	if (action == GET) //GET ENV
		return (ft_getenv(parameter));
	else if (action == ADD) // ADD
		my_environ = ft_putenv(parameter, my_environ);
	else if (action == UNSET) // UNSET
		my_environ = ft_unsetenv(parameter, my_environ);
	else if (action == CLEAN) // CLEAN
		clean_argv(my_environ);
	else if (action == INDEX) // index string
		return (my_environ[index]);
	return (NULL);
}