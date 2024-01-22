/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_simple.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 00:56:44 by pedro             #+#    #+#             */
/*   Updated: 2024/01/21 21:19:37 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clean_simple(t_simple_cmd *cmd)
{
	if (cmd == NULL)
		return ;
	clean_word(cmd->words);
	clean_redirection(cmd->redirects);
	free(cmd);
}

t_command	*make_simple(t_element *element1, t_token *word,
	t_element *element2)
{
	t_simple_cmd	*simple;

	simple = (t_simple_cmd *)ft_malloc(sizeof(t_simple_cmd));
	if (element1 != NULL)
	{
		simple->redirects = join_redir(simple->redirects, element1->redirect);
		simple->words = join_word(simple->words, element1->word);
	}
	if (word != NULL )
		simple->words = join_word(element1->word, make_word(word));
	if (element2 != NULL)
	{
		simple->redirects = join_redir(simple->redirects, element2->redirect);
		simple->words = join_word(simple->words, element2->word);
	}
	return (make_command(cmd_simple, (t_node)simple));
}
