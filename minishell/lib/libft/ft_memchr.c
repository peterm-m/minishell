/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:55:01 by adiaz-uf          #+#    #+#             */
/*   Updated: 2022/09/26 09:59:29 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	a;
	unsigned char	*aux;
	size_t			i;

	a = (unsigned char)c;
	aux = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (aux[i] == a)
			return (&aux[i]);
		i++;
	}
	return (0);
}
/*
int main()
{
	char *cad = "hola qque tal";
	printf("%s\n", ft_memchr(cad, 0, 0));
	printf("%s", memchr(cad, 0, 0));
}*/
