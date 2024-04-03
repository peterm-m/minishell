/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilde_expansion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 20:45:13 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/02 20:00:30 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// TODO gestion de no env. No hay HOME, es necesario gestionar usuario

char	*tilde_expansion(char *str)
{
	char	*home;
	char	*out;

	out = str;
	if (out[1] != '\0' && out[1] != '/')
		return (0);
	home = ft_getenv("HOME");
	out = ft_strjoin(home, ++out);
	free(str);
	return (out);
}
