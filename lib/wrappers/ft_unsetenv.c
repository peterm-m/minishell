/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:41:23 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/16 20:27:20 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrappers.h"

int unset_local(const char *name)
{
	int	i;
	int	j;

	i = 0; 
	if (name == NULL || ft_strlen(name) == 0)
		return (EXIT_FAILURE);
	while (environ[i] != NULL)
	{
			if (ft_strncmp(environ[i], (char *)name, ft_strlen(name) + 1) == 0)
			{
				j = i - 1;
				ft_free(environ[i]);
				while (environ[++j] != NULL)
					environ[j] = environ[j + 1];
				return (EXIT_SUCCESS);
			}
		i++;
	}
	return (EXIT_FAILURE);
}

int	ft_unsetenv(const char *name)
{
	int		i;
	int		j;
	char	*eq;

	if (name == NULL || ft_strlen(name) == 0 || ft_getenv(name) == NULL)
		return (unset_local(name));
	i = 0;
	while (environ[i] != NULL)
	{
		eq = ft_strchr(environ[i], '=');
		if (eq != NULL)
		{
			if (ft_strncmp(environ[i], (char *)name,
					(size_t)(eq - environ[i])) == 0
					&& (size_t)(eq - environ[i]) == ft_strlen(name))
			{
				j = i - 1;
				while (environ[++j] != NULL)
					environ[j] = environ[j + 1];
				return (EXIT_SUCCESS);
			}
		}
		i++;
	}
	return (EXIT_FAILURE);
}
