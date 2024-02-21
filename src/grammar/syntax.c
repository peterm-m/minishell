/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:56:16 by pedromar          #+#    #+#             */
/*   Updated: 2024/02/14 14:17:52 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//void	print_log(t_dlst **lex, t_state **state);

// TODO testeo general
//		rebla por regla
//		semantica
// TODO end_parser

static void	shift(t_dlst **lex, t_state **state, int action)
{
	t_state	*new;

	new = ft_dlstnew(ft_malloc(sizeof(int)));
	*((int *)new->data) = action;
	ft_dlstaddf(state, new);
	*lex = (*lex)->next;
	return ;
}

static void	reduce(t_dlst **lex, t_state **state, int action)
{
	int		id_rule;

	id_rule = action - REDUCE0;
	table_reduce(action - REDUCE0)(lex, state);
	*((int *)(*state)->data) = table_goto(*((int *)(*state)->next->data),
			table_nt_generate(id_rule));
	return ;
}

// En caso de error implementar la limpieza
// En caso de error implementar diagnostico

static void	end_parser(t_dlst **lex, t_state **state, int action)
{
	(void )lex;
	(void )state;
	//if (action == ACCEPT)
	//	printf("END PARSER\n");
	//else
	//	printf("Syntax Error.\n");
	//ªdbg("├CLEAN %s\n", "");
	//ªft_dlstdelone((*lex)->prev, print_command);
	//ft_dlstdelone((*lex)->prev, clean_command);
	//ft_dlstclear(state, ft_free);
	//exit(EXIT_SUCCESS);
	return ;
}

void	syntax(t_dlst **lex)
{
	int		action;
	t_state	*state;

	state = ft_dlstnew(ft_malloc(sizeof(int)));
	*((int *)state->data) = 0;
	while (1)
	{
		action = table_action(*((int *)state->data),
				((t_token *)((*lex)->data))->flag & TOK_TYPE);
		if (action >= SHIFT0 && action <= SHIFT54)
		{
			dbg("├SHIFT to %d\n", action);
			shift(lex, &state, action);
		}
		else if (action >= REDUCE0 && action <= REDUCE37)
		{
			dbg("├REDUCE to %d\n", action - REDUCE0);
			reduce(lex, &state, action);
		}
		if (action == GRAMMAR_ERROR || action == UNDEFINED
			|| action == ACCEPT)
		{
			dbg("└END to %d\n\n", action - REDUCE0);
			end_parser(lex, &state, action);
			break ;
		}
	}
}

// * aqui deberia estar eliminados los nodos que se han usado en la reducion.
//
// * formada la estructura del comando en el unico node que quede en lex
