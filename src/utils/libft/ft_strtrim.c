/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 18:41:13 by adiaz-uf          #+#    #+#             */
/*   Updated: 2022/09/26 12:48:34 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	is_in_cad(const char *cad, char c)
{
	int	i;

	i = 0;
	while (cad[i] != '\0')
	{
		if (cad[i] == c)
			return (1);
		else
			i++;
	}
	return (0);
}

/**
 * It returns a copy of the string s1, without any of the 
 * characters in the string set at the beginning
 * or end of the string
 * 
 * @param s1 The string to be trimmed.
 * @param set the set of characters to be trimmed
 * 
 * @return A pointer to a new string.
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		len;
	int		i;
	char	*trim;

	start = 0;
	i = 0;
	len = ft_strlen(s1);
	while (s1[start] && is_in_cad(set, s1[start]))
		start++;
	while (start < len && is_in_cad(set, s1[len - 1]))
		len--;
	trim = (char *)malloc(sizeof(char) * (len - start + 1));
	if (!trim)
		return (0);
	while (start < len)
	{
		trim[i] = s1[start];
		start++;
		i++;
	}
	trim[i] = '\0';
	return (trim);
}
/*
int main()
{
	printf("%s", ft_strtrim("", ""));
}*/
