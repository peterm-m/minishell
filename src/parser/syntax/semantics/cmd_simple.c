/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_simple.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 00:56:44 by pedro             #+#    #+#             */
/*   Updated: 2024/01/08 20:39:43 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//void	set_redirection(t_dlst *lex, t_state	*state, int rule)
//{
//	return ;
//}

void	clean_simple(t_simple_cmd *cmd)
{
	if (cmd == NULL)
		return ;
//	if (cmd->redirects != NULL)
//		clean_redirection(cmd->redirects);
//	if (cmd->words)
//		clean_words(cmd->words);
}

static t_command	*make_simple_empty(void)
{
	t_command 	*command;
	t_simple_cmd *temp;

	command = (t_command *)ft_malloc(sizeof(t_command));
	temp = (t_simple_cmd *)ft_malloc(sizeof(t_simple_cmd));
	command->value.simple = temp;
	temp->flags = 0;
	temp->words = (t_word_list *) NULL;
	temp->redirects = (t_redirect *)NULL;
	command->type = cmd_simple;
	command->redirects = (t_redirect *)NULL;
	command->flags = 0;
	return (command);
}


t_command	*make_simple(t_command *cmd, t_element *element)
{
	t_redirect *redirection;

	if (cmd == NULL)
		cmd = make_simple_empty();
	//if (element->word)
		//(cmd->value).simple->words = make_word_list(element->word, cmd->value.simple->words);
	else if (element->redirect)
	{
		redirection = element->redirect;
		while (redirection->next)
			redirection = redirection->next;
		redirection->next = cmd->value.simple->redirects;
		cmd->value.simple->redirects = element->redirect;
	}
	return (cmd);
}
