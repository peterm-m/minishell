/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_simple.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 00:56:44 by pedro             #+#    #+#             */
/*   Updated: 2024/01/06 13:13:05 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_redirection(t_dlst *lex, t_state	*state, int rule)
{
	return ;
}

void	clean_simple_command(t_simple_cmd *cmd)
{
	if (cmd == NULL)
		return ;
	if (cmd->redirects != NULL)
		clean_redirection(cmd->redirects);
	if (cmd->words)
		clean_words(cmd->words);
}

t_command	*make_simple_command(t_command *cmd, t_element *element)
{
	return (cmd);
}

//COMMAND *
//make_bare_simple_command ()
//{
//  COMMAND *command;
//  SIMPLE_COM *temp;
//
//  command = (COMMAND *)xmalloc (sizeof (COMMAND));
//  command->value.Simple = temp = (SIMPLE_COM *)xmalloc (sizeof (SIMPLE_COM));
//
//  temp->flags = 0;
//  temp->line = line_number;
//  temp->words = (WORD_LIST *)NULL;
//  temp->redirects = (REDIRECT *)NULL;
//
//  command->type = cm_simple;
//  command->redirects = (REDIRECT *)NULL;
//  command->flags = 0;
//
//  return (command);
//}


//t_command	*make_simple_command(t_command *cmd, t_element *element)
//{
//	if (cmd == NULL)
//	{
//	  cmd = make_bare_simple_command ();
//	  //parser_state& |= PST_REDIRLIST;
//	}
//  if (element.word)
//    {
//      command->value.Simple->words = make_word_list (element.word, command->value.Simple->words);
//      parser_state &= ~PST_REDIRLIST;
//    }
//  else if (element.redirect)
//    {
//      REDIRECT *r = element.redirect;
//      while (r->next)
//	r = r->next;
//      r->next = command->value.Simple->redirects;
//      command->value.Simple->redirects = element.redirect;
//    }
//
//  return (command);
//}