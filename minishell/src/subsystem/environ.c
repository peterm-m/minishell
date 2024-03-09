/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 02:02:09 by pedro             #+#    #+#             */
/*   Updated: 2024/03/01 19:40:57 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_getenv(const char *name)
{
	return (getenv(name));
}

int	ft_setenv(const char *name, const char *value, int overwrite)
{
	size_t	len;
	int		result;
	char	*env_var;

	if (name == NULL || value == NULL)
		return (-1);
	if (!overwrite && ft_getenv(name) != NULL)
		return (0);
	len = ft_strlen(name) + ft_strlen(value) + 2;
	env_var = ft_malloc(len);
	ft_strlcpy(env_var, (char *) name, len);
	ft_strlcat(env_var, "=", len);
	ft_strlcat(env_var, value, len);
	result = ft_putenv(env_var);
	ft_free(env_var);
	return (result);
}

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
		if (ft_strncmp(environ[num_env], string, name_len) == 0
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

int	ft_clearenv(void)
{
	int	i;

	i = 0;
	while (environ[i] != NULL)
		ft_free(environ[i++]);
	environ = (char **) ft_malloc(sizeof(char *));
	environ[0] = NULL;
	return (EXIT_SUCCESS);
}
