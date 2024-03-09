/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 09:51:00 by adiaz-uf          #+#    #+#             */
/*   Updated: 2022/09/13 10:27:03 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, unsigned int n)
{
	unsigned int	i;
	unsigned char	*aux;

	aux = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		aux[i] = 0;
		i++;
	}
}
/*
int main()
{
	char a[10];
	char c[10];

	ft_bzero(c, 5);
	write(1, c, 10);
	write(1, "\n", 1);
	bzero(a, 5);
	write(1, a, 10);
}*/
