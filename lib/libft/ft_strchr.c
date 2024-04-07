/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 10:25:27 by adiaz-uf          #+#    #+#             */
/*   Updated: 2022/09/25 13:52:58 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	aux;
	char	*str;
	int		i;

	aux = (char)c;
	str = (char *)s;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == aux)
			return (&str[i]);
		else
			i++;
	}
	if (aux == '\0')
		return (&str[i]);
	else
		return (0);
}
/*
int main()
{
	const char	*a = "hola que tal";
	const char	*b = "hola que tal";

	printf("%s\n", ft_strchr(a, 'f'));
	printf("%s", strchr(b, 'f'));
}*/
