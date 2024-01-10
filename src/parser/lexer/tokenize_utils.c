#include "minishell.h" 

t_token *add_token(char *str, int i, int j, int type)
{
	t_token *token;

    token = NULL;
	if (!(token = init_token()))
        return (0); // ? volver a sacar linea
    if (!(token->str = ft_substr(str, i, j)))
        return (NULL);
    token->type = type;
    token->expand = FALSE;
    return (token);
}

t_token	*init_token(void)
{
	t_token *token;
    
	if (!(token = (t_token *)ft_memalloc(sizeof(t_token))))
		return (NULL);
	return (token);
}

void free_token(t_token *tok)
{
    if (tok->str)
        free(tok->str);
    free((void *)tok);
}

void free_list(void *head)
{
	free((t_token *)head);
}

