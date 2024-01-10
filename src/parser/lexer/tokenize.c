#include "minishell.h" 
/**
 * The function extracts an IO number from a string and adds 
 * it as a token to a doubly linked list.
 * 
 * @param str A pointer to a character array (string) that contains the input.
 * @param i The parameter `i` represents the current index in the string `str`. It is used to keep
 * track of the position while parsing the string.
 * @param head A double linked list pointer, which is a pointer to the head of the list.
 * 
 * @return the index position of the next character after the IO number in the string.
 */
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
        if (!(token = add_token(str, i, j, tt_io_number)))
            return (-1);		
	}
    new_token = ft_dlstnew(token);
    ft_dlstaddb(head, new_token);
	return (i + j);
}

/**
 * The function adds tokens to a doubly linked list based on 
 * specific characters in a string.
 * 
 * @param str A pointer to a character array (string) that contains the input.
 * @param i An integer that represents the current index position in the string
 * `str`. It is used to iterate through the characters of the string.
 * @param head A pointer to a pointer to a doubly linked list (t_dlst).
 * 
 * @return the updated value of the variable 'i'.
 */
int get_token(char *str, int i, t_dlst **head) // Pasar como argumento la lista de tokens
{
    t_dlst  *new_token;
    t_token *token;

    token = NULL;
    if (str[i] == '|' && str[i + 1] != '|')
        token = add_token(str, i, 1, tt_pipe);
    else if (str[i] == '<' && str[i + 1] != '<')
        token = add_token(str, i, 1, tt_less);
    else if (str[i] == '>' && str[i + 1] != '>')
        token = add_token(str, i, 1, tt_great);
    else if (str[i] == '(')
        token = add_token(str, i, 1, tt_lbraket);
    else if (str[i] == '{')
        token = add_token(str, i, 1, tt_lbrace);
    else
        return(get_token2(str, i, head));
    if (token == NULL)
        return (-1);
    new_token = ft_dlstnew(token);    
    ft_dlstaddb(head, new_token);
    i++;
    return (i);
}

/**
 * The function adds tokens to a doubly linked list based on specific characters in a
 * string.
 * 
 * @param str A pointer to a character array (string) that contains the input.
 * @param i An integer that represents the current index position in the string
 * `str`. It is used to determine the position of the token in the string.
 * @param head A pointer to a pointer to a doubly linked list (t_dlst).
 * 
 * @return the updated value of the variable 'i'.
 */
int get_token2(char *str, int i, t_dlst **head)
{
    t_dlst  *new_token;
    t_token *token;

    token = NULL;
    if (str[i] == '|' && str[i + 1] == '|')
        token = add_token(str, i, 2, tt_or_if);
    else if (str[i] == '>' && str[i + 1] == '>')
        token = add_token(str, i, 2, tt_dgreat);
    else if (str[i] == '&' && str[i + 1] == '&')
        token = add_token(str, i, 2,tt_and_if);   
    else if (str[i] == '<' && str[i + 1] == '<')
        token = add_token(str, i, 2, tt_dless);
    else if (str[i] == ')')
        token = add_token(str, i, 1, tt_rbraket);
    else if (str[i] == '}')
        token = add_token(str, i, 1, tt_rbrace);
    new_token = ft_dlstnew(token);    
    ft_dlstaddb(head, new_token);
    if (str[i] == ')' || str[i] == '}')
        i += 1;
    else
        i += 2;
    return (i);
}

/**
 * The function takes an input string, an index, and a doubly linked list head
 * pointer, and returns the index of the next token in the input string.
 * 
 * @param input A pointer to a character array representing the input string.
 * @param i The parameter `i` is an integer that represents the current 
 * index position in the `input` string. It is used to keep track of 
 * the progress while parsing the input string.
 * @param head The `head` parameter is a pointer to a doubly linked list (`t_dlst`).
 * 
 * @return The function `get_next_token` returns an integer value.
 */
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

/**
 * The function takes an input string and creates a doubly linked list of tokens.
 * 
 * @param input A pointer to a character array representing the input string.
 * @param head The first node of a doubly linked list. It is used to keep 
 * track of the head of the list, which is updated as new tokens are added to the list.
 * 
 * @return the pointer to the head of the doubly linked list.
 */
t_dlst *tokenize(char *input, t_dlst **head)
{
    int             i;
    t_dlst  *last_token;
    t_token *end;

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
    end = add_token("$", 0, 1, tt_end);
    last_token = ft_dlstnew(end);    
    ft_dlstaddb(head, last_token);
    ft_dlstiter(*head, search_w_q);
    return (*head);
}
