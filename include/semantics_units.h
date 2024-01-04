/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semantics_units.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:21:43 by pedro             #+#    #+#             */
/*   Updated: 2024/01/05 00:00:03 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEMANTICS_UNITS_H
# define SEMANTICS_UNITS_H

# include "minishell.h"

/* Instructions describing what kind of thing to do for a redirection. */
typedef enum e_rinstructis
{
	r_output_direction,
	r_input_direction,
	r_appending_to,
	r_reading_until
}	t_roption;

typedef struct s_word_desc
{
	char	*word;
	int		flags;
}	t_word_desc;

typedef struct s_word_list
{
	t_word_desc			*word;
	struct s_word_list	*next;
} t_word_list;

typedef union u_unit_io
{
	int			dest;
	t_word_desc	*filename;
} t_unit_io;

/*
 Structure describing a redirection.
 	Descriptor or varname to be redirected.
 	Flags for this redirection
 	Flag vaxlue for open.
 	What to do with the information.
 	File descriptor or filename
 	The word that appeared in <<foo.
 	Next element, or NULL.
*/

typedef struct s_redirect
{
	t_unit_io			redirector;
	int					rflags;
	int					flags;
	t_roption			instructis_on;
	t_unit_io			redirectee;
	char				*here_doc_eof;
	struct s_redirect	*next;
} t_redirect;

/*
  An element used in parsing. 
  A single word or a single redirection.
  This is an ephemeral construct.
*/
typedef struct s_element
{
	t_word_list	*word;
	t_redirect	*redirect;
} t_element;

/* Command Types */
typedef enum e_command_type
{
	cmd_simple,
	cmd_connection,
	cmd_group,
	cmd_subshell
}  t_command_type;

/* Nodes Types */
typedef union u_node
{
	struct s_connection		*connection;
	struct s_simple_cmd		*simple;
	struct s_group_cmd		*group;
	struct s_subshell_cmd	*subshell;
}	t_node;

/*
  Command looks like.
	Command type
	Flags controlling execution environment
	Special redirects
*/
typedef struct s_command
{
	t_command_type	type;
	int				flags;
	t_node			value;
	t_redirect		*redirects;
} t_command;

/*
Connection.
	What separates this command from other

	Auxiliar
	Pointer to the first command. 
	Pointer to the second command. 
*/
typedef struct s_connection
{
	int			ignore;
	t_command	*first;
	t_command	*second;
	int			connector;
} t_connection;

/*
Simple command.
	Collection of words and redirects.

	Flags.
	Name, Arguments, Variable assignments, etc.
	Redirections to perform.
*/
typedef struct s_simple_cmd
{
	int			flags;
	t_word_list	*words;
	t_redirect	*redirects;
} t_simple_cmd;

/*
Group:
	Allows pipes and redirections to affect all commands in the group.
*/
typedef struct s_group_cmd
{
	int ignore;
	t_command *command;
} t_group_cmd;

/*
Subshell:
	Cmd in subshell
*/
typedef struct s_subshell_cmd
{
	int			flags;
	int			line;
  	t_command	*command;
} t_subshell_cmd;

t_connection	*make_conection(t_command *cmd1, t_command *cmd2, int type);
t_command	*make_group(t_command *cmd);
void	make_simple_command(t_dlst *lex, t_state *state, int rule);
void	set_redirection(t_dlst *lex, t_state *state, int rule);
t_command	*make_subshell(t_command *cmd);
void	make_element(t_dlst *lex, t_state	*state, int rule);
void	append_element(t_dlst *lex, t_state *state, int rule);
void	append_redir(t_redirect *redir1, t_redirect *redir2);
void	make_redirection(t_dlst *lex, t_state	*state, int rule);
void	join_redirection(t_dlst *lex, t_state	*state, int rule);

#endif