#include "minishell.h" 

int is_token(int c)
{
    if (c == '|' || c == '<' || c == '>' ||
        c == '(' || c == ')' || c == ';'
        || c == '&')
        return (1);
    else
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
int	in_word(char c)
{
	return (is_quotes(c) || is_token(c) || c == '$' || 
        is_blankspace(c) || c == '\0');
}

void	*ft_memalloc(size_t size)
{
	void *result;

	if (!(result = malloc(size)))
		return (NULL);
	ft_memset(result, 0, size);
	return (result);
}