/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_simple.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 00:56:44 by pedro             #+#    #+#             */
/*   Updated: 2024/03/20 20:58:09 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#undef LOGS 
#define LOGS 0

void	print_simple(t_simple *cmd)
{
	fprintf(stderr, "simple cmd: flag %d\nword: ", cmd->flags);
	print_word(cmd->words);
	fprintf(stderr, "redir: \n");
}

void	clean_simple(t_simple *cmd)
{
	if (cmd == NULL)
		return ;
	if (cmd->words != NULL)
		clean_word(&(cmd->words));
	if (cmd->redirects != NULL)
		clean_redirection(&(cmd->redirects));
	ft_free(cmd);
	dbg("├─%s\n", "clean_simple");
}

t_command	*make_simple(t_element *prefix, t_word_list *word,
	t_element *suffix)
{
	t_simple	*simple;

	dbg("│\t│\t├─%s\n", "make simple");
	simple = (t_simple *)ft_malloc(sizeof(t_simple));
	simple->redirects = NULL;
	simple->words = NULL;
	if (prefix != NULL)
	{
		join_word(&(simple->words), prefix->word);
		join_redir(&(simple->redirects), prefix->redirect);
		ft_free(prefix);
	}
	if (word != NULL)
		join_word(&(simple->words), word);
	if (suffix != NULL)
	{
		join_word(&(simple->words), suffix->word);
		join_redir(&(simple->redirects), suffix->redirect);
		ft_free(suffix);
	}
	return (make_command(cmd_simple, (t_node)simple));
}

#undef LOGS
#define LOGS 0
