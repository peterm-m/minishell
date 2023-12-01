/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstiter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:30:50 by pedro             #+#    #+#             */
/*   Updated: 2023/08/13 20:13:44 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlst.h"

void	ft_dlstiter(t_dlst *dlst, void (*f)(void *))
{
	while (dlst != NULL)
	{
		f(dlst->data);
		dlst = dlst->next;
	}
}
