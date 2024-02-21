/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tables.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 19:30:27 by pedro             #+#    #+#             */
/*   Updated: 2024/02/20 19:41:47 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	return n
	n >= 0  && n < 55 : shift to state n
	n >= 55 && n < 93 : reduce state with rule n
	n == 93           : accept
	n == 94           : grammar error (vacio)
	n < 0             : error
*/

int	table_action(int state, int token)
{
	static unsigned char	action[826] = ""\
	"~~~.~/~)-01234Y" "~~~~~~~~~~~~~~}" "~~~~~~~~~~~~~~W"\
	"56~~~~~~~~~~~~X" "ZZ7~Z~Z~~~~~~~Z" "]]]~]~]~~~~~~~]"\
	"___~_~_~~~~~~~_" "```~`~`~~01234`" "hhh~h~h:<01234h"\
	"jjj~j~j?~01234j" "bbb~b~b~~bbbbbb" "ccc~c~c~~cccccc"\
	"kkk~k~kkkkkkkkk" "mmm~m~mmmmmmmmm" "~~~.~/~)-01234~"\
	"~~~.~/~)-01234~" "~~~~~~~B~~~~~~~" "~~~~~~~C~~~~~~~"\
	"~~~~~~~D~~~~~~~" "~~~~~~~~~EFG~H~" "~~~~~~~I~~~~~~~"\
	"~~~.~/~)-01234~" "~~~.~/~)-01234~" "~~~.~/~)-01234~"\
	"aaa~a~a~~01234a" "sss~s~s~~ssssss" "ggg~g~g?~01234g"\
	"lll~l~lllllllll" "nnn~n~nnnnnnnnn" "iii~i~iP~01234i"\
	"ooo~o~oo~oooooo" "qqq~q~qq~qqqqqq" "56~~Q~~~~~~~~~~"\
	"56~~~~R~~~~~~~~" "uuu~u~uuuuuuuuu" "vvv~v~vvvvvvvvv"\
	"www~w~wwwwwwwww" "~~~~~~~S~~~~~~~" "~~~~~~~T~~~~~~~"\
	"~~~~~~~U~~~~~~~" "~~~~~~~V~~~~~~~" "{{{~{~{{{{{{{{{"\
	"[[7~[~[~~~~~~~[" "\\\\7~\\~\\~~~~~~~\\" "^^^~^~^~~~~~~~^"\
	"ttt~t~t~~tttttt" "fff~f~fP~01234f" "ppp~p~pp~pppppp"\
	"rrr~r~rr~rrrrrr" "ddd~d~d~~dddddd" "eee~e~e~~eeeeee"\
	"xxx~x~xxxxxxxxx" "yyy~y~yyyyyyyyy" "zzz~z~zzzzzzzzz"\
	"|||~|~|||||||||";

//	dbg("reduce %d\n", action[NUM_TOKEN * state + token] - CHR_STATE0);
	if ((token >= 0 && token <= 14) && (state >= 0 && state <= 54))
		return (action[NUM_TOKEN * state + token] - CHR_STATE0);
	return (-1);
}

/*
	return n:
	n >= 0 && n <= 54: go to state n
	n == 94: grammar error
	n < 0  : error
*/

