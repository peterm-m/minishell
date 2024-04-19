/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:31:30 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/19 14:53:24 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrappers.h"

void	unix_error(char *msg)
{
	ft_putstr_fd("minishell", STDERR_FILENO);
	perror(msg);
	exit(EXIT_FAILURE);
}

int	minish_error(char *msg)
{
	ft_putstr_fd("minishell", STDERR_FILENO);
	perror(msg);
	return (EXIT_FAILURE);
}
