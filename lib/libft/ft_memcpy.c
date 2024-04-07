/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 11:20:10 by adiaz-uf          #+#    #+#             */
/*   Updated: 2022/09/18 13:51:54 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	char			*auxdest;
	char			*auxsrc;

	if (src == 0 && dest == 0)
		return (0);
	auxdest = (char *)dest;
	auxsrc = (char *)src;
	i = 0;
	while (i < n)
	{
		auxdest[i] = auxsrc[i];
		i++;
	}
	return (dest);
}
/*
int main()
{
	char *srt = "hola";
	char dest[10];
	
	printf("%s\n", memcpy(dest,srt, 5));
    printf("%s\n", ft_memcpy(dest, srt, 5));
}*/
