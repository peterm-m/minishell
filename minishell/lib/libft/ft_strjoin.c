/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 13:22:29 by adiaz-uf          #+#    #+#             */
/*   Updated: 2022/09/23 12:46:32 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*c;
	size_t	size;
	size_t	i;
	size_t	j;

	size = (ft_strlen((char *)s1) + ft_strlen((char *)s2));
	c = malloc(sizeof(char) * size + 1);
	if (!c)
		return (0);
	i = 0;
	while (i < ft_strlen((char *)s1))
	{
		c[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < ft_strlen((char *)s2))
	{
		c[i] = s2[j];
		i++;
		j++;
	}
	c[i] = '\0';
	return (c);
}
/*
int main()
{
	printf("%s", ft_strjoin("hola", "que tal"));
}*/
