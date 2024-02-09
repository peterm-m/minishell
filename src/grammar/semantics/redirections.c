/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 01:08:35 by pedro             #+#    #+#             */
/*   Updated: 2024/02/09 18:24:15 by pedromar         ###   ########.fr       */
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
{	dbg("│\t│\t├─%s\n","clean_redirection");
	if (redirection != NULL)
	{
		clean_redirection(redirection->next);
		ft_free(redirection->redirectee.filename);
		ft_free(redirection);
	}
}

void	join_redirection(t_redirect **redir1, t_redirect *redir2)
{dbg("│\t│\t├─%s\n", "join _redirection");
	t_redirect	*tmp;
	
	if (*redir1 == NULL)
		*redir1 = redir2;
	else
	{
		tmp = *redir1;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = redir2;
	}
}

char	*make_filename(t_token	*token)
{dbg("│\t│\t├─%s\n", "make filename");
	char	*filename;

	if (token == NULL)
		return (NULL);
	filename = token->str;
	ft_free(token);
	return (filename);
}
