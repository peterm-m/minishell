/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:15:10 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/13 11:51:59 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_redirect	*new_redirection(void)
{
	t_redirect	*redir;

	redir = malloc(sizeof(t_redirect));
	redir->source.fd = STDIN_FILENO;
	redir->dest.fd = STDOUT_FILENO;
	redir->here_doc_eof = NULL;
	redir->rtype = 0;
	redir->flags_bits = (S_IWUSR | S_IRUSR | S_IRGRP | S_IROTH);
	redir->next = NULL;
	return (redir);
}

static void	fill_redirection(t_redirect *redir, t_token *io_number,
			t_token *type, t_token *word)
{
	if (io_number)
	{
		redir->source.fd = ft_atoi(io_number->str);
		free_token(io_number);
	}
	if ((type->flag & TOK_TYPE) == tt_great)
		redir->rtype = r_output_direction;
	else if ((type->flag & TOK_TYPE) == tt_dgreat)
		redir->rtype = r_appending_to;
	else if ((type->flag & TOK_TYPE) == tt_less)
		redir->rtype = r_input_direction;
	else if ((type->flag & TOK_TYPE) == tt_dless)
		redir->rtype = r_reading_until;
	if (redir->rtype == r_output_direction)
		redir->mode_bits = (O_CREAT | O_TRUNC | O_WRONLY);
	else if (redir->rtype == r_appending_to)
		redir->mode_bits = (O_CREAT | O_APPEND | O_WRONLY);
	else if (redir->rtype == r_input_direction)
		redir->mode_bits = O_RDONLY;
	else if (redir->rtype == r_reading_until)
		redir->dest.filename = heredoc(word->str);
	redir->dest.filename = word->str;
	ft_free(word);
	ft_free(type);
}

static void	read_redirection(t_dlst **lex, t_token **io_number,
				t_token **type, t_token **word)
{
	if (token_type(lex) == tt_io_number)
		*io_number = pop_token(lex);
	if (token_type(lex) == tt_dgreat || token_type(lex) == tt_great
		|| token_type(lex) == tt_dless || token_type(lex) == tt_less)
		*type = pop_token(lex);
	if (token_type(lex) == tt_word)
	{
		*word = pop_token(lex);
		expander(*word);
	}
}

t_redirect	*make_redirection(t_dlst **lex)
{
	t_token		*io_number;
	t_token		*type;
	t_token		*word;
	t_redirect	*redir;

	io_number = NULL;
	type = NULL;
	word = NULL;
	redir = new_redirection();
	if (redir == NULL)
		return (NULL);
	read_redirection(lex, &io_number, &type, &word);
	if (!type || !word)
	{
		if (io_number)
			free_token(io_number);
		if (type)
			free_token(type);
		if (word)
			free_token(word);
		ft_free(redir);
		return (NULL);
	}
	fill_redirection(redir, io_number, type, word);
	return (redir);
}

void	add_redirection(t_redirect **redir_list, t_redirect *new)
{
	t_redirect	*tmp;

	if (*redir_list == NULL)
	{
		*redir_list = new;
		return ;
	}
	tmp = *redir_list;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

void	clean_redirection(t_redirect **redirection)
{
	t_redirect	*aux;

	while (*redirection)
	{
		aux = (*redirection)->next;
		ft_free((*redirection)->dest.filename);
		ft_free(*redirection);
		*redirection = aux;
	}
}