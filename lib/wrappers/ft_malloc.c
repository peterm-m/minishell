/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:16:37 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/18 19:49:39 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrappers.h"

void	*ft_malloc(size_t size)
{
	void	*p;

	p = malloc(size);
	if (p == NULL)
		unix_error("Malloc error");
	return (p);
}

void	ft_free(void *ptr)
{
	free(ptr);
}
