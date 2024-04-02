/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 13:03:41 by pedro             #+#    #+#             */
/*   Updated: 2024/04/02 17:21:42 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	quote_remove(input->str);
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