/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enviroment.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 20:11:11 by adiaz-uf          #+#    #+#             */
/*   Updated: 2024/04/16 18:05:25 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrappers.h"

void	ft_initenv(void)
{
	int	i;

	i = 0;
	while (environ[i])
		ft_putenv(ft_strdup(environ[i++]));
	if (ft_getenv("MINISHLVL") == NULL)
		ft_putenv(ft_strdup("MINISHLVL=1"));
	else
	{
		i = ft_atoi(ft_getenv("MINISHLVL"));
		i++;
		ft_putenv(ft_strjoin("MINISHLVL=", ft_itoa(i)));
	}
}
