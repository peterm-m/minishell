/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:38:41 by pedromar          #+#    #+#             */
/*   Updated: 2024/03/15 18:49:40 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrappers.h"

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
	printf("\nFT_SETENV: con string a introducir: %s\n", env_var);
	result = ft_putenv(env_var);
	ft_free(env_var);
	return (result);
}

