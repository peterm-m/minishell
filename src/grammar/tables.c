/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tables.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 19:30:27 by pedro             #+#    #+#             */
/*   Updated: 2024/02/25 19:21:17 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	@param state: The current state.
	@param token: The current token.

	Dado que estoy en estado state y el token actual
	¿cual es la acción que debo ejecutar?

	Implementacion:
	Las acciones estan numeradas.
	Las acciones tipo shift son numeradas por numeros [0, 55)
	Las acciones tipo reduce son numeradas por numeros [55, 93)
	El estado accept marca el final del parseo de forma exitosa
		accion numerada con 93
	Si se encuentra una combinación de tokens no reconocide
		se llega a parser error, accion numerada con 94
	Si el input es incorrecto se retorna -1. 

	Dado que se ha de usar un array muy grande, se ha usado una string,
	los ascii usado son usados con su valor nummerico. 

	Resumen:
	n >= 0  && n < 55 : shift to state n
	n >= 55 && n < 93 : reduce state with rule n
	n == 93           : accept
	n == 94           : grammar error (vacio)
	n < 0             : error
	TODO: traducir comentario
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
	@param state: The current state.
	@param token: The current token.

	Dado que tras aplicar la regla reduce, he terminado en el estado state,
	y se ha generado un elemento n_terminal ¿cual es el siguiente estado?

	Implementacion:
	Las acciones tipo shift son numeradas por numeros [0, 55)
	Estado de error esta numerado por 54
	Si input o valido -1

	Dado que se ha de usar un array muy grande, se ha usado una string,
	los ascii usado son usados con su valor nummerico. 

	Resumen:
	return n:
	n >= 0 && n <= 54: go to state n
	n == 94: grammar error
	n == -1 : error
	TODO: traducir comentario
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

/*
	@param rule_id: regla reduce que se ha aplicado

	¿Tras aplicar una regla reduce que tipo de token se ha generado?
	TODO: traducir comentario
*/

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

/*
	@param rule_id: regla reduce que se quiere aplicar

	Asocia un id de una reglla con la funcion a ejecutar.
	TODO: traducir comentario
*/

void	(*table_reduce(int rule_id))(t_dlst **lst, t_state **state)
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
