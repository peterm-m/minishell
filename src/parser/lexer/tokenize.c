#include "minishell.h" 

int get_string(char *str, int i, t_dlst **head) // Pasar como argumento la lista de tokens
{
    int j;
    t_dlst  *new_token;
    t_token *token;
 
    j = 0;
    if (is_quotes(str[i + j]))
    {
        j++;
        while (!is_quotes(str[i + j]))
            j++;
        j++;
    }
    if (is_blankspace(str[i + j]))
    {
        if (!(token = add_token(str, i, j, QUOTED)))
            return (0);
    }
    else
    {
        if (!(token = add_token(str, i, j, QUOTED)))
            return (0);
    }
    new_token = ft_dlstnew(token);
    ft_dlstaddb(head, new_token);
    i += j;
    //printf("get_string i: %i\n", i);
    //printf("get_string str: %s\n", ((t_token *)head->data)->str);
    return (i);
}

int get_token(char *str, int i, t_dlst **head) // Pasar como argumento la lista de tokens
{
    int j;
    t_dlst  *new_token;
    t_token *token;

    token = NULL;
    j = 0;
    if (is_token(str[i + j]))
    {
        j++;
        if (is_token(str[i + j]))
            j++;
        if (!(token = add_token(str, i, j, WORD)))
            return (0);
    }
    new_token = ft_dlstnew(token);
    ft_dlstaddb(head, new_token);
    i += j;
    //printf("get_token i: %i\n", i);
    //printf("get_token str: %s\n", ((t_token *)head->data)->str);
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
    //printf("get_word i: %i\n", i);
    //printf("get_word str: %s\n",((t_token *)tem->data)->str);
    //ft_dlstiter(head, tok_p);
    return (i);
}

int get_next_token(char *input, int i, t_dlst **head)
{
    while (is_blankspace(input[i]))
        i++;
    if (!input[i])
        return (0);
    if (!in_word(input[i]))
        return(get_word(input, i, head));
    else if (is_token(input[i]))
        return(get_token(input, i, head));
    else if (is_quotes(input[i]))
        return (get_string(input, i, head));
    else if (ft_isdigit(input[i]))
        printf("io_number");
        //token = get_ionumber(input, i, head);
    return (i);
}
t_dlst *tokenize(char *input, t_dlst **head)
{
    int             i;
    //head = ft_dlstnew(head);
    i = 0;
    while(input[i] != '\0')
    {
        i = get_next_token(input, i, head);
        if(i == 0)
        {
            // eliminar token y liberar lista, volver a pedir nueva linea.
            return (NULL);
        }
        i++;
        printf("i: %i\n", i);
    }
    return (*head);
}
