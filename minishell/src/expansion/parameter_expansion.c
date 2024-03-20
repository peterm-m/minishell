/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameter_expansion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 20:47:08 by pedromar          #+#    #+#             */
/*   Updated: 2024/03/20 20:02:18 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_parameter(char *word)
{
	int	i;
	int	brace;

	brace = FALSE;
	i = 0; 
	if (word[i] == '{' || word[i] == '(')
	{
		i++;
		brace = TRUE;
	}
	printf("word a buscar: %s\n", word);
	while (word[i] && !in_word(word[i])
		&& !is_quotes(word[i]) && word[i] != ')' && word[i] != '}')
			i++;
	if (brace == TRUE)
		printf("word a expandir: %s\n", ft_substr(word, 1, i - 1));
	else
		printf("word a expandir: %s\n", ft_substr(word, 0, i));
	//printf("Encuetra en env: %s\n", ft_getenv(ft_substr(word, 0, i)));
	if (brace == TRUE)
		return (ft_substr(word, 1, i - 1));
	return (ft_substr(word, 0, i));
}

static int	is_special_parameter(char *parameter)
{
	if (ft_strchr("*@#?-$!0", parameter[0]) == 0)
		return (FALSE);
	return (TRUE);
}

static int	is_valid_identifier(char *parameter)
{
	(void)parameter;
	return (EXIT_FAILURE);
}

static int	expand_spacial_parameters(char *parameter, char *word)
{
	(void)parameter;
	(void)word;
	return (EXIT_FAILURE);
}

int	parameter_expansion(t_word_list *word)
{
	char	*parameter;
//	char	*value_var;
	char	*out;

	out = word->word;
	if (*out++ != '$')
		return (EXIT_FAILURE);
	parameter = get_parameter(out);
	if (is_special_parameter(parameter))
		printf("Parametro especial: %s\n", parameter);
		//expand_spacial_parameters(parameter, out);
	else if (is_valid_identifier(parameter))
		(void) 0;//expand_parameters(parameter, out); TODO
	else
	{
		// TODO: gestionar fallo
		return (EXIT_FAILURE);
	}
	ft_free(word->word);
	word->word = out;
	return (EXIT_SUCCESS);
}

// TODO: identificador valido
//			ejemplo no valido 11111