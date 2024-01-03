#include "minishell.h" 

int get_dolar_type(char *str, int i)
{
    int j;
    int type;

    j = 1;
    type = 0;
    while (!is_quotes(str[i + j]))
    {
        if (str[i + j] == '$')
            break;
        j++;
    }
    if (str[i + j] == '$' && str[i + j+ 1] == '(') 
        type = COMMD_SUB;    
    else if (str[i + j] == '$' && str[i + j + 1] == '{')
        type = PARAM_E;
    else if (str[i + j] == '$')
        type = PARAM_E;
    return (type);
}

int get_string(char *str, int i, t_dlst **head) // Pasar como argumento la lista de tokens
{
    int j;
    int expand;
    int type;
    t_dlst  *new_token;
    t_token *token;
 
    j = 1;
    expand = 0;
    while (!is_quotes(str[i + j]))
    {
        if (str[i + j] == '$')
            expand = 1;
        j++;
    }
    j++;
    token = add_token(str, i, j, WORD);
    if (expand == 1)
    {
        type = get_dolar_type(str, i);
        token->expand=type;
    }
    new_token = ft_dlstnew(token);
    ft_dlstaddb(head, new_token);
    return (i + j);
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
        return (-1);
    new_token = ft_dlstnew(token);
    ft_dlstaddb(head, new_token);
    i += j;
    return (i);
}

int get_dolar2(char *str, int i, t_dlst **head, int type)
{
    int j;
    t_dlst  *new_token;
    t_token *token;

    j = 2;
    if (str[i] == '$' && str[i + 1] == '(')
    {  
        type = COMMD_SUB;
        while (str[i + j] != ')')
            j++;        
    }
    else if (str[i] == '$' && str[i + 1] == '{')
    {
        type = PARAM_E;
        while (str[i + j] != '}')
            j++;
    }
    if (!(token = add_token(str, i, j + 1, WORD)))
        return (-1);
    token->expand = type;
    new_token = ft_dlstnew(token);
    ft_dlstaddb(head, new_token);
    return (i + j + 1);
}
int get_dolar(char *str, int i, t_dlst **head)
{
    int j;
    int type;
    t_dlst  *new_token;
    t_token *token;

    j = 0;
    type = 0;
    if (str[i + j] == '$')
        j++;
    if (str[i + j] == '(' || str[i + j] == '{')
    {
        return(get_dolar2(str, i, head, type));
    }
    else
    {
        while (!is_blankspace(str[i + j]))
            j++;
    }
    if (!(token = add_token(str, i, j, WORD)))
        return (-1);
    token->expand = PARAM_E;
    new_token = ft_dlstnew(token);
    ft_dlstaddb(head, new_token);
    return (i + j);
}
//"$hola" "g{$hh}" "$(ggg)" $fff $(hhh) ${jjj} 