int	table_goto(int state, int n_terminal)
{
	static unsigned char	go_to[716] = ""\
	"!\"#$%&'~*+(~," "~~~~~~~~~~~~~" "~~~~~~~~~~~~~"\
	"~~~~~~~~~~~~~" "~~~~~~~~~~~~~" "~~~~~~~~~~~~~"\
	"~~~~~~~~~~~~~" "~~~~~~~8~~~~9" "~~~~~~~~~~~~;"\
	"~~~~~~~~~~~=>" "~~~~~~~~~~~~~" "~~~~~~~~~~~~~"\
	"~~~~~~~~~~~~~" "~~~~~~~~~~~~~" "~~@$%&'~*+(~,"\
	"~~A$%&'~*+(~," "~~~~~~~~~~~~~" "~~~~~~~~~~~~~"\
	"~~~~~~~~~~~~~" "~~~~~~~~~~~~~" "~~~~~~~~~~~~~"\
	"~~~J%&'~*+(~," "~~~K%&'~*+(~," "~~~~L&'~*+(~,"\
	"~~~~~~~~~~~~M" "~~~~~~~~~~~~~" "~~~~~~~~~~~N>"\
	"~~~~~~~~~~~~~" "~~~~~~~~~~~~~" "~~~~~~~~~~~~O"\
	"~~~~~~~~~~~~~" "~~~~~~~~~~~~~" "~~~~~~~~~~~~~"\
	"~~~~~~~~~~~~~" "~~~~~~~~~~~~~" "~~~~~~~~~~~~~"\
	"~~~~~~~~~~~~~" "~~~~~~~~~~~~~" "~~~~~~~~~~~~~"\
	"~~~~~~~~~~~~~" "~~~~~~~~~~~~~" "~~~~~~~~~~~~~"\
	"~~~~~~~~~~~~~" "~~~~~~~~~~~~~" "~~~~~~~~~~~~~"\
	"~~~~~~~~~~~~~" "~~~~~~~~~~~~O" "~~~~~~~~~~~~~"\
	"~~~~~~~~~~~~~" "~~~~~~~~~~~~~" "~~~~~~~~~~~~~"\
	"~~~~~~~~~~~~~" "~~~~~~~~~~~~~" "~~~~~~~~~~~~~"\
	"~~~~~~~~~~~~~";

	if ((n_terminal >= nt_accept && n_terminal <= nt_io_redirect)
		&& (state >= SHIFT0 && state <= SHIFT54))
		return (go_to[NUM_NTERMINALS * state + n_terminal] - CHR_STATE0);
	return (-1);
}

int	table_nt_generate(int rule_id)
{
	static int	nt_generate[NUM_RULES] = {\
		nt_accept, nt_program, nt_program,
		nt_and_or, nt_and_or, nt_and_or,
		nt_pipeline, nt_pipeline, nt_command,
		nt_command, nt_command, nt_compound_command,
		nt_compound_command, nt_brace_group, nt_subshell,
		nt_simple_command, nt_simple_command, nt_simple_command,
		nt_simple_command, nt_simple_command, nt_cmd_prefix,
		nt_cmd_prefix, nt_cmd_prefix, nt_cmd_prefix,
		nt_cmd_suffix, nt_cmd_suffix, nt_cmd_suffix,
		nt_cmd_suffix, nt_redirect_list, nt_redirect_list,
		nt_io_redirect, nt_io_redirect, nt_io_redirect,
		nt_io_redirect, nt_io_redirect, nt_io_redirect,
		nt_io_redirect, nt_io_redirect};

	return (nt_generate[rule_id]);
}

void	(*table_reduce(int rule_id))(t_dlst **, t_state **)
{
	static void	(*rule[NUM_RULES])(t_dlst **, t_state **) = {\
		rule_nothing,
		rule_nothing, rule_nothing, rule_nothing,
		rule_and_or1, rule_and_or2, rule_nothing,
		rule_pipeline, rule_nothing, rule_nothing,
		rule_command, rule_nothing, rule_nothing,
		rule_group, rule_subshell, 
		rule_simple1, rule_simple2, rule_simple3,
		rule_simple4, rule_simple5,
		rule_prefix1, rule_prefix2, rule_prefix3,
		rule_prefix4,
		rule_suffix1, rule_suffix2, rule_suffix3,
		rule_suffix4,
		rule_nothing, rule_redir_list, 
		rule_redir1, rule_redir2, rule_redir3,
		rule_redir4, rule_redir5, rule_redir6,
		rule_redir7, rule_redir8};
	return (rule[rule_id]);
}

