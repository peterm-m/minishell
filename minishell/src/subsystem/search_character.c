/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_character.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:07:11 by pedro             #+#    #+#             */
/*   Updated: 2024/04/02 19:32:58 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	search_character(char *str, char c)
{
	int			i;
	static int	single_q = 0;
	static int	double_q = 0;

	i = 0;
	while (str[i])
	{
		single_q = (single_q + (str[i] == '\'' && double_q == 0)) % 2;
		double_q = (double_q + (str[i] == '\"' && single_q == 0)) % 2;
		if (str[i] == c)
			if ((c == '$' && single_q == 0) || (double_q == 0 && single_q == 0))
				break ;
		i++;
	}
	return (i);
}
