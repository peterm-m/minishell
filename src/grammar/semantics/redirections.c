/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 01:08:35 by pedro             #+#    #+#             */
/*   Updated: 2024/04/09 19:49:52 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#undef LOGS
#define LOGS 0

t_redirect	*make_redirection(t_unit_io *source, int type, t_unit_io *dest,
	int flag)
{
	t_redirect	*redirect;

	dbg("│\t│\t├─%s\n", "make redir");
	redirect = (t_redirect *)ft_malloc(sizeof(t_redirect));
	redirect->source = *source;
	redirect->dest = *dest;
	redirect->here_doc_eof = 0;
	redirect->option = type;
	redirect->flag = 0;
	redirect->rflags = flag;
	redirect->next = (t_redirect *) NULL;
	if (type == r_output_direction)
		redirect->mode_bits = (O_CREAT | O_TRUNC | O_WRONLY);
	else if (type == r_appending_to)
		redirect->mode_bits = (O_CREAT | O_APPEND | O_WRONLY);
	else if (type == r_input_direction)
		redirect->mode_bits = O_RDONLY;
	else if (type == r_reading_until)
		redirect->mode_bits = 0;
	else
		printf("Error pipeline \n");
	return (redirect);
}

void	clean_redirection(t_redirect **redirection)
{
	t_redirect	*aux;

	dbg("├─%s\n", "clean_redirection");
	while (*redirection)
	{
		aux = (*redirection)->next;
		ft_free((*redirection)->dest.filename);
		ft_free(*redirection);
		*redirection = aux;
	}
}

void	join_redir(t_redirect **redir1, t_redirect *redir2)
{
	t_redirect	*tmp;

	dbg("│\t│\t├─%s\n", "join_redir");
	if (*redir1 == NULL)
	{
		*redir1 = redir2;
		return ;
	}
	tmp = *redir1;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = redir2;
}

char	*make_filename(t_token	*token)
{
	char	*filename;

	dbg("│\t│\t├─%s\n", "make filename");
	if (token == NULL)
		return (NULL);
	filename = token->str;
	ft_free(token);
	return (filename);
}
