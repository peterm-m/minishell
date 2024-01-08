/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tables.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 19:30:27 by pedro             #+#    #+#             */
/*   Updated: 2024/01/08 19:35:49 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	return n
	n >= 0  && n < 55 : shift to state n
	n >= 55 && n < 93 : reduce state with rule n
	n == 93           : accept
	n == 94           : grammar error
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

void	(*table_reduce(int rule_id))(t_dlst **, t_state **, int )
{
	static void	(*rules[NUM_RULES])(t_dlst **, t_state **, int) = {\
		rules_accept, rules_program, rules_program,
		rules_and_or, rules_and_or, rules_and_or,
		rules_pipeline, rules_pipeline, rules_command,
		rules_command, rules_command, rules_compound,
		rules_compound, rules_group, rules_subshell,
		rules_simple_cmd, rules_simple_cmd, rules_simple_cmd,
		rules_simple_cmd, rules_simple_cmd, rules_cmd_prefix,
		rules_cmd_prefix, rules_cmd_prefix, rules_cmd_prefix,
		rules_cmd_suffix, rules_cmd_suffix, rules_cmd_suffix,
		rules_cmd_suffix, rules_redirect_list, rules_redirect_list,
		rules_io_redirect, rules_io_redirect, rules_io_redirect,
		rules_io_redirect, rules_io_redirect, rules_io_redirect,
		rules_io_redirect, rules_io_redirect};

	return (rules[rule_id]);
}
