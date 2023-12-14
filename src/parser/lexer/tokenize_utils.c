#include "minishell.h" 

int is_token(int c)
{
    if (c == '|' || c == '<' || c == '>' ||
        c == '(' || c == ')' || c == ';'
        || c == '&')
        return (1);
    return (0);
}

int	is_blankspace(char c)
{
	return (c == ' ' || (c > 8 && c < 14));
}

int is_quotes(char c)
{
    return (c == '\'' || c == '"');
}