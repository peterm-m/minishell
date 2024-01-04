/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 20:51:01 by pedro             #+#    #+#             */
/*   Updated: 2024/01/04 22:59:19 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	rules_accept(t_dlst *lex, t_state *state, int rule)
{
	if (rule == 0)
		;
	state->data = table_goto(state->next->data, 0);
	printf("state %d rules_accept\n", state->data);
}

void	rules_program(t_dlst *lex, t_state *state, int rule)
{
	if (rule == 1)
		;
	else if (rule == 2)
		;
	state->data = table_goto(state->next->data, 1);
	printf("state %d rules_program\n", state->data);
}

void	rules_and_or(t_dlst *lex, t_state *state, int rule)
{
	if (rule == 3)
		;
	else if (rule == 4)
	{
		//lex->next->next->data = make_conection(lex->next->next->data, lex->data, AND_IF);
		pop_elements(lex, state, 2);
	}
	else if (rule == 5)
	{
		//lex->next->next->data = make_conection(lex->next->next->data, lex->data, OR_IF);
		pop_elements(lex, state, 2);
	}
	state->data = table_goto(state->next->data, 2);
	printf("state %d rules_and_or\n", state->data);
}

void	rules_pipeline(t_dlst *lex, t_state *state, int rule)
{
	if (rule == 6)
		;
	else if (rule == 7)
	{
		//lex->next->next->data = make_conection(lex->next->next->data, lex->data, _PIPE);
		pop_elements(lex, state, 2);
	}
	state->data = table_goto(state->next->data, 3);
	printf("state %d rules_pipeline\n", state->data);
}

void	rules_command(t_dlst *lex, t_state *state, int rule)
{
	if (rule == 8)
		;
	else if (rule == 9)
		;
	else if (rule == 10)
	{
		//append_redir(((t_command *)lex->next->data)->redirects, (t_redirect *)lex->data);
		pop_elements(lex, state, 1);
	}
	state->data = table_goto(state->next->data, 4);
	printf("state %d rules_command\n", state->data);
}

void	rules_commpound(t_dlst *lex, t_state *state, int rule)
{
	if (rule == 11)
		;
	else if (rule == 12)
		;
	state->data = table_goto(state->next->data, 6);
	printf("state %d rules_commpound\n", state->data);
}

void	rules_group(t_dlst *lex, t_state *state, int rule)
{
	if (rule == 13)
	{
		//lex->next->next->data = make_group((t_command *)lex->next->data);
		pop_elements(lex, state, 2);
	}
	state->data = table_goto(state->next->data, 8);
	printf("state %d rules_group\n", state->data);
}

void	rules_subshell(t_dlst *lex, t_state *state, int rule)
{
	if (rule == 14)
	{
		//lex->next->next->data = make_subshell((t_command *)lex->next->data);
		pop_elements(lex, state, 2);
	}
	state->data = table_goto(state->next->data, 9);
	printf("state %d rules_subshell\n", state->data);
}

void	rules_simple_cmd(t_dlst *lex, t_state *state, int rule)
{
	if (rule == 15)
	{
		pop_elements(lex, state, 2);
	}
	else if (rule == 16)
	{
		pop_elements(lex, state, 1);
	}
	else if (rule == 17)
		;
	else if (rule == 18)
	{
		pop_elements(lex, state, 1);
	}
	else if (rule == 19)
		;
	state->data = table_goto(state->next->data, 5);
	printf("state %d rules_simple_cmd\n", state->data);
}

void	rules_cmd_prefix(t_dlst *lex, t_state *state, int rule)
{
	if (rule == 20)
		;
	else if (rule == 21)
	{
		pop_elements(lex, state, 1);
	}
	else if (rule == 22)
		;
	else if (rule == 23)
	{
		pop_elements(lex, state, 1);
	}
	state->data = table_goto(state->next->data, 10);
	printf("state %d rules_cmd_prefix\n", state->data);
}

void	rules_cmd_suffix(t_dlst *lex, t_state *state, int rule)
{
	if (rule == 24)
		;
	else if (rule == 25)
	{
		pop_elements(lex, state, 1);
	}
	else if (rule == 26)
		;
	else if (rule == 27)
	{
		pop_elements(lex, state, 1);
	}
	state->data = table_goto(state->next->data, 11);
	printf("state %d rules_cmd_suffix\n", state->data);
}

void	rules_redirect_list(t_dlst *lex, t_state *state, int rule)
{
	if (rule == 28)
		;
	else if (rule == 29)
	{
		pop_elements(lex, state, 1);
	}
	state->data = table_goto(state->next->data, 7);
	printf("state %d rules_redirect_list\n", state->data);
}

void	rules_io_redirect(t_dlst *lex, t_state *state, int rule)
{
	if (rule == 30)
	{
		pop_elements(lex, state, 1);
	}
	else if (rule == 31)
	{
		pop_elements(lex, state, 1);
	}
	else if (rule == 32)
	{
		pop_elements(lex, state, 1);
	}
	else if (rule == 33)
	{
		pop_elements(lex, state, 2);
	}
	else if (rule == 34)
	{
		pop_elements(lex, state, 2);
	}
	else if (rule == 35)
	{
		pop_elements(lex, state, 2);
	}
	else if (rule == 36)
	{
		pop_elements(lex, state, 1);
	}
	else if (rule == 37)
	{
		pop_elements(lex, state, 2);
	}
	state->data = table_goto(state->next->data, 12);
	printf("state %d rules_io_redirect\n", state->data);
}
