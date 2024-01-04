/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:56:16 by pedromar          #+#    #+#             */
/*   Updated: 2024/01/04 23:07:34 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	shift:
		añade stado actual a state
		avanza token
*/
static void	shift(t_dlst *lex, t_state	*state, int action)
{
	t_state	*new;

	new = (t_state *)ft_malloc(sizeof(t_dlst));
	new->data = action;
	ft_dlstaddf(&state, new);
	lex = lex->next;
	return ;
}

static void	reduce(t_dlst *lex, t_state	*state, int action)
{
	action = action - REDUCE0;
	if (action == 0)
		rules_accept(lex, state, action);
	else if (action >=1 && action <=2 )
		rules_program(lex, state, action);
	else if (action >=3 && action <=5 )
		rules_and_or(lex, state, action);
	else if (action >=6 && action <=7 )
		rules_pipeline(lex, state, action);
	else if (action >=8 && action <=10 )
		rules_command(lex, state, action);
	else if (action >=11 && action <=12 )
		rules_commpound(lex, state, action);
	else if (action >=13 )
		rules_group(lex, state, action);
	else if (action >=14 )
		rules_subshell(lex, state, action);
	else if (action >=15 && action <=19 )
		rules_simple_cmd(lex, state, action);
	else if (action >=20 && action <=23 )
		rules_cmd_prefix(lex, state, action);
	else if (action >=24 && action <=27 )
		rules_cmd_suffix(lex, state, action);
	else if (action >=28 && action <=29 )
		rules_redirect_list(lex, state, action);
	else if (action >=30 && action <=37 )
		rules_io_redirect(lex, state, action);


	// * aqui deberia estar eliminados los nodos que se han usado en la reducion.
	//
	// * formada la estructura pertinente en la cabeza de lex
	//
	// * eliminados los nodos de state
	//
	// * actualizado el valor de state con la tabla go_to 
}

/*
	error:
		limpia state y tokens
		imprime diagnostico
*/
static void	error(t_dlst *lex, t_state	*state, int action)
{
	//t_state	*tmp;
	//// FREE LEX
	//// Los elementos de lex que posiblemente
	//// no sean tokens ordinarios son desde el principio de la lista hasta el
	//// elemento actual:
	////		eliminar como token desde state->next hasta el final
	//ft_dlstclear(&(lex->next), free);
	////		eliminar especiales desde token actual hasta inicio
	//// FREE STATE
	//// el primer estado no esta en memoria dinamica, lo deslinkeamos
	//tmp = ft_dlstlast(state);
	//tmp->prev->next = NULL;
	//tmp->prev = NULL;
	//tmp->data = state->data;
	//ft_dlstclear(&state, free);
	//state = tmp;
	//// diagnostic
	printf("Syntax Error.\n");
	return ;
};


/*
	Inicialmente en lex hay una lista de tokens,
	tras la función quedara un unico node con la estructura a ejecutar.
	En caso de error gramatical o RULE 2 quedara lex->data = NULL
*/

void	syntax(t_dlst *lex)
{
	int			action;
	t_state		state;

	state.next = NULL;
	state.prev = NULL;
	state.data = 0;
	while (state.data != ACCEPT && state.data != GRAMMAR_ERROR && state.data != UNDEFINED)
	{
		action = table_action(state.data, lex->data);
		if (action >= SHIFT0  && action <= SHIFT54)
			shift(lex, &state, action);
		else if (action >= REDUCE0 && action <= REDUCE37)
			reduce(lex, &state, action);
		else if (action == GRAMMAR_ERROR || action == UNDEFINED)
			error(lex, &state, action);
	}
	return ;
}
