/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 10:23:14 by adiaz-uf          #+#    #+#             */
/*   Updated: 2022/09/26 12:54:31 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == 0)
		return (0);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
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
	printf("ultimo: %s\n", ft_lstlast(&p[0])->content);
}

#include <unistd.h>
#include <string.h>

t_list	*ft_lstnewone(void *content)
{
	t_list	*elem;

	elem = (t_list *)malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	if (!content)
		elem->content = NULL;
	else
		elem->content = content;
	elem->next = NULL;
	return (elem);
}

int main(int argc, const char *argv[])
{
	int			i;
	char		*content;
	t_list		*val;
	t_list		*elem;
	t_list		*elem2;
	t_list		*elem3;
	t_list		*elem4;
	char		*str = strdup("lorem");
	char		*str2 = strdup("ipsum");
	char		*str3 = strdup("dolor");
	char		*str4 = strdup("sit");

	elem = ft_lstnewone(str);
	elem2 = ft_lstnewone(str2);
	elem3 = ft_lstnewone(str3);
	elem4 = ft_lstnewone(str4);
	alarm(5);
	if (argc == 1 || !elem || !elem2 || !elem3 || !elem4)
		return (0);
	else if (atoi(argv[1]) == 1)
	{
		elem->next = elem2;
		elem2->next = elem3;
		elem3->next = elem4;
		val = ft_lstlast(elem);
		i = 0;
		content = val->content;
		while (content[i])
			write(1, &(content[i++]), 1);
		write(1, "\n", 1);
		elem->next = NULL;
		val = ft_lstlast(elem);
		content = val->content;
		i = 0;
		while (content[i])
			write(1, &(content[i++]), 1);
		write(1, "\n", 1);
		elem = NULL;
		val = ft_lstlast(elem);
		if (val == NULL)
			write(1, "NULL", 4);
		write(1, "\n", 1);
	}
	return (0);
}*/
