#include "minishell.h" 

/**
 * The function checks if a given character is a token 
 * (one of the following: '|', '<', '>', '(', ')', ';', or '&')
 * 
 * @param c The parameter `c` is an integer representing a character.
 * 
 * @return The function is_token is returning 1 if the input 
 * character c is a token Otherwise, it is returning 0.
 */
int is_token(int c)
{
    if (c == '|' || c == '<' || c == '>' ||
        c == '(' || c == ')' || c == ';'
        || c == '&')
        return (1);
    else
        return (0);
}

/**
 * The function checks if a character is a blank space or a whitespace character.
 * 
 * @param c The parameter "c" is of type char and represents a character.
 * 
 * @return a boolean value indicating whether the character is a blank space or not.
 */
int	is_blankspace(char c)
{
	return (c == ' ' || (c > 8 && c < 14));
}

/**
 * The function checks if a character is a single or double quote.
 * 
 * @param c The parameter `c` is the character that we want to check.
 * 
 * @return returns 1 if the character c is either a single quote (') or 
 * a double quote (") and returns 0 otherwise.
 */
int is_quotes(char c)
{
    return (c == '\'' || c == '"');
}

/**
 * The function checks if a character is part of a word by checking if 
 * it is a quote, token, dollar sign, blank space, or null character.
 * 
 * @param c The parameter "c" is a character that is being checked 
 * to determine if it is part of a word.
 * 
 * @return a boolean value.
 */
int	in_word(char c)
{
	return (is_quotes(c) || is_token(c) || c == '$' || 
        is_blankspace(c) || c == '\0');
}

/**
 * The function allocates memory of a given size and initializes it to zero.
 * 
 * @param size The size parameter is the number of bytes to allocate in memory.
 * 
 * @return a pointer to the allocated memory block.
 */
void	*ft_memalloc(size_t size)
{
	void *result;

	if (!(result = malloc(size)))
		return (NULL);
	ft_memset(result, 0, size);
	return (result);
}