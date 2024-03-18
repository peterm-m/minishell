/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:39:24 by pedromar          #+#    #+#             */
/*   Updated: 2024/03/15 19:30:50 by adiaz-uf         ###   ########.fr       */
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
	printf("\nFT_PUTENV, con string a introducir: %zu \n", name_len);
	printf("\nstr: %s \n", string);
	while (environ[++num_env] != NULL)
	{
		printf("\nenv: %s \n", environ[num_env]);
		if (ft_strncmp(environ[num_env], string, name_len + 1) == 0
			&& (environ[num_env])[name_len] == '=')
		{
			environ[num_env] = (char *) string;
			printf("\nESTA: %s \n", environ[num_env]);
			return (EXIT_SUCCESS);
		}
	}
	new_environ = ft_memcpy(ft_malloc((num_env + 2) * sizeof(char *)),
			environ, num_env * sizeof(char *));
	new_environ[num_env] = (char *) string;
	new_environ[num_env + 1] = NULL;
	printf("\nFT_PUTENV, con string a introducir: %s \n", new_environ[num_env]);
	environ = new_environ;
	return (EXIT_SUCCESS);
}
