/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:56:16 by pedromar          #+#    #+#             */
/*   Updated: 2024/03/26 22:18:44 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#undef LOGS 
#define LOGS 0

// TODO testeo clean structuras
// TODO end_parser

/*
	A Shift step advances in the token list by one symbol.
*/

static void	shift(t_dlst **lex, t_state **state, int action)
{
	t_state	*new;

	dbg("├SHIFT to %d\n", action);
	new = ft_dlstnew(ft_malloc(sizeof(int)));
	*((int *)new->data) = action;
	ft_dlstaddf(state, new);
	*lex = (*lex)->next;
	return ;
}

/*
	Reduce applies a grammar rule to some of the recent parse trees,
	joining them together as one tree with a new root symbol.
*/

static void	reduce(t_dlst **lex, t_state **state, int action)
{
	int		id_rule;

	dbg("├REDUCE to %d\n", action - REDUCE0);
	id_rule = action - REDUCE0;
	table_reduce(action - REDUCE0)(lex, state);
	*((int *)(*state)->data) = table_goto(*((int *)(*state)->next->data),
			table_nt_generate(id_rule));
	return ;
}

// En caso de error implementar la limpieza
// En caso de error implementar diagnostico

static void	end_parser(t_dlst **lex, t_state **state)
{
	t_command	*cmd;

	cmd = (*lex)->prev->data;
	ft_free((*state)->next->data);
	ft_free((*state)->data);
	execute_command(cmd, NO_PIPE, NO_PIPE);
	clean_command(cmd);
	return ;
}
	// TODO
	//if (action == ACCEPT)
	//	printf("END PARSER\n");
	//else
	//	printf("Syntax Error.\n");
	//dbg("├CLEAN %s\n", "");
	//ft_dlstdelone((*lex)->prev, print_command);
	//ft_dlstdelone((*lex)->prev, clean_command);
	//ft_dlstclear(state, ft_free);
	//exit(EXIT_SUCCESS);

/*
	Loop for LR-parser
	https://en.wikipedia.org/wiki/LR_parser
*/

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
			shift(lex, &state, action);
		else if (action >= REDUCE0 && action <= REDUCE37)
		{
			reduce(lex, &state, action);
		}
		if (action == GRAMMAR_ERROR || action == UNDEFINED
			|| action == ACCEPT)
		{
			dbg("└END to %d\n\n", action - REDUCE0);
			end_parser(lex, &state);
			break ;
		}
	}
}
