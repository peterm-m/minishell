/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:16:37 by pedromar          #+#    #+#             */
/*   Updated: 2024/01/16 19:58:53 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrappers.h"

static void	*ft_memset(void *b, int c, unsigned int len)
{
	unsigned char	*aux;
	unsigned int	i;

	aux = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		aux[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

void	*ft_malloc(size_t size)
{
	void	*p;

	p = malloc(size);
	if (p == NULL)
		unix_error("Malloc error");
	else
		ft_memset(p, 0, size);
	return (p);
}
