/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 09:20:24 by adiaz-uf          #+#    #+#             */
/*   Updated: 2022/09/21 12:14:29 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, unsigned int len)
{
	unsigned char	*aux;
	unsigned int	i;

	aux = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		aux[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
/*
int main()
{
	char b[10];
	char d[10];

	printf("%s\n", memset(b, 'a', 5));
	printf("%s", ft_memset(d, 'b', 5));
}*/
