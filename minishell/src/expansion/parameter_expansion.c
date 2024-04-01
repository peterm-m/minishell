/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameter_expansion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 20:47:08 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/02 00:22:47 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// TODO: testear hay fallos

static char	*parameter_value(t_token *word, int start_expan, int end_expan)
{
	char	*value;
	char	*name;

	if (word->str[start_expan] == '?')
		value = ft_itoa(g_exit_status);
	else if (word->str[start_expan] == '$')
		value = ft_strdup("$");
	else
	{
		name = ft_substr(word->str, start_expan, end_expan - start_expan);
		value = ft_getenv(name);
		free(name);
		if (!value)
			return (NULL);
		value = ft_strdup(value);
	}
	return (value);
}

int	parameter_expansion(t_token *word, int start_expan)
{
	int		end_expan;
	char	*aux;
	char	*str[3];

	end_expan = start_expan;
	while (word->str[end_expan] &&
		(ft_isalnum(word->str[end_expan]) || word->str[end_expan] == '_'))
		end_expan++;
	end_expan += (word->str[start_expan] == '?');
	str[0] = ft_substr(word->str, 0, start_expan -1);
	str[1] = parameter_value(word, start_expan, end_expan);
	str[2] = ft_substr(word->str, end_expan, INT_MAX);
	aux = ft_strnjoin((char **)str, 3);
	free(word->str);
	word->str = aux;
	if (str[0])
		free(str[0]);
	if (str[1])
		free(str[1]);
	if (str[2])
		free(str[2]);
	return (0);
}
