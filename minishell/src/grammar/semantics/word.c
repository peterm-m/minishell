/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:05:30 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/03 20:02:05 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#undef LOGS
#define LOGS 0

void	print_word(t_word_list *word)
{
	if (word != NULL)
	{
		fprintf(stderr, "%s,", word->word);
		print_word(word->next);
	}
	else
		fprintf(stderr, "\n");
}

void	clean_word(t_word_list **word)
{
	t_word_list	*aux;

	while (*word)
	{
		aux = (*word)->next;
		ft_free(*word);
		*word = aux;
	}
	dbg("├─%s\n", "clean_word");
}

t_word_list	*make_word(t_token *token)
{
	char		*tmp;
	t_word_list	*new;
	t_word_list	*new2;

	dbg("│\t│\t├─%s\n", "make word");
	if (token == NULL)
		return (NULL);
	expander(token);
	tmp = token->str;
	new = ft_malloc(sizeof(t_word_list));
	if (token->flag & WILDCARD)
	{
		while (tmp != '\0')
		{
			new2 = ft_malloc(sizeof(t_word_list));
			new2->next = NULL;
			new2->word = ft_strdup(tmp);
			tmp += PATH_MAX + 1;
		}
	}
	else
	{
		new->word = token->str;
		new->next = NULL;
	}
	ft_free(token);
	return (new);
}

int	make_number(t_token *word)
{
	int	fd;

	dbg("│\t│\t├─%s\n", "make number");
	if (word == NULL)
		return (-1);
	fd = ft_atoi(word->str);
	free_token(word);
	return (fd);
}

void	join_word(t_word_list **word1, t_word_list *word2)
{
	t_word_list	*tmp;

	dbg("│\t│\t├─%s\n", "join word");
	if (*word1 == NULL)
	{
		*word1 = word2;
		return ;
	}
	tmp = *word1;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = word2;
}
