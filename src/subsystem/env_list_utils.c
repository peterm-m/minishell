#include "minishell.h"

t_env *new_t_env(void)
{
	t_env *env;

	env = ft_malloc(sizeof(t_env));
	env->key = NULL;
	env->key = NULL;
	return (env);
}
void free_t_env(t_env *tok)
{
	if (tok->key)
		free(tok->key);
	if (tok->value)
		free(tok->value);
	free((void *)tok);
}