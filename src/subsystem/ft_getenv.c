/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 02:02:09 by pedro             #+#    #+#             */
/*   Updated: 2024/04/19 15:15:48 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_getenv(char *name, char **my_environ)
{
	int		i;
	int		size;

	i = -1;
	size = ft_strlen(name);
	while (my_environ[++i])
	{
		if (ft_strncmp(my_environ[i], name, size) == 0)
			return (ft_strchr(my_environ[i], '=') + 1);
	}
	return (NULL);
}

char	*ft_getvar(const char *name)
{
	int	len_name;
	int	i;

	i = -1;
	len_name = ft_strlen(name);
	while (environ[++i] != NULL)
	{
		if (ft_strncmp(environ[i], (char *)name, len_name) == 0
			&& (environ[i])[len_name] == '=')
			return (environ[i]);
	}
	return (NULL);
}
