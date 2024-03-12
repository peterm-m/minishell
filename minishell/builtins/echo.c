#include "wrappers.h"
#include "libft.h"

/**
 * The function checks if a given string starts with 
 * a '-' followed by one or more 'n' characters.
 * 
 * @param str The string to be checked.
 * 
 * @return either TRUE or FALSE.
 */
int has_flag(char *str)
{
	int i;

	i = 0;
	if (!str[i])
		return (0);
	if (str[i] != '-')
		return (0);
	i++;
	while (str[i] && str[i] == 'n')
		i++;
	if  (!str[i])
		return (1);
	return (0);
}
/**
 * Prints the elements of an array of strings, separated by spaces,
 * and followed by a newline character if flag -n appears.
 * 
 * @param args The args that will be printed
 * @param i An integer that represents the index of the current 
 * argument in the `args` array.
 * @param is_flag Indicates whether the function is being called
 * with a flag argument. 
 * 
 * @return EXIT_SUCCESS or FAILURE_SUCCESS
 */
void print_echo(char **args, int i, int is_flag)
{
	if (!args[i])
	{
		if (!is_flag)
			printf("\n");
		return ;
	}
	while (args[i++])
	{
		printf ("%s", args[i - 1]);
		if (args[i])
			printf (" ");
		else if (!args[i] && !is_flag)
			printf ("\n");
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	is_flag;

	(void)argc;
	i = 1;
	is_flag = 0;
	while (argv[i] && has_flag(argv[i]))
	{
		is_flag = 1;
		i++;
	}
	print_echo(argv, i, is_flag);
	return (EXIT_SUCCESS);
}
