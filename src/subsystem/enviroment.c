/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enviroment.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 20:11:11 by adiaz-uf          #+#    #+#             */
/*   Updated: 2024/04/17 18:43:56 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "minishell.h"

#include "wrappers.h"

void	ft_initenv(void)
{
	int	i;

	i = 0;
	while (environ[i])
		ft_putenv(ft_strdup(environ[i++]));
	if (ft_getenv("MINISHLVL") == NULL)
		ft_putenv(ft_strdup("MINISHLVL=1"));
	else
	{
		i = ft_atoi(ft_getenv("MINISHLVL"));
		i++;
		ft_putenv(ft_strjoin("MINISHLVL=", ft_itoa(i)));
	}
}

//static char	**ft_initenv(void)
//{
//	char	**new_env;
//	int		i;
//
//	new_env = ft_copyarg(environ);
//	if (ft_getenv("MINISHLVL") == NULL)
//		ft_putenv(ft_strdup("MINISHLVL=1"));
//	else
//	{
//		i = ft_atoi(ft_getenv("MINISHLVL"));
//		i++;
//		ft_putenv(ft_strjoin("MINISHLVL=", ft_itoa(i)));
//	}
//	return (new_env);
//}
//
//void	ft_environ(char *parameter, int action)
//{
//	static char	**my_environ;
//
//	if (my_environ == NULL)
//		my_environ = ft_newenv();
//	if (action == 0)
//		ft_getenv(parameter);
//	else if (action == 1) // ADD
//		ft_putenv(paremeter, my_environ);
//	else if (action == 2) // UNSET
//		ft_unsetenv(parameter, my_environ);
//	else if (action == 3) // CLEAN
//		clean_argv(environ);
//}