/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_simple.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 00:56:44 by pedro             #+#    #+#             */
/*   Updated: 2024/01/30 20:36:53 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#undef LOGS 
#define LOGS 0

void	clean_simple(t_simple_cmd *cmd)
{
	dbg("%s\n","");
	if (cmd == NULL)
		return ;
	clean_word(cmd->words);
	clean_redirection(cmd->redirects);
ft_free(cmd);
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
	{dbg("%s\n","");
		simple->words = join_word(simple->words, make_word(word));
	}
	if (element2 != NULL)
	{dbg("%s\n","");
		simple->redirects = join_redir(simple->redirects, element2->redirect);
		simple->words = join_word(simple->words, element2->word);
	}
	return (make_command(cmd_simple, (t_node)simple));
}
#undef LOGS
#define LOGS 1