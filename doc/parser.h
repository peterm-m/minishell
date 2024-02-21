/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 22:28:25 by pedro             #+#    #+#             */
/*   Updated: 2024/02/21 15:21:41 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H 
# define PARSER_H

/* Instructis_ons describing what kind of thing to do for a redirection. */
typedef enum e_rinstructis
{
  r_output_direction, 
  r_input_direction, 
  r_inputa_direction,
  r_appending_to, 
  r_reading_until, 
  r_reading_string,
  r_duplicating_input, 
  r_duplicating_output, 
  r_deblank_reading_until,
  r_close_this, 
  r_err_and_out, 
  r_input_output, 
  r_output_force,
  r_duplicating_input_word, 
  r_duplicating_output_word,
  r_move_input, 
  r_move_output, 
  r_move_input_word, 
  r_move_output_word,
  r_append_err_and_out
}	t_rinstructis;

/* Command Types: */
typedef enum e_command_type
{
	cm_simple,
	cm_connection,
	cm_group,
	cm_subshell
}  t_command_type;

/* Zero terminated string. */
/* Flags associated with this word. */
typedef struct s_word_desc
{
	char	*word;
	int		flags;
}	t_word_desc;

typedef struct s_word_list
{
  struct s_word_list *next;
  t_word_desc *word;
} t_word_list;

/* What a redirection descriptor looks like.  If the redirection instructis_on
   is ri_duplicating_input or ri_duplicating_output, use DEST, otherwise
   use the file in FILENAME.  Out-of-range descriptors are identified by a
   negative DEST. */
/* Place to redirect t_redirect to, or ... */
/* filename to redirect to. */

typedef union u_redirectee
{
	int			dest;
	t_word_desc	*filename;
} t_redirectee;

/* Structure describing a redirection.  If t_redirect is negative, the parser
   (or translator in redir.c) encountered an out-of-range file descriptor. */
/* Descriptor or varname to be redirected. */
/* Private flags for this redirection */
/* Flag vaxlue for `open'. */
/* What to do with the information. */
/* File descriptor or filename */
/* The word that appeared in <<foo. */
/* Next element, or NULL. */

typedef struct s_redirect
{
	t_redirectee		source;
	int					rflags;
	int					flags;
	t_rinstructis 		instructis_on;
	t_redirectee		redirectee;
	char				*here_doc_eof;
	struct	s_redirect	*next;
} t_redirect;

/* An element used in parsing.  A single word or a single redirection.
   This is an ephemeral construct.s_ */
typedef struct s_element
{
  t_word_desc	*word;
  t_redirect	*redirect;
} t_element;

typedef union u_value
{
  struct s_connection	*connection;
  struct s_simple_com	*simple;
  struct s_group_com	*group;
  struct s_subshell_com	*subshell;
}	t_value;

/* What a command looks like. */
/* Flags controlling execution environment. */
/* line number the command starts on */
/* Special redirects for FOR CASE, etc. */
typedef struct s_command
{
	t_command_type	type;
	int				flags;
	int				line;
	t_value	  		value;
	t_redirect		*redirects;
} t_command;

/* Structure used to represent the CONNECTION type. */
/* Unused; simplifies make_command (). */
/* Pointer to the first command. */
/* Pointer to the second command. */
/* What separates this command from others. */
typedef struct s_connection
{
	int			ignore;
	t_command	*first;
	t_command	*second;
	int			connector;
} t_connection;

/* The "simple" command.  Just a collection of words and redirects. */
/* See description of CMD flags. */
/* line number the command starts on */
/* The program name, the arguments, variable assignments, etc. */
/* Redirections to perform. */
typedef struct s_simple_com
{
	int			flags;
	int			line;
	t_word_list	*words;
	t_redirect	*redirects;
} t_simple_com;

/* A command that is `grouped' allows pipes and redirections to affect all
   commands in the group. */
typedef struct s_group_com
{
	int ignore;
	t_command *command;
} t_group_com;

typedef struct s_subshell_com
{
	int			flags;
	int			line;
  	t_command	*command;
} t_subshell_com;

#endif