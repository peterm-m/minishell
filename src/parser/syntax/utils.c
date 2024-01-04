/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 20:38:02 by pedro             #+#    #+#             */
/*   Updated: 2024/01/04 23:08:24 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	pop_elements(t_dlst *lex, t_dlst *state, int n)
{
	t_dlst	*tmp;

	while (n)
	{
		tmp = lex->next;
		ft_dlstdelone(lex, free);
		lex = tmp;
		tmp = state->next;
		ft_dlstdelone(state, free);
		state = tmp;
		n--;
	}
}
