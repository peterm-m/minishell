/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clearenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:40:35 by pedromar          #+#    #+#             */
/*   Updated: 2024/03/12 19:45:27 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrappers.h"

int	ft_clearenv(void)
{
	int	i;

	i = 0;
	while (environ[i] != NULL)
		ft_free(environ[i++]);
	environ = (char **) ft_malloc(sizeof(char *));
	environ[0] = NULL;
	return (EXIT_SUCCESS);
}
