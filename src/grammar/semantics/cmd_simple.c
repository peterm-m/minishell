/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_simple.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 00:56:44 by pedro             #+#    #+#             */
/*   Updated: 2024/01/24 23:22:24 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clean_simple(t_simple_cmd *cmd)
{
	dbg("%s\n","");
	if (cmd == NULL)
		return ;
	clean_word(cmd->words);
	clean_redirection(cmd->redirects);
	free(cmd);
}

t_command	*make_simple(t_element *element1, t_token *word,
	t_element *element2)
{
	dbg("%s\n","");
	t_simple_cmd	*simple;

	simple = (t_simple_cmd *)ft_malloc(sizeof(t_simple_cmd));
	if (element1 != NULL)
	{dbg("%s\n","");
		simple->redirects = join_redir(simple->redirects, element1->redirect);
		simple->words = join_word(simple->words, element1->word);
	}
	if (word != NULL)
	{dbg("%d\n",word->flag);
		simple->words = join_word(simple->words, make_word(word));
	}
	if (element2 != NULL)
	{dbg("%s\n","");
		simple->redirects = join_redir(simple->redirects, element2->redirect);
		simple->words = join_word(simple->words, element2->word);
	}
	return (make_command(cmd_simple, (t_node)simple));
}
