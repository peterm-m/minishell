/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstlast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:53:25 by pedro             #+#    #+#             */
/*   Updated: 2024/01/21 19:31:41 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlst.h"

t_dlst	*ft_dlstlast(t_dlst *dlst)
{
	if (dlst == NULL)
		return (NULL);
	while (dlst->next != NULL)
		dlst = dlst->next;
	return (dlst);
}
