/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:41:23 by pedromar          #+#    #+#             */
/*   Updated: 2024/03/12 19:45:23 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrappers.h"

int	ft_unsetenv(const char *name)
{
	int		i;
	int		j;
	char	*eq;

	if (name == NULL || ft_strlen(name) == 0 || ft_strchr(name, '=') != NULL)
		return (EXIT_FAILURE);
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
				j = i -1;
				while (environ[++j] != NULL)
					environ[j] = environ[j + 1];
				return (EXIT_SUCCESS);
			}
		}
		i++;
	}
	return (EXIT_FAILURE);
}
