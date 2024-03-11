/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:08:32 by adiaz-uf          #+#    #+#             */
/*   Updated: 2024/03/11 18:13:29 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int get_env_len(char **env)
{
    int i;

    i = 0;
    while (env[i])
        i++;
    return (i);
}

void    sort_env(char **env)
{
    int i;
    int j;
    int env_len;
    char *aux;

    env_len = get_env_len(env);
    i = 0;
    while (i < env_len - 1)
    {
        j = i + 1;
        while (j < env_len)
        {
            if (strcmp(env[i], env[j]) > 0)
            {
                aux  = env[i];
                env[i] = env[j];
                env[j] = aux;
            }
            j++;
        }
        i++;
    }
}

void    print_sorted_env(char **env)
{
    int i;

    sort_env(env);
    i = -1;
    while (env[++i])
        printf ("declare -x %s\n", env[i]);
}

int main(int argc, char **argv, char **env)
{
    char    *name;
    char    *value;
    int     i;

    if (argc == 1)
    {
        print_sorted_env(env);
        return(EXIT_SUCCESS);
    }
    i = 0;
    while (argv[1][i] && argv[1][i] != '=')
        i++;
    name = ft_substr(argv[1], 0, i);
    i++;
    value = ft_strdup(argv[1] + i);
    if (!name || !value)
        return (EXIT_FAILURE);
    setenv(name, value, 1);  //TODO: FT_setenv
    i = 0;
    while (env[i])
    {
        printf ("I = %d   %s\n",i, env[i]);
        i++;
    }
    free(name);
    free(value);      
    return(EXIT_SUCCESS);
}
