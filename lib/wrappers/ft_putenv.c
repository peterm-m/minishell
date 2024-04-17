/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:39:24 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/17 19:30:44 by adiaz-uf         ###   ########.fr       */
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

char **realloc_env(int len_env, char *string, char **my_environ)
{
	//char	**old_environ;
	char	**new_environ;

	new_environ = ft_calloc((len_env + 2), sizeof(char *));
	if (new_environ == NULL)
		return (my_environ);
	if ((ft_strlen(string) - (ft_strchr(string, '=') - string)) == 1)
		string = ft_strjoin(string, "\"\"");
	new_environ[len_env] = (char *) string;
	while (len_env--)
		new_environ[len_env] = my_environ[len_env]; 
	//old_environ = environ;
	my_environ = new_environ;
	//free(old_environ);
	return (my_environ);
}

char	**ft_putenv(char *string, char **my_environ)
{
	int		num_env;
	char	*eq;
	size_t	name_len;

	eq = ft_strchr(string, '=');
	if (eq == NULL && not_in_export(string))
		return (realloc_env(arr_len(my_environ), string, my_environ));
	if (string == NULL || eq == NULL)
		return (my_environ);
	name_len = eq - string;
	num_env = -1;
	while (my_environ[++num_env] != NULL)
	{
		if (ft_strncmp(my_environ[num_env], string, name_len) == 0)
		{
			if (ft_strlen(string) - name_len == 1)
				string = ft_strjoin(string, "\"\"");
			ft_free(my_environ[num_env]);
			my_environ[num_env] = ft_strdup(string);
			return (my_environ);
		}
	}
	return (realloc_env(num_env, string, my_environ));
}
