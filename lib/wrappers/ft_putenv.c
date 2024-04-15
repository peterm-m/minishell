/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:39:24 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/15 15:50:38 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrappers.h"

static int realloc_env(int len_env, char *string)
{
	char	**old_environ;
	char	**new_environ;

	new_environ = ft_calloc((len_env + 2), sizeof(char *));
	if (new_environ == NULL)
		return (EXIT_FAILURE);
	new_environ[len_env] = (char *) string;
	while (len_env--)
		new_environ[len_env] = environ[len_env]; 
	old_environ = environ;
	environ = new_environ;
	free(old_environ);
	return (EXIT_SUCCESS);
}

int	ft_putenv(char *string)
{
	int		num_env;
	char	*eq;
	size_t	name_len;

	eq = ft_strchr(string, '=');
	name_len = eq - string;
	if (string == NULL || eq == NULL)
		return (EXIT_FAILURE);
	num_env = -1;
	while (environ[++num_env] != NULL)
	{
		if (ft_strncmp(environ[num_env], string, name_len + 1) == 0
			&& (environ[num_env])[name_len] == '=')
		{
			environ[num_env] = (char *) string;
			return (EXIT_SUCCESS);
		}
	}
	return (realloc_env(num_env, string));
}
