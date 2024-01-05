/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 20:38:02 by pedro             #+#    #+#             */
/*   Updated: 2024/01/05 20:27:26 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
	Delete n element of lex and state
*/

void	pop_elements(t_dlst **lex, t_dlst **state, int n)
{
	t_dlst	*tmp;

	while (n)
	{
		tmp = (*state)->next;
		ft_dlstdelone(*state, free);
		*state = tmp;
		n--;
		//tmp = (*lex)->next;
		//ft_dlstdelone(*lex, free);
		//*lex = tmp;
	}
}
