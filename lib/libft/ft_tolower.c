/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 08:49:00 by adiaz-uf          #+#    #+#             */
/*   Updated: 2022/09/13 10:31:09 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	unsigned char	aux;

	aux = (unsigned char)c;
	if (c >= 65 && c <= 90)
	{
		aux += 32;
		return ((int)aux);
	}
	else
		return (c);
}
/*
int main()
{
    printf("%i\n", ft_tolower('D'));
    printf("%i ", tolower('D'));
    return (0);
}*/
