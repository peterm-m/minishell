/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:25:35 by adiaz-uf          #+#    #+#             */
/*   Updated: 2022/09/15 15:37:02 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s)
{
	int		size;
	int		i;
	char	*dup;

	size = 0;
	while (s[size] != '\0')
		size++;
	dup = malloc((size + 1) * sizeof(char));
	if (!dup)
		return (0);
	i = 0;
	while (i < size)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
/*
int main()
{
    printf("%s\n", ft_strdup("hola que tal"));
    printf("%s\n", strdup("hola que tal"));
    return (0);
}*/
