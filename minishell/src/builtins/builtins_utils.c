/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:08:32 by adiaz-uf          #+#    #+#             */
/*   Updated: 2024/03/19 19:09:02 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int get_arr_len(char **env)
{
	int i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}

void    sort_env()
{
	int i;
	int j;
	int env_len;
	char *aux;

	env_len = get_arr_len(environ);
	i = 0;
	while (i < env_len - 1)
	{
		j = i + 1;
		while (j < env_len)
		{
			if (strcmp(environ[i], environ[j]) > 0)
			{
				aux  = environ[i];
				environ[i] = environ[j];
				environ[j] = aux;
			}
			j++;
		}
		i++;
	}
}