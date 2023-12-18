/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 11:24:09 by adiaz-uf          #+#    #+#             */
/*   Updated: 2022/09/26 12:51:41 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It adds a new element to the end of a list
 * 
 * @param lst A pointer to the first element of a linked list.
 * @param new the new element to add to the list
 */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*aux;

	if (*lst == 0)
		*lst = new;
	else
	{
		aux = ft_lstlast(*lst);
		aux->next = new;
	}
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
	ft_lstadd_back(&p, ft_lstnew("5"));
	printf("%s\n", ft_lstlast(p)->content);
	printf("ultimo: %s\n", ft_lstlast(p)->content);
}*/
