/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:32:08 by adiaz-uf          #+#    #+#             */
/*   Updated: 2022/09/18 13:35:54 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	val;

	val = 0;
	sign = 1;
	i = 0;
	while ((str[i] <= 13 && str[i] >= 9) || str[i] == ' ')
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		val = (val * 10) + (str[i] - '0');
		i++;
	}
	return (val * sign);
}
/*
int main()
{
	printf("%d\n", ft_atoi("+123:123"));
	printf("%d", atoi("+123:123"));
}*/
