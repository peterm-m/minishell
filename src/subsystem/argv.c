/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:56:44 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/08 16:06:56 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_copyarg(char **argv)
{
	size_t	size_env;
	char	**new_env;

	size_env = 0;
	while (environ[size_env] != NULL)
		size_env++;
	new_env = malloc((size_env +1) * sizeof(char **));
	if (new_env == NULL)
		return (NULL);
	new_env[size_env] = environ[size_env];
	size_env--;
	while (--size_env > 0)
	{
		new_env[size_env] = ft_strdup(environ[size_env]);
		if (new_env[size_env] == NULL)
		{
			while (environ[++size_env] != NULL)
				ft_free(new_env[size_env]);
			ft_free(new_env);
			return (NULL);
		}
	}
	return (new_env);
}

void	clean_argv(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	ft_free(arr[i++]);
ft_free(arr);
}

static size_t	get_size_argv(t_word_list *words)
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
	ft_free(arr2);
		tmp = tmp->next;
	}
	return (arr);
}

char	**list_to_argv(t_word_list *words)
{
	size_t	n_word;
	char	**arr;

	n_word = get_size_argv(words);
	arr = ft_calloc((n_word + 1), sizeof(char *));
	arr = fill_arr(words, arr);
	return (arr);
}
