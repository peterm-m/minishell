/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semantics.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:21:43 by pedro             #+#    #+#             */
/*   Updated: 2024/03/25 18:14:43 by adiaz-uf         ###   ########.fr       */
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
	char				*word;
	char				*expansion;
	struct s_word_list	*next;
}	t_word_list;

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
	int			fd;
	char		*filename;
}	t_unit_io;

/* Structure describing a redirection. */
typedef struct s_redirect
{
	t_unit_io			source;
	t_unit_io			dest;
	int					rflags;
	int					mode_bits;
	int					flag;
	t_redir_option		option;
	char				*here_doc_eof;
	struct s_redirect	*next;
}	t_redirect;

/* Auxiliar */
typedef struct s_element
{
	t_word_list	*word;
	t_redirect	*redirect;
}	t_element;

/* Command Types ID*/
typedef enum e_command_type
{
	cmd_simple,
	cmd_connection,
	cmd_group,
	cmd_subshell
}	t_command_type;

/* Command Types */
typedef union u_node
{
	struct s_connection	*connection;
	struct s_simple		*simple;
	struct s_group		*group;
	struct s_subshell	*subshell;
}	t_node;

/* Command */
typedef struct s_command
{
	t_command_type	type;
	int				flag;
	t_node			value;
	t_redirect		*redirects;
}	t_command;

/* Connection */
typedef struct s_connection
{
	int			ignore;
	t_command	*first;
	t_command	*second;
	int			connector;
}	t_connection;

/* Simple command */
typedef struct s_simple
{
	int			flags;
	t_word_list	*words;
	t_redirect	*redirects;
}	t_simple;

/* Group */
typedef struct s_group
{
	int			ignore;
	t_command	*command;
}	t_group;

/* Subshell */
typedef struct s_subshell
{
	int			flags;
	t_command	*command;
}	t_subshell;

t_command		*make_command(t_command_type type, t_node value);
void			clean_command(t_command *cmd);
void			print_command(t_command *cmd);
t_command		*join_command_redir(t_command *cmd, t_redirect *redir);

t_redirect		*make_redirection(t_unit_io *source, int type, t_unit_io *dest,
					int flag);
void			clean_redirection(t_redirect **redirection);
void			print_redirection(t_redirect *redirection);
void			join_redir(t_redirect **redir1, t_redirect *redir2);
char			*make_filename(t_token	*token);

t_word_list		*make_word(t_token *word);
int				make_number(t_token *word);
void			clean_word(t_word_list **word);
void			print_word(t_word_list *word);
void			join_word(t_word_list **word1, t_word_list *word2);

t_command		*make_connection(t_command *cmd1, t_command *cmd2, int type);
void			clean_connection(t_connection *connection);
void			print_connection(t_connection *connection);

t_command		*make_group(t_command *cmd);
void			clean_group(t_group *group);
void			print_group(t_group *group);

t_command		*make_subshell(t_command *cmd);
void			clean_subshell(t_subshell *subshell);
void			print_subshell(t_subshell *subshell);

t_command		*make_simple(t_element *prefix, t_word_list *word,
					t_element *suffix);
void			clean_simple(t_simple *cmd);
void			print_simple(t_simple *cmd);

t_element		*join_element(t_element *element1, t_element *element2);
t_element		*make_element(t_word_list *word, t_redirect *redir);
void			clean_element(t_element	*element);

#endif