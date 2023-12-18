/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:40:35 by adiaz-uf          #+#    #+#             */
/*   Updated: 2022/09/25 13:38:26 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*aux1;
	unsigned char	*aux2;

	aux1 = (unsigned char *)s1;
	aux2 = (unsigned char *)s2;
	i = 0;
	if (n <= 0)
		return (0);
	while ((aux1[i] == aux2[i]) && (i < n - 1))
	{
		i++;
	}
	return ((int)aux1[i] - aux2[i]);
}
/*
int main()
{
	char cad[] = "salut";
	char cad2[] = "salut";
	int x;
	unsigned int y;

	y = 7;

	x = ft_memcmp(cad, cad2, y);
	printf("%d\n", x);
	x = memcmp(cad, cad2, y);
	printf("%d", x);
}*/
