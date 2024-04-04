/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:56:44 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/04 18:28:37 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clean_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

static size_t get_size_arr(t_word_list *words)
{
	t_word_list	*tmp;
	char		*str;
	size_t		n_word;

	n_word = 0;
	tmp = words;
	while (tmp)
	{
		n_word++ ;
		str = tmp->word;
		while (*str)
			n_word += (*str++ == 31);
		tmp = tmp->next;
	}
	return (n_word);
}

static char	**fill_arr(t_word_list *words, char **arr)
{
	t_word_list	*tmp;
	char		**arr2;
	int			j;
	int			i;

	i = 0;
	tmp = words;
	while (tmp)
	{
		arr2 = ft_split(tmp->word, 31);
		j = 0;
		while (arr2[j] != NULL)
			arr[i++] = arr2[j++];
		free(arr2);
		tmp = tmp->next;
	}
	return (arr);
}

char	**list_to_arr(t_word_list *words)
{
	size_t	n_word;
	char	**arr;

	n_word = get_size_arr(words);
	arr = ft_calloc((n_word + 1), sizeof(char *));
	arr = fill_arr(words, arr);
	return (arr);
}
