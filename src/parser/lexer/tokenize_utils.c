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

t_dlst	*init_list(t_dlst *list)
{
	list = ft_calloc(sizeof(t_dlst), 1);
	if (!list)
		return (NULL);
	return (list);
}

int get_ionumber(char *str, int i, t_dlst **head)
{
    int j;
    t_dlst  *new_token;
    t_token *token;

	j = 0;
    token = NULL;
	while (ft_isdigit(str[i + j]))
		j++;
	if (str[i + j] == '>' || str[i + j] == '<')
	{
		j++;
        if (!(token = add_token(str, i, j, IO_NUMBER)))
            return (0);		
	}
    new_token = ft_dlstnew(token);
    ft_dlstaddb(head, new_token);
    i += j;
	return (i);
}
/* void	free_list(t_dlst *list)
{
	t_elem	*tmp;

	tmp = list->head;
	while (tmp)
	{
		free(tmp->content);
		free(tmp);
		tmp = tmp->next;
	}
	free(list);
} */


