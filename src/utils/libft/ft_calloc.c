/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:45:46 by adiaz-uf          #+#    #+#             */
/*   Updated: 2022/09/18 13:37:28 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <unistd.h>
//#include <stdio.h>

void	*ft_calloc(size_t n, size_t size)
{
	size_t	i;
	char	*b;

	b = (char *)malloc(n * size);
	if (!b)
		return (0);
	i = 0;
	while (i < (n * size))
	{
		b[i] = '\0';
		i++;
	}
	return ((void *)b);
}
/*
int main()
{
	write(1, ft_calloc(10,5), 10);
	write(1, calloc(10,5), 10);
	printf("%s\n", ft_calloc(10, 5));
	printf("%s", calloc(10, 5));
}*/
