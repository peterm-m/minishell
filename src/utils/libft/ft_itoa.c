/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:28:44 by adiaz-uf          #+#    #+#             */
/*   Updated: 2022/09/25 11:09:46 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	tam(long n)
{
	int	i;

	i = 1;
	if (n > 0)
	{
		while (n > 9)
		{
			n = n / 10;
			i++;
		}
	}
	else
	{
		while (n < -9)
		{
			n = n / 10;
			i++;
		}
	}
	return (i);
}

static char	*fill_str(char *s, long n, int sg, int sg2)
{
	long	i;
	int		j;
	char	aux;
	char	x;

	i = n;
	j = sg;
	while (sg < tam(i) + j)
	{
		x = (n % 10) + '0';
		s[sg] = x;
		n = n / 10;
		sg++;
	}
	sg = sg - 1;
	while (j < ((tam(i) + 1 + sg2) / 2))
	{
		aux = s[j] + '0';
		s[j] = s[sg];
		s[sg] = aux - '0';
		sg--;
		j++;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		sig;
	long	num;
	int		sig2;

	num = (long)n;
	sig = 0;
	if (num < 0)
	{
		str = malloc(sizeof(char) * tam(num) + 2);
		if (!str)
			return (0);
		sig = 1;
		num = -num;
		str[0] = '-';
	}
	else
		str = malloc(sizeof(char) * tam(num) + 1);
	if (!str)
		return (0);
	sig2 = sig;
	str = fill_str(str, num, sig, sig2);
	str[(tam(num) + sig)] = '\0';
	return (str);
}
/*
int main()
{
	printf("%s", ft_itoa(-2147483648LL));
}

#include <unistd.h>

void	ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

int		main(int argc, const char *argv[])
{
	int		arg;

	alarm(5);
	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
	{
		char *res = ft_itoa(0);
		ft_print_result(res);
		free(res);
	}
	else if (arg == 2)
	{
		char *res = ft_itoa(9);
		ft_print_result(res);
		free(res);
	}
	else if (arg == 3)
	{
		char *res = ft_itoa(-9);
		ft_print_result(res);
		free(res);
	}
	else if (arg == 4)
	{
		char *res = ft_itoa(10);
		ft_print_result(res);
		free(res);
	}
	else if (arg == 5)
	{
		char *res = ft_itoa(-10);
		ft_print_result(res);
		free(res);
	}
	else if (arg == 6)
	{
		char *res = ft_itoa(8124);
		ft_print_result(res);
		free(res);
	}
	else if (arg == 7)
	{
		char *res = ft_itoa(-9874);
		ft_print_result(res);
		free(res);
	}
	else if (arg == 8)
	{
		char *res = ft_itoa(543000);
		ft_print_result(res);
		free(res);
	}
	else if (arg == 9)
	{
		char *res = ft_itoa(-2147483648LL);
		ft_print_result(res);
		free(res);
	}
	else if (arg == 10)
	{
		char *res = ft_itoa(2147483647);
		ft_print_result(res);
		free(res);
	}
	return (0);
}*/
