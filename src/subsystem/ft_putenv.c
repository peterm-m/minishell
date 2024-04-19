/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:39:24 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/19 18:08:19 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	not_in_export(char *string, char **my_environ)
{
	int	i;
	int	size;

	i = -1;
	size = ft_strlen(string);
	while (my_environ[++i])
	{
		if (ft_strncmp(my_environ[i], string, size) == 0)
			return (0);
	}
	return (1);
}

static char	**realloc_env(int len_env, char *string, char **my_environ)
{
	char	**new_environ;
	char	*aux;

	new_environ = ft_calloc((len_env + 2), sizeof(char *));
	if (new_environ == NULL)
		return (my_environ);
	if ((ft_strlen(string) - (ft_strchr(string, '=') - string)) == 1)
	{
		aux = ft_strjoin(string, "\"\"");
		ft_free(string);
		string = aux;
	}
	new_environ[len_env] = (char *) string;
	while (len_env--)
		new_environ[len_env] = ft_strdup(my_environ[len_env]);
	len_env = -1;
	while (my_environ[++len_env])
		ft_free(my_environ[len_env]);
	ft_free(my_environ);
	return (new_environ);
}

static void	change_cariable(char **my_environ,
	char *string, char *eq, int num_env)
{
	char	*aux;

	if ((ft_strlen(string) - (eq - string)) == 1)
	{
		aux = ft_strjoin(string, "\"\"");
		ft_free(string);
		string = aux;
	}
	ft_free(my_environ[num_env]);
	my_environ[num_env] = string;
}

char	**ft_putenv(char *string, char **my_environ)
{
	int		num_env;
	char	*eq;

	eq = ft_strchr(string, '=');
	if (eq == NULL && not_in_export(string, my_environ))
		return (realloc_env(get_arr_len(my_environ), string, my_environ));
	if (string == NULL || eq == NULL)
		return (my_environ);
	num_env = -1;
	while (my_environ[++num_env] != NULL)
	{
		if (ft_strncmp(my_environ[num_env], string, eq - string) == 0)
		{
			change_cariable(my_environ, string, eq, num_env);
			return (my_environ);
		}
	}
	return (realloc_env(num_env, string, my_environ));
}
