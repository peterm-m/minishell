/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 13:03:41 by pedro             #+#    #+#             */
/*   Updated: 2024/04/02 19:45:47 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	search_character(char *str, char c)
{
	int	i;
	static int	single_q = 0;
	static int	double_q = 0;

	i = 0;
	while (str[i])
	{
		single_q = (single_q + (str[i] == '\'' && double_q == 0)) % 2;
		double_q = (double_q + (str[i] == '\"' && single_q == 0)) % 2;
		if (str[i] == c)
			if ((c == '$' && single_q == 0) ||
				(double_q == 0 && single_q == 0))
				break ;
		i++;
	}
	return (i);
}

void	expander(t_token *input)
{
	int		i;

	i = 0;
	if (input->str[0] == '~')
		i += tilde_expansion(input);
	if (input->flag & PARAM_E)
	{
		while (1)
		{
			printf("1 %s\n", input->str +i);
			i += search_character(input->str + i, '$');
			if (!input->str[i])
				break ;
			while (input->str[i] == '$')
				i++;
			parameter_expansion(input, i);
		}
	}
}

/*
$HOME
--$HOME
$HOME-- 
--$HOME--
$NOVAR
--$NOVAR
$NOVAR--
--$NOVAR--
$HOME$HOME
--$HOME$HOME
$HOME$HOME--
--$HOME$HOME--
$HOME$USER
--$HOME$USER
$HOME$USER--
--$HOME$USER--
$USER$HOME
--$USER$HOME
$USER$HOME--
--$USER$HOME--
$NOVAR$HOME
--$NOVAR$HOME
$NOVAR$HOME--
--$NOVAR$HOME--
$NOVAR$NOVAR
--$NOVAR$NOVAR
$NOVAR$NOVAR--
--$NOVAR$NOVAR--

~$HOME
~--$HOME
~$HOME--
~--$HOME--
~$NOVAR
~--$NOVAR
~$NOVAR--
~--$NOVAR--
~$HOME$HOME
~--$HOME$HOME
~$HOME$HOME--
~--$HOME$HOME--
~$HOME$USER
~--$HOME$USER
~$HOME$USER--
~--$HOME$USER--
~$USER$HOME
~--$USER$HOME
~$USER$HOME--
~--$USER$HOME--
~$NOVAR$HOME
~--$NOVAR$HOME
~$NOVAR$HOME--
~--$NOVAR$HOME--
~$NOVAR$NOVAR
~--$NOVAR$NOVAR
~$NOVAR$NOVAR--
~--$NOVAR$NOVAR--

~/$HOME
~/--$HOME
~/$HOME--
~/--$HOME--
~/$NOVAR
~/--$NOVAR
~/$NOVAR--
~/--$NOVAR--
~/$HOME$HOME
~/--$HOME$HOME
~/$HOME$HOME--
~/--$HOME$HOME--
~/$HOME$USER
~/--$HOME$USER
~/$HOME$USER--
~/--$HOME$USER--
~/$USER$HOME
~/--$USER$HOME
~/$USER$HOME--
~/--$USER$HOME--
~/$NOVAR$HOME
~/--$NOVAR$HOME
~/$NOVAR$HOME--
~/--$NOVAR$HOME--
~/$NOVAR$NOVAR
~/--$NOVAR$NOVAR
~/$NOVAR$NOVAR--
~/--$NOVAR$NOVAR--

"~"/$HOME
"~"/--$HOME
"~"/$HOME--
"~"/--$HOME--
"~"/$NOVAR
"~"/--$NOVAR
"~"/$NOVAR--
"~"/--$NOVAR--
"~"/$HOME$HOME
"~"/--$HOME$HOME
"~"/$HOME$HOME--
"~"/--$HOME$HOME--
"~"/$HOME$USER
"~"/--$HOME$USER
"~"/$HOME$USER--
"~"/--$HOME$USER--
"~"/$USER$HOME
"~"/--$USER$HOME
"~"/$USER$HOME--
"~"/--$USER$HOME--
"~"/$NOVAR$HOME
"~"/--$NOVAR$HOME
"~"/$NOVAR$HOME--
"~"/--$NOVAR$HOME--
"~"/$NOVAR$NOVAR
"~"/--$NOVAR$NOVAR
"~"/$NOVAR$NOVAR--
"~"/--$NOVAR$NOVAR--

'~'/$HOME
'~'/--$HOME
'~'/$HOME--
'~'/--$HOME--
'~'/$NOVAR
'~'/--$NOVAR
'~'/$NOVAR--
'~'/--$NOVAR--
'~'/$HOME$HOME
'~'/--$HOME$HOME
'~'/$HOME$HOME--
'~'/--$HOME$HOME--
'~'/$HOME$USER
'~'/--$HOME$USER
'~'/$HOME$USER--
'~'/--$HOME$USER--
'~'/$USER$HOME
'~'/--$USER$HOME
'~'/$USER$HOME--
'~'/--$USER$HOME--
'~'/$NOVAR$HOME
'~'/--$NOVAR$HOME
'~'/$NOVAR$HOME--
'~'/--$NOVAR$HOME--
'~'/$NOVAR$NOVAR
'~'/--$NOVAR$NOVAR
'~'/$NOVAR$NOVAR--
'~'/--$NOVAR$NOVAR--

"$HOME"
--"$HOME"
"$HOME"--
--"$HOME"--
"$NOVAR"
--"$NOVAR"
"$NOVAR"--
--"$NOVAR"--
"$HOME""$HOME"
--"$HOME""$HOME"
"$HOME""$HOME"--
--"$HOME""$HOME"--
"$HOME"$USER
--"$HOME"$USER
"$HOME"$USER--
--"$HOME"$USER--
$USER"$HOME"
--$USER"$HOME"
$USER"$HOME"--
--$USER"$HOME"--
"$NOVAR""$HOME"
--"$NOVAR""$HOME"
"$NOVAR""$HOME"--
--"$NOVAR""$HOME"--
"$NOVAR""$NOVAR"
--"$NOVAR""$NOVAR"
"$NOVAR""$NOVAR"--
--"$NOVAR""$NOVAR"--

'$HOME'
--'$HOME'
'$HOME'--
--'$HOME'--
'$NOVAR'
--'$NOVAR'
'$NOVAR'--
--'$NOVAR'--
'$HOME'$HOME'
--'$HOME'$HOME'
'$HOME'$HOME'--
--'$HOME'$HOME'--
'$HOME'$USER
--'$HOME'$USER
'$HOME'$USER--
--'$HOME'$USER--
$USER'$HOME'
--$USER'$HOME'
$USER'$HOME'--
--$USER'$HOME'--
'$NOVAR'$HOME'
--'$NOVAR'$HOME'
'$NOVAR'$HOME'--
--'$NOVAR'$HOME'--
'$NOVAR'$NOVAR'
--'$NOVAR'$NOVAR'
'$NOVAR'$NOVAR'--
--'$NOVAR'$NOVAR'--

*/