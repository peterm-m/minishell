/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 19:54:26 by adiaz-uf          #+#    #+#             */
/*   Updated: 2024/04/17 19:08:23 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	unset_main(char **argv, int fd_out)
{
	int	argc;
	int	i;

	(void)fd_out;
	argc = get_arr_len(argv);
	if (argc == 1)
	{
		ft_putendl_fd("unset: not enough arguments", 2);
		return (EXIT_SUCCESS);
	}
	i = 1;
	if (ft_strncmp(argv[1], "_", 2) == 0)
		i++;
	while (argv[i])
	{
		ft_environ(argv[i], UNSET, 0);
		i++;
	}
	return (EXIT_SUCCESS);
}
