#include "minishell.h" 

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

int get_string(char *str, int i, t_dlst **head) // Pasar como argumento la lista de tokens
{
    int j;
    int expand;
    t_dlst  *new_token;
    t_token *token;
 
    j = 0;
    expand = 0;
    if (is_quotes(str[i + j]))
    {
        j++;
        while (!is_quotes(str[i + j]))
        {
            j++;
            if (str[i + j] == '$')
                expand = 1;
        }
        j++;
    }
    if (!(token = add_token(str, i, j, WORD)))
        return (0);
    new_token = ft_dlstnew(token);
    if (expand == 1)
        token ->expand = TRUE;
    ft_dlstaddb(head, new_token);
    i += j;
    return (i);
}

int get_word(char *str, int i, t_dlst **head)
{
    int j;
    t_dlst  *new_token;
    t_token *token;

    j = 0;
    while(!in_word(str[i + j]))
        j++;
    if (!(token = add_token(str, i, j, WORD)))
        return (0);
    new_token = ft_dlstnew(token);
    ft_dlstaddb(head, new_token);
    i += j;
    return (i);
}
int expansion_type()
{
    return (1);
}

int get_dolar(char *str, int i, t_dlst **head)
{
    int j;
    t_dlst  *new_token;
    t_token *token;

    j = 0;
    if (str[i + j] == '$')
        j++;
    if (str[i + j] == '(' || str[i + j] == '{')
    {
        j++;
        while (str[i + j] != '{' || str[i + j] != '{')
            j++;
    }
    else
    {
        while (!is_blankspace(str[i + j]))
            j++;
    }
    token = add_token(str, i, j, DOLAR);
    token->expand = TRUE;
    new_token = ft_dlstnew(token);
    ft_dlstaddb(head, new_token);
    i += j;
    return (i);
}