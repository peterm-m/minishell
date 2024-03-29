/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameter_expansion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 20:47:08 by pedromar          #+#    #+#             */
/*   Updated: 2024/03/25 20:07:47 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_parameter(char **word)
{
	int	i;
	int	brace;
	char *param;
	char *word2;

	brace = FALSE;
	i = 0; 
	word2 = ft_strjoin("", *word);
	printf("word a buscar: %s\n", *word);
	printf("COPIA de word a buscar: %s\n", word2);
 	if (word2[i] == '{' || word2[i] == '(')
	{
		printf("HAY BRAKETS\n");
		brace = TRUE;
		i++;
	}
	while (word2[i] && !in_word(word2[i]) && word2[i] != '$'
		&& !is_quotes(word2[i]) && word2[i] != ')' && word2[i] != '}')
			i++;
 	if (brace == TRUE)
		param = ft_substr(word2, 0, i + 1);
	else
		param = ft_substr(word2, 0, i);
	free(word2);
	return (param);
}

static int	is_special_parameter(char *parameter)
{
	char	*param;

	param = NULL;
	if (parameter[0] == '{' || parameter[0] == '(')
		param = ft_substr(parameter, 1, ft_strlen(parameter) - 2);
	else
		param = ft_strdup(parameter);
	if (ft_strchr("*@#?-$!0", param[0]) == 0)
	{
		free(param);
		return (FALSE);
	}
	free(param);
	return (TRUE);
}

static int	is_valid_identifier(char *parameter)
{
	(void)parameter;
	return (TRUE);
}

static int	expand_spacial_parameters(char *parameter, char **word)
{
	(void)parameter;
	*word = ft_strjoin(*word, parameter);
	printf("word expanded: %s\n", *word);
	return (1);
}

static int	expand_parameters(char *parameter, char **word)
{
	char	*tmp;
	char	size;
	char	*param;
	char	*after_param;
	char	*before_param;
	
	printf("param: %s\n", parameter);
	size =  ft_strlen(*word) + ft_strlen(ft_getenv(parameter)) - ft_strlen(parameter) + 1;
	tmp = ft_strnstr(*word, parameter, ft_strlen(*word));
	//printf("TMP: %s\n", tmp);
	before_param = ft_substr(*word, 0, ft_strlen(*word) - ft_strlen(tmp));
	//printf("before_param: %s\n", before_param);
	after_param = ft_strdup(*word + ft_strlen(parameter));
	//printf("after_param: %s\n", after_param);
	if (parameter[0] == '{' || parameter[0] == '(')
		param = ft_substr(parameter, 1, ft_strlen(parameter) - 2);
	else
		param = ft_strdup(parameter);
	if (!ft_getenv(parameter))
	{
		*word = ft_strjoin(before_param, "");
		*word = ft_strjoin(*word, after_param);
		return (1);
	}
	*word = ft_strjoin(before_param, ft_getenv(param));
	*word = ft_strjoin(*word, after_param);
	printf("word expanded en expand paramteer: %s\n", *&word[0]);
	return (1);
}

int	parameter_expansion(t_word_list *word)
{
	char	*parameter;
	char	*out;

	out = word->word;
	printf("word al entrar en param_expansion: %s\n", &word->word[0]);
	if (*out != '$')
		return (EXIT_FAILURE);
	out++;
	parameter = get_parameter(&out);
	printf("Salida GET_PARAMETER: %s\n", parameter);
	printf("OUT en Salida GET_PARAMETER: %s\n", out);
	if (is_special_parameter(parameter))
		expand_spacial_parameters(parameter, &out);
	else if (is_valid_identifier(parameter))
		expand_parameters(parameter, &out);
	else
	{
		// TODO: gestionar fallo
		return (EXIT_FAILURE);
	}
	printf("word expandida: %s\n", out);
	printf("antes de igualar: %s\n", word->word);
	if (word->word)
		ft_free(word->word);
	//word->word = ft_strjoin("", out);
	word->word = out;
	//ft_free(out);
	printf("word expandida_f: %s\n", word->word);
	return (EXIT_SUCCESS);
}

// TODO: identificador valido
//			ejemplo no valido 11111