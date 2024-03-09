/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilde_expansion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 20:45:13 by pedromar          #+#    #+#             */
/*   Updated: 2024/03/01 18:48:40 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	tilde_expansion(t_word *word)
{
	char	*home;
	char	*out;

	if (out[0] != '~')
		return (EXIT_FAILURE);
	out = word->word;
	home = ft_getenv("HOME");
	out = ft_strjoin(++out, home);
	ft_free(word->word);
	word->word = out;
	return (EXIT_SUCCESS);
}
