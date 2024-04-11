/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temfile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 20:55:05 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/10 21:17:39 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_temfile(void)
{
	int		i;
	char	*num;
	char	*out;
	char	file_name[NAME_MAX];

	i = 0;
	ft_strlcpy(file_name, ".tmpfile", 8);
	while (access(file_name, F_OK) == 0)
	{
		num = ft_itoa(i++);
		if (num == NULL)
			return (NULL);
		ft_strlcpy(file_name +8, num, NAME_MAX -8);
		ft_free(num);
	}
	out = ft_strdup(file_name);
	return (out);
}
