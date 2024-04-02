/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 13:03:41 by pedro             #+#    #+#             */
/*   Updated: 2024/04/02 18:38:28 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	expander(t_token *input)
{
	char	*aux;

	if (input->str[0] == '~')
	{
		aux = tilde_expansion(input->str);
		free(input->str);
		input->str = aux;
	}
	if (input->flag & PARAM_E)
	{
		aux = parameter_expansion(input->str);
		free(input->str);
		input->str = aux;
	}
	if (input->flag & (WILDCARD|QUEST))
	{
		input->str = filename_expansion(input->str);
		free(input->str);
		input->str = aux;
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