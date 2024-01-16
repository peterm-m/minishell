#include "minishell.h" 

t_token *add_token(char *str, int i, int j, int type)
{
	t_token *token;

	token = ft_malloc(sizeof(t_token));
	if (!(token->str = ft_substr(str, i, j)))
	{
		ft_free(token);
		return (NULL);
	}
	token->flag = type;
	return (token);
}

void free_token(t_token *tok)
{
	if (tok->str)
		free(tok->str);
	free((void *)tok);
}

void search_w_q(void *t)
{
	if (((t_token *)t) != NULL)
	{
		printf("str: %s\n", ((t_token *)t)->str);
		if (ft_strchr(((t_token *)t)->str, '*') != 0)
			((t_token *)t)->flag |= WILDCARD;
		else if (ft_strchr(((t_token *)t)->str, '?') != 0)
			((t_token *)t)->flag |= QUEST;
	}
}

