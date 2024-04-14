/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:56:58 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/13 21:02:46 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYNTAX_H
# define SYNTAX_H

# include "minishell.h"

int			redirection_token(t_dlst **lex);
t_terminals	type_token(t_dlst **lex);
t_token		*pop_token(t_dlst **lex);

typedef enum e_rtype
{
	r_output_direction,
	r_input_direction,
	r_appending_to,
	r_reading_until
}	t_rtype;

typedef union u_unit_io
{
	int			fd;
	char		*filename;
}	t_unit_io;

typedef struct s_redirect
{
	t_unit_io			source;
	t_unit_io			dest;
	t_rtype				rtype;
	int					mode_bits;
	int					flags_bits;
	char				*here_doc_eof;
	struct s_redirect	*next;
}	t_redirect;

t_redirect	*make_redirection(t_dlst **lex);
int			add_redirection(t_redirect **redir_list, t_dlst **lex);
void		clean_redirection(t_redirect **redirection);

typedef struct s_word
{
	char			*word;
	struct s_word	*next;
}	t_word;

t_word		*make_word(t_dlst **lex);
int			add_word(t_word **word_list, t_dlst **lex);
void		clean_word(t_word **word);

typedef enum e_command_type
{
	cmd_simple,
	cmd_connection,
	cmd_subshell
}	t_command_type;

typedef union u_node
{
	struct s_connection	*connection;
	struct s_simple		*simple;
	struct s_subshell	*subshell;
}	t_node;

typedef struct s_command
{
	t_command_type	type;
	int				flag;
	t_node			value;
	t_redirect		*redirects;
}	t_command;

typedef struct s_simple
{
	int			flags;
	t_word		*words;
	t_redirect	*redirects;
}	t_simple;

t_command	*make_simple(t_dlst **lex);

typedef struct s_connection
{
	int			ignore;
	t_command	*first;
	t_command	*second;
	int			connector;
}	t_connection;

typedef struct s_subshell
{
	int			flags;
	t_command	*command;
}	t_subshell;

t_command	*make_subshell(t_dlst **lex);

int			new_command(t_command_type type, t_command **out);
void		clean_command(t_command *cmd);

t_command	*syntax(t_dlst **lex);
t_command	*parser_error(t_dlst **lex, t_command *command);

#endif
