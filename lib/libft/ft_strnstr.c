/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 12:50:40 by adiaz-uf          #+#    #+#             */
/*   Updated: 2022/09/28 11:26:35 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It searches for a string within a string.
 * 
 * @param str The string to be searched.
 * @param to_find the string to find
 * @param len the maximum number of characters to search
 * 
 * @return The address of the first character of the first 
 * occurence of the string to_find in the
 * string str.
 */
char	*ft_strnstr(char *str, char *to_find, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	n;

	i = 0;
	n = ft_strlen(to_find);
	if (n == 0 || str == to_find)
		return ((char *)str);
	while (str[i] != '\0' && i < len)
	{
		j = 0;
		while ((str[i + j] == to_find[j]) && (str[i + j] != '\0')
			&& (i + j) < len)
		{
			j++;
		}
		if (to_find[j] == '\0')
			return (str + i);
		i++;
	}
	return (0);
}
/*
int main()
{
	char cad[20] = "hola qque tal";
	char cad2[20] = "k";
	char cad3[20] = "hola qque tal";
	char cad4[20] = "k";

	printf("%s\n", strnstr(cad, cad2, 18));
	printf("%s", ft_strnstr(cad3, cad4, 18));
}*/
