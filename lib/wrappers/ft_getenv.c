/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 02:02:09 by pedro             #+#    #+#             */
/*   Updated: 2024/04/11 20:29:57 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrappers.h"

char	*ft_getenv(const char *name)
{
	return (getenv(name));
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
	return  (NULL);
}