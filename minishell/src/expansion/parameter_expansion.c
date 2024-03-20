/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameter_expansion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 20:47:08 by pedromar          #+#    #+#             */
/*   Updated: 2024/03/19 20:21:18 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_parameter(char *word)
{
	int	i;

	i = 0; 
	if (word[i] == '{' || word[i] == '(')
		i++;
	while (word[i] && !in_word(word[i]) && word[i] != '$'
		&& !is_quotes(word[i]) && word[i] != ')' && word[i] != '}')
		i++;
	printf("word a expandir: %s\n", ft_substr(word, 0, i));
	printf("Encuetra en env: %s\n", ft_getenv(ft_substr(word, 0, i)));
	return (ft_getenv(ft_substr(word, 0, i)));
}

static int	is_special_parameter(char *parameter)
{
	(void)parameter;
	return (EXIT_FAILURE);
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

int	parameter_expansion(t_word *word)
{
	char	*parameter;
//	char	*value_var;
	char	*out;

	out = word->word;
	if (*out++ != '$')
		return (EXIT_FAILURE);
	parameter = get_parameter(out);
	if (is_special_parameter(parameter))
		expand_spacial_parameters(parameter, out);
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