/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semantics.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:21:43 by pedro             #+#    #+#             */
/*   Updated: 2024/01/08 21:29:12 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEMANTICS_H
# define SEMANTICS_H

# include "minishell.h"

/*
	UTILS
*/

typedef struct s_word
{
	char	*word;
	int		flags;
}	t_word;

typedef struct s_word_list
{
	t_word			*word;
	struct s_word_list	*next;
} t_word_list;

/*
	REDIRECTIONS
*/

/* Type of redirection */
typedef enum e_redir_option
{
	r_output_direction,
	r_input_direction,
	r_appending_to,
	r_reading_until
}	t_redir_option;

/* filename or file descriptor */
typedef union u_unit_io
{
	int			dest;
	t_word		*filename;
}	t_unit_io;

/* Structure describing a redirection. */
typedef struct s_redirect
{
	t_unit_io			redirector;
	t_unit_io			redirectee;
	int					rflags;
	int					flags;
	t_redir_option		option;
	char				*here_doc_eof;
	struct s_redirect	*next;
} t_redirect;

/* Auxiliar */
typedef struct s_element
{
	t_word_list	*word;
	t_redirect	*redirect;
} t_element;

/* Command Types ID*/
typedef enum e_command_type
{
	cmd_simple,
	cmd_connection,
	cmd_group,
	cmd_subshell
}  t_command_type;

/* Command Types */
typedef union u_node
{
	struct s_connection		*connection;
	struct s_simple_cmd		*simple;
	struct s_group_cmd		*group;
	struct s_subshell_cmd	*subshell;
}	t_node;

/* Command */
typedef struct s_command
{
	t_command_type	type;
	int				flags;
	t_node			value;
	t_redirect		*redirects;
} t_command;

/* Connection */
typedef struct s_connection
{
	int			ignore;
	t_command	*first;
	t_command	*second;
	int			connector;
} t_connection;

/* Simple command */
typedef struct s_simple_cmd
{
	int			flags;
	t_word_list	*words;
	t_redirect	*redirects;
} t_simple_cmd;

/* Group */
typedef struct s_group_cmd
{
	int ignore;
	t_command *command;
} t_group_cmd;

/* Subshell */
typedef struct s_subshell_cmd
{
	int			flags;
  	t_command	*command;
} t_subshell_cmd;

t_command		*make_command(t_command_type type, t_node value);
void			clean_command(t_command *cmd);

t_redirect		*make_redirection(t_unit_io *source, int type, t_unit_io *dest,int flag);
void			join_redir(t_redirect **redir1, t_redirect *redir2);
void			clean_redirection(t_redirect *redirection);

t_command		*make_connection(t_command *cmd1, t_command *cmd2, int type);
void			clean_connection(t_connection *connection);

t_command		*make_group(t_command *cmd);
void			clean_group(t_group_cmd *group);

t_command		*make_subshell(t_command *cmd);
void			clean_subshell(t_subshell_cmd *subshell);

t_command		*make_simple(t_command *cmd, t_element *element);
void			clean_simple(t_simple_cmd *cmd);

t_element		*make_element(t_dlst *lex, t_state	*state, int rule);

void			set_redirection(t_dlst *lex, t_state *state, int rule);

t_word_list	*make_word_list(t_word	*word, t_word_list *w_list);

#endif