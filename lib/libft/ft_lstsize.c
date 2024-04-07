/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 10:12:48 by adiaz-uf          #+#    #+#             */
/*   Updated: 2022/09/23 10:25:44 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*aux;

	aux = lst;
	i = 0;
	while (aux)
	{
		aux = aux->next;
		i++;
	}
	return (i);
}
/*
int main()
{
	char *s1 = "1";
	char *s2 = "2";
	char *s3 = "3";
	char *s4 = "4";
	t_list *p;

	p = ft_lstnew(s1);
	printf("%s\n", p->content);
	ft_lstadd_front(&p, ft_lstnew(s2));
	printf("%s\n", p->content);
	ft_lstadd_front(&p, ft_lstnew(s3));
	printf("%s\n", p->content);
	ft_lstadd_front(&p, ft_lstnew(s4));
	printf("%s\n", p->content);
	printf("tamaño: %i\n", ft_lstsize(p));
}*/
