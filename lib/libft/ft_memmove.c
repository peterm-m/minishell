/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 11:20:10 by adiaz-uf          #+#    #+#             */
/*   Updated: 2022/09/25 10:38:41 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int	i;

	if (!dest && !src)
		return (0);
	i = 0;
	if (((unsigned char *)dest) < ((unsigned char *)src))
	{
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	else
	{
		while (n-- > 0)
		{
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
		}
	}
	return (dest);
}
/*
int main()
{
	char *srt = "hola como ests";
	char dest[50];
	
	printf("%s\n", memmove(dest,srt, -1));
    printf("%s\n", ft_memmove(dest, srt, -1));
}*/
