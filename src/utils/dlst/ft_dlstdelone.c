/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 22:17:25 by pedro             #+#    #+#             */
/*   Updated: 2023/12/14 20:23:56 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlst.h"

void	ft_dlstdelone(t_dlst *dlst, void (*del)(void*))
{
	if (dlst != NULL)
	{
		del(dlst->data);
		free(dlst);
	}
}
