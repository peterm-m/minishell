/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:31:30 by pedromar          #+#    #+#             */
/*   Updated: 2024/03/11 13:08:09 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrappers.h"

void	unix_error(char *msg)
{
	// TODO: gestion de errores
	fprintf(stderr, "%s: %s\n", msg, strerror(errno));
	exit(EXIT_FAILURE);
}
