/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:56:16 by pedromar          #+#    #+#             */
/*   Updated: 2024/01/06 20:01:15 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_dlstprint(void *data)
{
	printf("%d ", ((t_token *)data)->type);
}


static void	shift(t_dlst **lex, t_state **state, int action)
{
	t_state	*new;

	new = ft_dlstnew(malloc(sizeof(int)));
	*((int *)new->data) = action;
	ft_dlstaddf(state, new);
	*lex = (*lex)->next;
	printf("shift to %d\n", action);
	// printf("lex\t");
	// ft_dlstiter(*lex, ft_dlstprint);
	// printf("\nstate\t");
	// ft_dlstiter(*state, ft_dlstprint);
	// printf("\n");
	return ;
}

static void	reduce(t_dlst **lex, t_state **state, int action)
{
	int	id_rule;

	id_rule = action - REDUCE0;
	table_reduce(action - REDUCE0)(lex, state, id_rule);
	*((int *)(*state)->data) = table_goto(*((int *)(*state)->next->data), table_nt_generate(id_rule));
	printf("reduce %d and go to %d\n", id_rule, *((int *)(*state)->data));
	// printf("lex\t");
	// ft_dlstiter(*lex, ft_dlstprint);
	// printf("\nstate\t");
	// ft_dlstiter(*state, ft_dlstprint);
	// printf("\n");
	return ;
}

static void	end_parser(t_dlst **lex, t_state **state, int action)
{
	(void )lex;
	(void )state;

	// En caso de error implementar la limpieza
	// En caso de error implementar diagnostico
	if (action == ACCEPT)
		printf("END PARSER\n");
	else
		printf("Syntax Error.\n");
	return ;
};

void	syntax(t_dlst *lex)
{
	int			action;
	t_state		*state;

	state = ft_dlstnew(malloc(sizeof(int)));
	*((int *)state->data) = 0;
	// printf("lex\t");
	// ft_dlstiter(lex, ft_dlstprint);
	// printf("\nstate\t");
	// ft_dlstiter(state, ft_dlstprint);
	// printf("\n");
	while (1)
	{
		action = table_action(*((int *)state->data), ((t_token *)(lex->data))->type);
		if (action >= SHIFT0  && action <= SHIFT54)
			shift(&lex, &state, action);
		else if (action >= REDUCE0 && action <= REDUCE37)
			reduce(&lex, &state, action);
		else if (action == GRAMMAR_ERROR || action == UNDEFINED || action == ACCEPT)
		{
			end_parser(&lex, &state, action);
			break ;
		}
	}
	return ;
}

//t_token	*gen_tok(t_terminals type)
//{	
//	t_token	*tok;
//	tok = (t_token *)malloc(sizeof(t_token));
//	tok->type = type;
//	return (tok);	
//}
//
//
//
//int main()
//{
//	t_dlst	*lex;
//
//	lex = ft_dlstnew(gen_tok(tt_word));
//	ft_dlstaddb(&lex, ft_dlstnew(gen_tok(tt_pipe)));
//	ft_dlstaddb(&lex, ft_dlstnew(gen_tok(tt_word)));
//	ft_dlstaddb(&lex, ft_dlstnew(gen_tok(tt_end)));
//	syntax(lex);
//	return (0);
//}


/*
void	syntax(t_dlst *lex):
	Inicialmente en lex hay una lista de tokens.
	tras la función quedara un unico node con la estructura a ejecutar.
	Si error gramatical quedara
		lex->data = NULL; state = GRAMMAR_ERROR
	Si un token no definido:
		lex->data = NULL; state = UNDEFINED
	Si se aplica program : /empty/ (rule 2):
		lex->data = NULL; state = ACCEPT
*/

/*
static void	end_parser(t_dlst **lex, t_state **state, int action):
	limpia state y tokens
	imprime diagnostico
*/

/*
	shift:
		añade stado actual a state
		avanza token
*/

// * aqui deberia estar eliminados los nodos que se han usado en la reducion.
//
// * formada la estructura pertinente en la cabeza de lex
//
// * eliminados los nodos de state
//
// * actualizado el valor de state con la tabla go_to 