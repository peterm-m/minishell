/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_removal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 21:04:49 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/02 21:20:12 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	quote_remove(char *str)
{
	int	i;
	int	j;
	int	single_q;
	int	double_q;

	i = 0;
	j = 0;
	single_q = 0;
	double_q = 0;
	while (str[j])
	{
		single_q = (single_q + (str[j] == '\'' && double_q == 0)) % 2;
		double_q = (double_q + (str[j] == '\"' && single_q == 0)) % 2;
		if ((str[j] == '\"' && single_q == 0)
			|| (str[j] == '\'' && double_q == 0))
			j++;
		str[i++] = str[j++];
	}
	while (i < j)
		str[i++] = '\0';
}
