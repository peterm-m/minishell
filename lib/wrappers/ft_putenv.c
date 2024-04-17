/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:39:24 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/16 19:34:28 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrappers.h"
int	arr_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	return (i);
}

int	not_in_export(char *string)
{
	int	i;
	int	size;

	i = -1;
	size = ft_strlen(string);
	while(environ[++i])
	{
		if (ft_strncmp(environ[i], string, size) == 0)
			return (0);
	}
	return (1);
}

static int realloc_env(int len_env, char *string)
{
	//char	**old_environ;
	char	**new_environ;

	new_environ = ft_calloc((len_env + 2), sizeof(char *));
	if (new_environ == NULL)
		return (EXIT_FAILURE);
	if ((ft_strlen(string) - (ft_strchr(string, '=') - string)) == 1)
		string = ft_strjoin(string, "\"\"");
	new_environ[len_env] = (char *) string;
	while (len_env--)
		new_environ[len_env] = environ[len_env]; 
	//old_environ = environ;
	environ = new_environ;
	//free(old_environ);
	return (EXIT_SUCCESS);
}

int	ft_putenv(char *string)
{
	int		num_env;
	char	*eq;
	size_t	name_len;

	eq = ft_strchr(string, '=');
	if (eq == NULL && not_in_export(string))
		return (realloc_env(arr_len(environ), string));
	if (string == NULL || eq == NULL)
		return (EXIT_FAILURE);
	name_len = eq - string;
	num_env = -1;
	while (environ[++num_env] != NULL)
	{
		if (ft_strncmp(environ[num_env], string, name_len) == 0)
		{
			if (ft_strlen(string) - name_len == 1)
				string = ft_strjoin(string, "\"\"");
			environ[num_env] = (char *) string;
			return (EXIT_SUCCESS);
		}
	}
	return (realloc_env(num_env, string));
}
