/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enviroment.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 20:11:11 by adiaz-uf          #+#    #+#             */
/*   Updated: 2024/04/15 18:15:26 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	initenv(void)
{
	int		i;
	char	**new_env;

	i = get_arr_len(environ);
	new_env = ft_calloc(i +1, sizeof(char *));
	while (environ[--i])
		new_env[i] = ft_strdup(environ[i]);
	environ = new_env;
}
