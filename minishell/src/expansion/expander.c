#include "minishell.h"

/* char *get_env_var(t_data *data, char *str, int i)
{
	char    *env_var;
	size_t  var_size;
	int     var_pos;

	var_pos = 0;
	var_size = ft_strlen(&str[i]);
	while (ft_strnstr((char *)data->env[var_pos], &str[i], var_size) == 0)
		var_pos++;
	env_var = ft_strnstr((char *)data->env[var_pos], &str[i], var_size);
	printf("%s\n", env_var);
	return (0);
}

void get_expansion(t_data *data, char *str, int i)
{   
	char *env_var;

	if (str[i] == '$' && str[i + 1] == '{')
	{
		env_var = get_env_var(data, str, i+1);
		printf("env: %c\n", str[i]);
		getchar();
	}
	else if ((str[i] == '$' && str[i + 1] != '('))
	{
		env_var = get_env_var(data, str, i);
		printf("env: %c\n", str[i]);
		getchar();       
	}   
}
*/
void	expander(t_word *input)
{
	// if NULL gestionar
	while (*(input->word))
	{
		/*body    $alphanum  o "$alphanum" ${alphanum} $(alphanum)  o ~ pero no  '$alphanum'  "~"  etc etc   */
		input->word++;
	}
}