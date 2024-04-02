/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilde_expansion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 20:45:13 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/02 17:46:21 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// TODO gestion de no env. No hay HOME, es necesario gestionar usuario

int	tilde_expansion(t_token *word)
{
	char	*home;
	char	*out;

	out = word->str;
	if (out[1] != '\0' && out[1] != '/')
		return (0);
	home = ft_getenv("HOME");
	out = ft_strjoin(home, ++out);
	ft_free(word->str);
	word->str = out;
	return (ft_strlen(home));
}
