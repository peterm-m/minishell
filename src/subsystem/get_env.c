#include "minishell.h"

void    set_env(char *key, char *value, t_env *tok)
{
    tok->key = key;
    tok->value = ft_split(value, ':');
}

t_dlst   *get_enviroment(const char **env, t_dlst **head)
{
    t_dlst   *next_env;
    t_env    *env_new;
    char        *equal;
    //char        *key;
    size_t      key_size;
    int         i;

    i = 0;
    while (env[i])
    {
        env_new = new_t_env();
        equal = ft_strrchr(env[i], '='); // Busca el '=' en cada linea de env
        key_size = ft_strlen(env[i]) - ft_strlen(equal); //tamaño de la string que precede al '='(key)
        equal++;
        set_env(ft_substr(env[i], 0, key_size), equal, env_new);
        next_env = ft_dlstnew(env_new);
        ft_dlstaddb(head, next_env);
        i++;
    }
    return (*head);
}

char    **make_char(t_dlst *head)
{
    int     i;
    int     j;
    char    *value;
    char    **env;

    env = ft_malloc((size_t)ft_dlstsize + 1);
    i = 0;
    while (head != NULL)
	{
        j = 0;
        value = NULL;
        env[i++] = ft_strjoin(((t_env *)head->data)->key, "=");
        while (((t_env *)head->data)->value[j])
        {
            value = ft_strjoin(value, ((t_env *)head->data)->value[j]);
            if (((t_env *)head->data)->value[j++ + 1])
                value = ft_strjoin(value, ":");
        }
        env[i - 1] = ft_strjoin(env[i - 1], value);
        if (value)
            free(value);
		head = head->next;
	}
    env[i] = NULL;
    return (env);
}

char    *get_env_value(char *str, char **env)
{
    int      i;

    i = 0;
    while (env[i])
    {
        if (ft_strncmp(str, env[i], ft_strlen(str)) == 0)
            return (ft_strchr(env[i], '=') + 1);
        i++;
    }
    return (NULL);
}

/* void p_lst(void *e)
{
    printf("%s===%s", ((t_env_lst *)e)->key, ((t_env_lst *)e)->value);
} */

/* int main(int argc, char **argv,const char **env)
{
    (void)argc;
    (void)argv;
    t_env_lst *p = get_enviroment(env, &p);
    ft_envlstiter(p, p_lst);
} */