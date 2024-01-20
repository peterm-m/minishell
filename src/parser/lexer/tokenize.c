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
int get_ionumber(char *str, int i, t_token *token)
{
	int j;

	j = 0;
	token = NULL;
	while (ft_isdigit(str[i + j]))
		j++;
	set_token(str, i, j, tt_word, token);
	if (token->flag == LEX_ERROR)
		return (LEX_ERROR);
	if (str[i + j] == '>' || str[i + j] == '<')
		token->flag = tt_io_number;
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
int get_token(char *str, int i, t_token *token) // Pasar como argumento la lista de tokens
{
	if (str[i] == '|' && str[i + 1] != '|')
		set_token(str, i, 1, tt_pipe, token);
	else if (str[i] == '<' && str[i + 1] != '<')
		set_token(str, i, 1, tt_less, token);
	else if (str[i] == '>' && str[i + 1] != '>')
		set_token(str, i, 1, tt_great, token);
	else if (str[i] == '(')
		set_token(str, i, 1, tt_lbraket, token);
	else if (str[i] == '{')
		set_token(str, i, 1, tt_lbrace, token);
	else
		return(get_token2(str, i, token));
	if (token->flag == LEX_ERROR)
		return (LEX_ERROR);
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
int get_token2(char *str, int i, t_token *token)
{
	if (str[i] == '|' && str[i + 1] == '|')
		set_token(str, i, 2, tt_or_if, token);
	else if (str[i] == '>' && str[i + 1] == '>')
		set_token(str, i, 2, tt_dgreat, token);
	else if (str[i] == '&' && str[i + 1] == '&')
		set_token(str, i, 2, tt_and_if, token);
	else if (str[i] == '<' && str[i + 1] == '<')
		set_token(str, i, 2, tt_dless, token);
	else if (str[i] == ')')
		set_token(str, i, 1, tt_rbraket, token);
	else if (str[i] == '}')
		set_token(str, i, 1, tt_rbrace, token);
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
int get_next_token(char *input, int i, t_token *token)
{
	while (is_blankspace(input[i]))
		i++;
	if (!input[i])
		return (i);
	if (is_operator(input[i]))
		return(get_token(input, i, token));
	else if (!in_word(input[i]) && !ft_isdigit(input[i]))
		return(get_word(input, i, token));
	else if (is_quotes(input[i]))
		return (get_string(input, i, token));
	else if (ft_isdigit(input[i]))
		return (get_ionumber(input, i, token));
	else if (input[i] == '$')
		return(get_dolar(input, i, token));
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
	int		i;
	t_token	*token;

	i = 0;
	while(input[i] != '\0')
	{
		token = new_token();
		i = get_next_token(input, i, token);
		if(i == LEX_ERROR)
		{
			ft_dlstclear(head, ft_free);
			return (NULL);
		}
		ft_dlstaddb(head, ft_dlstnew(token));
	}
	ft_dlstiter(*head, search_w_q);
	return (*head);
}
