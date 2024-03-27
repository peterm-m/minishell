/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 10:43:38 by adiaz-uf          #+#    #+#             */
/*   Updated: 2024/03/25 17:44:52 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * This function copies a string from source to destination with a specified size limit and returns the
 * length of the source string.
 * 
 * @param dest The `dest` parameter is a pointer to a character array where the function will copy the
 * contents of the `src` array.
 * @param src The `src` parameter is a pointer to a character array that contains the string to be
 * copied.
 * @param size The `size` parameter in the `ft_strlcpy` function represents the size of the destination
 * buffer `dest`. It indicates the maximum number of characters that can be copied from the source
 * string `src` to the destination string `dest`, including the null-terminator.
 * 
 * @return the total length of the source string `src`, not the length of the string copied into the
 * destination `dest`.
 */
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
