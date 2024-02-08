/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 01:08:35 by pedro             #+#    #+#             */
/*   Updated: 2024/02/08 02:01:03 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#undef LOGS
#define LOGS 1

t_redirect	*make_redirection(t_unit_io *source, int type, t_unit_io *dest,
	int flag)
{dbg("│\t│\t├─%s\n","make redir");
	t_redirect	*redirect;

	redirect = (t_redirect *)ft_malloc(sizeof(t_redirect));
	redirect->redirector = *source;
	redirect->redirectee = *dest;
	redirect->here_doc_eof = 0;
	redirect->option = type;
	redirect->flag = 0;
	redirect->rflags = flag;
	redirect->next = (t_redirect *) NULL;
	if (type == r_output_direction)
		redirect->mode_bits = O_TRUNC | O_WRONLY | O_CREAT;
	else if (type == r_appending_to)
		redirect->mode_bits = O_APPEND | O_WRONLY | O_CREAT;
	else if (type == r_input_direction)
		redirect->mode_bits = O_RDONLY;
	else if (type == r_reading_until)
		(void )NULL;
	else
		printf("Error pipeline \n");
	return (redirect);
}

void	clean_redirection(t_redirect *redirection)
{
	if (redirection != NULL)
	{
		clean_redirection(redirection->next);
		ft_free(redirection);
	}
	dbg("│\t│\t├─%s\n","clean_redirection");
}

t_redirect	*join_redir(t_redirect *redir1, t_redirect *redir2)
{
	dbg("│\t│\t├─%s\n","join_redir");
	t_redirect	*tmp;

	if (redir1 == NULL)
		return (redir2);
	tmp = redir1;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = redir2;
	return (redir1);
}

int		make_io_number(t_token *io_number)
{dbg("│\t│\t├─%s\n", "make io_number");
	int	fd;

	if (io_number == NULL)
		return (0);
	fd = ft_atoi(io_number->str);

	return (fd);
}