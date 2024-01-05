/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 01:05:58 by pedro             #+#    #+#             */
/*   Updated: 2024/01/05 14:18:49 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_element	*make_element(t_dlst *lex, t_state	*state, int rule)
{
	t_element	*element;

	element = (t_element *)ft_malloc(sizeof(t_element));
	return (element);
}

void	append_element(t_dlst *lex, t_state *state, int rule)
{
	return ;
}