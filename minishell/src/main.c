/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:42:25 by pedromar          #+#    #+#             */
/*   Updated: 2024/03/09 12:17:44 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#ifdef DEBUG

int	main(int argc, char **argv)
{
	interactive_loop(argc, argv);
	return (EXIT_SUCCESS);
}

#else

int	main(int argc, char **argv)
{
	//initialization();
	interactive_loop(argc, argv);
	return (EXIT_SUCCESS);
}
#endif
