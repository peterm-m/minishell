/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:36:38 by pedro             #+#    #+#             */
/*   Updated: 2024/03/27 16:16:40 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_pipe(int fd_in, int fd_out)
{
	if (fd_in > 0)
		close(fd_in);
	if (fd_out > 0)
		close(fd_out);
}

void	make_pipe(int fd_in, int fd_out)
{
	if (fd_in != NO_PIPE)
		ft_dup2(fd_in, STDIN_FILENO);
	if (fd_in > 0)
		ft_close(fd_in);
	if (fd_out != NO_PIPE)
		ft_dup2(fd_out, STDOUT_FILENO);
	if (fd_out == 0 || fd_out > 1)
		ft_close(fd_out);	
}
