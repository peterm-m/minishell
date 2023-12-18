/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 10:43:38 by adiaz-uf          #+#    #+#             */
/*   Updated: 2022/09/26 11:27:18 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	j;
	unsigned int	i;
	unsigned int	a;

	j = 0;
	while (src[j] != '\0')
	{
		j++;
	}
	if (size == 0)
	{
		return (j);
	}
	i = 0;
	a = 1;
	while (src[i] != '\0' && a < size)
	{
		dest[i] = src[i];
		i++;
		a++;
	}
	dest[i] = '\0';
	return (j);
}
