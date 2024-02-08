/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_simple.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 00:56:44 by pedro             #+#    #+#             */
/*   Updated: 2024/02/08 20:16:28 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#undef LOGS 
#define LOGS 1

void	print_simple(t_simple *cmd)
{
	fprintf(stderr,"simple cmd: flag %d\nword: ", cmd->flags);
	print_word(cmd->words);
	fprintf(stderr,"redir: \n");
}

void	clean_simple(t_simple *cmd)
{dbg("│\t│\t├─%s\n","clean_simple");
	if (cmd == NULL)
		return ;
	if (cmd->words != NULL)
		clean_word(cmd->words);
	if (cmd->redirects != NULL)
		clean_redirection(cmd->redirects);
	ft_free(cmd);
}

t_command	*make_simple(t_element *prefix, t_word_list *word,
	t_element *suffix)
{dbg("│\t│\t├─%s\n","make simple");
	t_element		*aux;
	t_simple	*simple;

	simple = (t_simple *)ft_malloc(sizeof(t_simple));
	simple->redirects = NULL;
	simple->words = NULL;
	aux = make_element(simple->words ,simple->redirects);
	aux = join_element(aux, prefix);
	aux->word = join_word(aux->word, word);
	aux = join_element(aux, suffix);
	simple->redirects = aux->redirect;
	simple->words = aux->word;
	ft_free(aux);
	return (make_command(cmd_simple, (t_node)simple));
}
#undef LOGS
#define LOGS 1
