/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 08:56:04 by adiaz-uf          #+#    #+#             */
/*   Updated: 2022/09/23 10:06:19 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newnodo;

	newnodo = (t_list *)malloc(sizeof(t_list));
	if (!newnodo)
		return (0);
	newnodo->content = content;
	newnodo->next = 0;
	return (newnodo);
}
/*
int main()
{
	printf("%s", ft_lstnew((void *)"hola")->content);
}*/
