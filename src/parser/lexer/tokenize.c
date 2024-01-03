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
            return (-1);		
	}
    new_token = ft_dlstnew(token);
    ft_dlstaddb(head, new_token);
	return (i + j);
}

int get_token(char *str, int i, t_dlst **head) // Pasar como argumento la lista de tokens
{
    t_dlst  *new_token;
    t_token *token;

    token = NULL;
    if (str[i] == '|' && str[i + 1] != '|')
        token = add_token(str, i, 1, PIPE);
    else if (str[i] == '<' && str[i + 1] != '<')
        token = add_token(str, i, 1, LESS);
    else if (str[i] == '>' && str[i + 1] != '>')
        token = add_token(str, i, 1, REDIR);
    else if (str[i] == '(')
        token = add_token(str, i, 1, L_BRAKET);
    else if (str[i] == '{')
        token = add_token(str, i, 1, L_BRACE);
    else
        return(get_token2(str, i, head));
    if (token == NULL)
        return (-1);
    new_token = ft_dlstnew(token);    
    ft_dlstaddb(head, new_token);
    i++;
    return (i);
}

int get_token2(char *str, int i, t_dlst **head)
{
    t_dlst  *new_token;
    t_token *token;

    token = NULL;
    if (str[i] == '|' && str[i + 1] == '|')
        token = add_token(str, i, 2, OR);
    else if (str[i] == '>' && str[i + 1] == '>')
        token = add_token(str, i, 2, APPEND);
    else if (str[i] == '&' && str[i + 1] == '&')
        token = add_token(str, i, 2, AND);   
    else if (str[i] == '<' && str[i + 1] == '<')
        token = add_token(str, i, 2, HEREDOC);
    else if (str[i] == ')')
        token = add_token(str, i, 1, R_BRAKET);
    else if (str[i] == '}')
        token = add_token(str, i, 1, R_BRACE);
    new_token = ft_dlstnew(token);    
    ft_dlstaddb(head, new_token);
    if (str[i] == ')' || str[i] == '}')
        i += 1;
    else
        i += 2;
    return (i);
}

int get_next_token(char *input, int i, t_dlst **head)
{
    while (is_blankspace(input[i]))
        i++;
    if (!input[i])
        return (i);
    if (is_token(input[i]))
        return(get_token(input, i, head));
    else if (!in_word(input[i]) && !ft_isdigit(input[i]))
        return(get_word(input, i, head));
    else if (is_quotes(input[i]))
        return (get_string(input, i, head));
    else if (ft_isdigit(input[i]))
        return (get_ionumber(input, i, head));
    else if (input[i] == '$')
        return(get_dolar(input, i, head));
    return (i);
}

t_dlst *tokenize(char *input, t_dlst **head)
{
    int             i;
    i = 0;
    while(input[i] != '\0')
    {
        i = get_next_token(input, i, head);
        if(i <= 0)
        {
            ft_dlstclear(head, free_list);
            return (NULL);
        }
    }
    return (*head);
}
