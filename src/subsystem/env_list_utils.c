#include "minishell.h"

t_env_lst	*ft_envlstnew(void *key, void *value)
{
	t_env_lst	*new_node;

	new_node = malloc(sizeof(t_env_lst));
	if (new_node != NULL)
	{
		new_node->key = key;
        new_node->value = value;
		new_node->next = NULL;
		new_node->prev = NULL;
	}
	return (new_node);
}

void	ft_envlstaddb(t_env_lst **head, t_env_lst *node)
{
	t_env_lst	*last;

	node->next = NULL;
	last = ft_envlstlast(*head);
	if (last == NULL)
		*head = node;
	else
	{
		last->next = node;
		node->prev = last;
	}
}

void	ft_envlstadd(t_env_lst *prev, t_env_lst *node)
{
	if (prev == NULL)
	{
		node->next = NULL;
		node->prev = NULL;
		prev = node;
	}
	else
	{
		node->next = prev->next;
		prev->next = node;
		node->prev = prev;
		if (node->next != NULL)
			node->next->prev = node;
	}
}

t_env_lst	*ft_envlstlast(t_env_lst *envlst)
{
	if (envlst == NULL)
		return (NULL);
	while (envlst->next != NULL)
		envlst = envlst->next;
	return (envlst);
}

void	ft_envlstiter(t_env_lst *envlst, void (*f)(void *))
{
	while (envlst != NULL)
	{
		f(envlst->key);
		envlst = envlst->next;
	}
}

void	ft_envlstclear(t_env_lst **envlst, void (*del)(void*))
{
	t_env_lst	*aux;

	aux = *envlst;
	while (aux != NULL)
	{
		*envlst = aux->next;
		del(aux->key);
        del(aux->value);
		free(aux);
		aux = *envlst;
	}
}
