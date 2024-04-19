/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:41:23 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/19 15:17:26 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**unset_local(const char *name, char **my_environ)
{
	int	i;
	int	j;

	i = 0;
	if (name == NULL || ft_strlen(name) == 0)
		return (my_environ);
	while (my_environ[i] != NULL)
	{
		if (ft_strncmp(my_environ[i], (char *)name, ft_strlen(name) + 1) == 0)
		{
			j = i - 1;
			ft_free(my_environ[i]);
			while (my_environ[++j] != NULL)
				my_environ[j] = my_environ[j + 1];
			return (my_environ);
		}
		i++;
	}
	return (my_environ);
}

char	**ft_unsetenv(char *name, char **my_environ)
{
	int		i;
	int		j;
	char	*eq;

	if (!name || ft_strlen(name) == 0 || ft_environ(name, GET, 0) == NULL)
		return (unset_local(name, my_environ));
	i = -1;
	while (my_environ[++i] != NULL)
	{
		eq = ft_strchr(my_environ[i], '=');
		if (eq != NULL)
		{
			if (ft_strncmp(my_environ[i], (char *)name,
					(size_t)(eq - my_environ[i])) == 0
					&& (size_t)(eq - my_environ[i]) == ft_strlen(name))
			{
				ft_free(my_environ[i]);
				j = i - 1;
				while (my_environ[++j] != NULL)
					my_environ[j] = my_environ[j + 1];
				return (my_environ);
			}
		}
	}
	return (my_environ);
}
