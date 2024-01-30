/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 10:42:07 by adiaz-uf          #+#    #+#             */
/*   Updated: 2022/09/16 10:25:24 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The function `ft_strncmp` compares two strings up to a specified number of characters and returns
 * the difference between the first differing characters.
 * 
 * @param s1 A pointer to the first string to be compared.
 * @param s2 The parameter `s2` is a pointer to a character array (string) that we want to compare with
 * `s1`.
 * @param n The parameter `n` represents the maximum number of characters to compare between the two
 * strings `s1` and `s2`.
 * 
 * @return the difference between the first differing characters in the two strings, casted to an
 * unsigned char.
 */
int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while ((unsigned char)*s1 == (unsigned char)*s2 \
		&& *s1 != '\0' && n - 1 > 0)
	{
		s1++;
		s2++;
		n--;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
