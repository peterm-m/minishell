/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:39:24 by pedromar          #+#    #+#             */
/*   Updated: 2024/03/18 19:58:16 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrappers.h"

int	ft_putenv(char *string)
{
	char	**new_environ;
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
	new_environ = ft_memcpy(ft_malloc((num_env + 2) * sizeof(char *)),
			environ, num_env * sizeof(char *));
	new_environ[num_env] = (char *) string;
	new_environ[num_env + 1] = NULL;
	environ = new_environ;
	return (EXIT_SUCCESS);
}
