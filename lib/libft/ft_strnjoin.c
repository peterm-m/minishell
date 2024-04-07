/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 21:33:31 by pedro             #+#    #+#             */
/*   Updated: 2024/04/07 17:24:42 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*append_str(char *dest, char *str)
{
	while (*str)
		*dest++ = *str++;
	return (dest);
}

char	*ft_strnjoin(char **s, int n)
{
	int		i;
	int		size;
	char	*aux;
	char	*out;

	i = -1;
	size = 0;
	while (++i < n)
		if (s[i])
			size += ft_strlen((char *)s[i]);
	out = ft_calloc((size + 1), sizeof(char));
	if (out == NULL)
		return (NULL);
	i = -1;
	aux = out;
	while (++i < n)
		if (s[i])
			aux = append_str(aux, (char *)s[i]);
	return (out);
}
