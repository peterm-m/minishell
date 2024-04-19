/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilde_expansion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 20:45:13 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/19 18:09:15 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*tilde_expansion(char *str)
{
	char	*arr[2];
	char	*out;

	if (str[1] != '\0' && str[1] != '/')
		return (str);
	arr[0] = ft_environ("HOME", GET, 0);
	arr[1] = str +1;
	out = ft_strnjoin(arr, 2);
	ft_free(str);
	return (out);
}
