#include "minishell.h" 
/*
typedef struct s_token 
{
    int     type;
    int    expand;
    char *str;
    struct s_token  *next;
}   t_token;




input = "dasflakhsdfasdfkljasdf dal fd fddd"

input[0] */

t_token get_string(char *str, int i, t_token *token) // Pasar como argumento la lista de tokens
{
    if (is_quotes(str[i]))
    {
        i++;
        while (!is_quotes(str[i]))
            i++;
        i++;
    }
    if (is_blankspace(str[i]))
        if (!token = ft_substr(str, 0, i))
            return (-1);
    else
        if (!token = ft_substr(str, 0, i + 1))
            return (-1);
    return (token);
}

t_token get_token(char *str, int i, t_token *token) // Pasar como argumento la lista de tokens
{

}

int tokenize(char   *read_line)// esta no
{
    int i;
    int success;

    i = 0;
    while (read_line[i] != '\0')
    {
        if (is_blankspace(read_line[i]))
            i++;
        else if (is_token(read_line[i]))
            success = get_token(read_line[i]);
        else
            success = get_string(read_line[i]);
        if (success < 0)
            return (-1);
        i = i + success;
    }
}

t_token	*init_token(void)
{
	t_token *token;
	if (!(token = (t_token *)ft_memalloc(sizeof(t_token))))
		return (NULL);
	return (token);
}
t_token get_next_token(char *input, int i, t_data *data)
{
    t_token token;

    token = NULL;
    while (is_blankspace(input[i]))
        i++;
    if (!input[i])
        return (token);
    if (!token = init_token())
        return (token); // ? volver a sacar linea
    if (is_token(input[i]))
        token = get_token(input, &i, token);
    else if (is_quotes(input[i]))
        token = get_string(input, &i, token);
    else if (ft_isdigit(input[i]))
        token = get_ionumber()
    return (token);
}
t_token_list tokenize(char *input, t_data *data)
{
    int             i;
    t_token_list    *head;
    t_token         next_token;
    t_token         new_token;
    i = 0;
    head = NULL;
    while(input[i] != '\0')
    {
        if(!next_token = get_next_token(input, &i, &head))
        {
            // eliminar token y liberar lista, volver a pedir nueva linea.
        }
        new_token = ft_lstnew(next_token);
        if (!new_token)
            return (-1);
        ft_lstadd_back(&head, new_token);
    }
}