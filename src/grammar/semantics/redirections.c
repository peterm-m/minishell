/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 01:08:35 by pedro             #+#    #+#             */
/*   Updated: 2024/01/21 21:29:42 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/* void heredoc(t_dlst **lex, char *delimiter)
{
	char *line;
	char *full_history;
	int		size;
	t_token	*token;

	line = NULL;
	full_history = NULL;
	size = ft_strlen(delimiter);
	full_history = ft_strjoin(full_history, delimiter);
	full_history = ft_strjoin(full_history, "\n");
	while (ft_strncmp(line, delimiter, size) != 0)
	{
		line = readline("heredoc >");
		full_history = ft_strjoin(full_history, line);
		full_history = ft_strjoin(full_history, "\n");
		//free(line);
	}
	//full_history = ft_strjoin(full_history, delimiter);
	token = new_token();
	set_token(full_history, 0, ft_strlen(full_history), tt_dgreat, token);
	ft_dlstaddb(lex, ft_dlstnew(token));
} */

t_redirect	*make_redirection(t_unit_io *source, int type, t_unit_io *dest,
	int flag)
{
	t_redirect	*redirect;

	redirect = (t_redirect *)ft_malloc(sizeof(t_redirect));
	redirect->redirector = *source;
	redirect->redirectee = *dest;
	redirect->here_doc_eof = 0;
	redirect->option = type;
	redirect->flags = 0;
	redirect->rflags = flag;
	redirect->next = (t_redirect *) NULL;
	if (type == r_output_direction)
		redirect->flags = O_TRUNC | O_WRONLY | O_CREAT;
	else if (type == r_appending_to)
		redirect->flags = O_APPEND | O_WRONLY | O_CREAT;
	else if (type == r_input_direction)
		redirect->flags = O_RDONLY;
	else if (type == r_reading_until)
		(void )NULL;
	else
		printf("Error pipeline \n");
	return (redirect);
}

void	clean_redirection(t_redirect *redirection)
{
	if (redirection)
	{
		clean_redirection(redirection->next);
		free(redirection);
	}
}

t_redirect	*join_redir(t_redirect *redir1, t_redirect *redir2)
{
	t_redirect	*tmp;

	if (redir1 == NULL)
		return (redir2);
	tmp = redir1;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = redir2;
	return (redir2);
}
