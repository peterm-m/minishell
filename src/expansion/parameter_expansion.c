/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameter_expansion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 20:47:08 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/08 18:11:49 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// TODO: testear hay fallos

static char	*parameter_value(char *str, int start_expan, int end_expan)
{
	char	*value;
	char	*name;

	if (str[start_expan] == '?')
		value = ft_itoa(g_exit_status);
	else if (str[start_expan] == '$')
		value = ft_strdup("$");
	else
	{
		name = ft_substr(str, start_expan, end_expan - start_expan);
		value = ft_getenv(name);
		ft_free(name);
		if (!value)
			return (NULL);
		value = ft_strdup(value);
	}
	return (value);
}

char	*make_expansion(char *str, int start_expan)
{
	int		end_expan;
	char	*out;
	char	*aux[3];

	end_expan = start_expan;
	while (str[end_expan]
		&& (ft_isalnum(str[end_expan]) || str[end_expan] == '_'))
		end_expan++;
	end_expan += (str[start_expan] == '?');
	aux[0] = ft_substr(str, 0, start_expan -1);
	aux[1] = parameter_value(str, start_expan, end_expan);
	aux[2] = ft_substr(str, end_expan, INT_MAX);
	out = ft_strnjoin((char **)aux, 3);
	if (aux[0])
		ft_free(aux[0]);
	if (aux[1])
		ft_free(aux[1]);
	if (aux[2])
		ft_free(aux[2]);
	ft_free(str);
	return (out);
}

// TODO: FIX si la expansion no existe, hace falta disminuir i en uno
// TODO: FIX: cuando solo aparece $? no funciona bien
//                               "$?" si en algun momento
//                             el puntero queda desplazado 

char	*parameter_expansion(char *str)
{
	char	*out;
	int		i;

	i = 0;
	out = str;
	while (1)
	{
		i += search_character(out + i, '$');
		while (out[i] == '$')
			i++;
		if (!out[i])
			break ;
		out = make_expansion(out, i);
		if (out[i - 1] == '\0')
			break ;
	}
	return (out);
}
