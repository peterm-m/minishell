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
    //size_t  s_key = 0;
    char    *value;
    char    **env;
    printf("env size: %i\n\n", ft_dlstsize(head));
    env = (char **)ft_malloc(ft_dlstsize(head) + 1);
    i = 0;
    
    while (head != NULL)
	{
		//s_key = (ft_strlen(((t_env *)head->data)->key));
        j = 0;
        while (((t_env *)head->data)->value[j])
        {
            value = ft_strjoin(value, ((t_env *)head->data)->value[j]);
            if (((t_env *)head->data)->value[j + 1])
                value = ft_strjoin(value, ":");
            j++;
        }
        env[i] = ft_strjoin(((t_env *)head->data)->key, "=");
        env[i] = ft_strjoin(env[i], value);
		head = head->next;
        i++;
        printf("%s\n", env[i]);
	}
    env[i] = NULL;
    return (env);
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