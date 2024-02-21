/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 20:52:28 by pedromar          #+#    #+#             */
/*   Updated: 2024/02/21 16:54:30 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdlib.h>
#include "common.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                 LEXER TEST
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////// TOKENS

void	test_simple_tokens(void)
{
	t_dlst *out = NULL;
	t_token	*tok;

//----------------------------
	out = tokenize("");
	tok = out->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("&&");
	tok = out->data;
	TEST_CHECK(tok->flag == tt_and_if);
	TEST_CHECK(tok->str == NULL);
	tok = out->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("||"); //mirar
	tok = out->data;
	TEST_CHECK(tok->flag == tt_or_if);
	TEST_CHECK(tok->str == NULL);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("|");
	tok = out->data;
	TEST_CHECK(tok->flag == tt_pipe);
	TEST_CHECK(tok->str == NULL);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("{ }");
	tok = out->data;
	TEST_CHECK(tok->flag == tt_lbrace);
	TEST_CHECK(tok->str == NULL);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_rbrace);
	TEST_CHECK(tok->str == NULL);
	tok = out->next->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("{}");
	tok = out->data;
	TEST_CHECK(tok->flag == tt_lbrace);
	TEST_CHECK(tok->str == NULL);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_rbrace);
	TEST_CHECK(tok->str == NULL);
	tok = out->next->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("( )");
	tok = out->data;
	TEST_CHECK(tok->flag == tt_lbraket);
	TEST_CHECK(tok->str == NULL);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_rbraket);
	TEST_CHECK(tok->str == NULL);
	tok = out->next->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("()");
	tok = out->data;
	TEST_CHECK(tok->flag == tt_lbraket);
	TEST_CHECK(tok->str == NULL);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_rbraket);
	TEST_CHECK(tok->str == NULL);
	tok = out->next->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("word");
	tok = out->data;
	TEST_CHECK(tok->flag == tt_word);
	TEST_CHECK(strcmp(tok->str, "word") == 0);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("<");
	tok = out->data;
	TEST_CHECK(tok->flag == tt_less);
	TEST_CHECK(tok->str == NULL);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize(">");
	tok = out->data;
	TEST_CHECK(tok->flag == tt_great);
	TEST_CHECK(tok->str == NULL);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize(">>");
	tok = out->data;
	TEST_CHECK(tok->flag == tt_dgreat);
	TEST_CHECK(tok->str == NULL);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("<<");
	tok = out->data;
	TEST_CHECK(tok->flag == tt_dless);
	TEST_CHECK(tok->str == NULL);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("10");
	tok = out->data;
	TEST_CHECK(tok->flag == tt_io_number);
	TEST_CHECK(tok->str == NULL);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
}

void	test_expansion(void)
{
	t_dlst *out = NULL;
	t_token	*tok;

	out = tokenize("$");
	tok = out->data;
	TEST_CHECK(tok->flag == tt_word);
	TEST_CHECK(strcmp(tok->str, "$") == 0);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("$()");
	tok = out->data;
	TEST_CHECK(tok->flag == tt_word|COMMD_SUB);
	TEST_CHECK(strcmp(tok->str, "$()") == 0);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("${}");
	tok = out->data;
	TEST_CHECK(tok->flag == tt_word|PARAM_E);
	TEST_CHECK(strcmp(tok->str, "${}") == 0);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("*");
	tok = out->data;
	TEST_CHECK(tok->flag == tt_word|WILDCARD);
	TEST_CHECK(strcmp(tok->str, "*") == 0);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("$word");
	tok = out->data;
	TEST_CHECK(tok->flag == tt_word|PARAM_E);
	TEST_CHECK(strcmp(tok->str, "$word") == 0);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("wo$rd");
	tok = out->data;
	TEST_CHECK(tok->flag == tt_word|PARAM_E);
	TEST_CHECK(strcmp(tok->str, "wo$rd") == 0);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("word$");
	tok = out->data;
	TEST_CHECK(tok->flag == tt_word);
	TEST_CHECK(strcmp(tok->str, "word$") == 0);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("$(word)");
	tok = out->data;
	TEST_CHECK(tok->flag == tt_word|COMMD_SUB);
	TEST_CHECK(strcmp(tok->str, "$(word)") == 0);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("wo$(word)rd");
	tok = out->data;
	TEST_CHECK(tok->flag == tt_word|COMMD_SUB);
	TEST_CHECK(strcmp(tok->str, "wo$(word)rd") == 0);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("word$(word)");
	tok = out->data;
	TEST_CHECK(tok->flag == tt_word|COMMD_SUB);
	TEST_CHECK(strcmp(tok->str, "word$(word)") == 0);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("${word}");
	tok = out->data;
	TEST_CHECK(tok->flag == tt_word|PARAM_E);
	TEST_CHECK(strcmp(tok->str, "${word}") == 0);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("wo${word}rd");
	tok = out->data;
	TEST_CHECK(tok->flag == tt_word|PARAM_E);
	TEST_CHECK(strcmp(tok->str, "wo${word}rd") == 0);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
	//----------------------------
	out = tokenize("word${word}");
	tok = out->data;
	TEST_CHECK(tok->flag == tt_word|PARAM_E);
	TEST_CHECK(strcmp(tok->str, "word${word}") == 0);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("*word");
	tok = out->data;
	TEST_CHECK(tok->flag == tt_word|WILDCARD);
	TEST_CHECK(strcmp(tok->str, "*word") == 0);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("wo*rd");
	tok = out->data;
	TEST_CHECK(tok->flag == tt_word|WILDCARD);
	TEST_CHECK(strcmp(tok->str, "wo*rd") == 0);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("word*");
	tok = out->data;
	TEST_CHECK(tok->flag == tt_word|WILDCARD);
	TEST_CHECK(strcmp(tok->str, "*word") == 0);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
}

void	test_singleq(void)
{
	t_dlst *out = NULL;
	t_token	*tok;

	out = tokenize("\'\'");
	tok = out->data;
	TEST_CHECK(tok->flag == tt_word);
	TEST_CHECK(strcmp(tok->str, "\'\'") == 0);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("\'\"\'");
	tok = out->data;
	TEST_CHECK(tok->flag == tt_word);
	TEST_CHECK(strcmp(tok->str, "\'\"\'") == 0);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("\'\"\"\'");
	tok = out->data;
	TEST_CHECK(tok->flag == tt_word);
	TEST_CHECK(strcmp(tok->str, "\'\"\"\'") == 0);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("\'\t\'");
	tok = out->data;
	TEST_CHECK(tok->flag == tt_word);
	TEST_CHECK(strcmp(tok->str, "\'\t\'") == 0);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("\' \'");
	tok = out->data;
	TEST_CHECK(tok->flag == tt_word);
	TEST_CHECK(strcmp(tok->str, "\' \'") == 0);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("\'\n\'");
	tok = out->data;
	TEST_CHECK(tok->flag == tt_word);
	TEST_CHECK(strcmp(tok->str, "\'\n\'") == 0);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("\'&&\'");
	tok = out->data;
	TEST_CHECK(tok->flag == tt_word);
	TEST_CHECK(strcmp(tok->str, "\'&&\'") == 0);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("\'||\'");
	tok = out->data;
	TEST_CHECK(tok->flag == tt_word);
	TEST_CHECK(strcmp(tok->str, "\'||\'") == 0);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("\'|\'");
	tok = out->data;
	TEST_CHECK(tok->flag == tt_word);
	TEST_CHECK(strcmp(tok->str, "\'|\'") == 0);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("\'{ }\'");
	tok = out->data;
	TEST_CHECK(tok->flag == tt_word);
	TEST_CHECK(strcmp(tok->str, "\'{ }\'") == 0);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("\'{}\'");
	tok = out->data;
	TEST_CHECK(tok->flag == tt_word);
	TEST_CHECK(strcmp(tok->str, "\'{}\'") == 0);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("\'( )\'");
	tok = out->data;
	TEST_CHECK(tok->flag == tt_word);
	TEST_CHECK(strcmp(tok->str, "\'( )\'") == 0);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("\'()\'");
	tok = out->data;
	TEST_CHECK(1 == 0);
	tok = out->data;
	TEST_CHECK(tok->flag == tt_word);
	TEST_CHECK(strcmp(tok->str, "\'()\'") == 0);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("\'word\'");
	tok = out->data;
	TEST_CHECK(1 == 0);
	tok = out->data;
	TEST_CHECK(tok->flag == tt_word);
	TEST_CHECK(strcmp(tok->str, "\'word\'") == 0);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("\'<\'");
	tok = out->data;
	TEST_CHECK(1 == 0);
	tok = out->data;
	TEST_CHECK(tok->flag == tt_word);
	TEST_CHECK(strcmp(tok->str, "\'\'") == 0);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("\'>\'");
	tok = out->data;
	TEST_CHECK(1 == 0);
	tok = out->data;
	TEST_CHECK(tok->flag == tt_word);
	TEST_CHECK(strcmp(tok->str, "\'>\'") == 0);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("\'>>\'");
	tok = out->data;
	TEST_CHECK(1 == 0);
	tok = out->data;
	TEST_CHECK(tok->flag == tt_word);
	TEST_CHECK(strcmp(tok->str, "\'>>\'") == 0);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("\'<<\'");
	tok = out->data;
	TEST_CHECK(1 == 0);
	tok = out->data;
	TEST_CHECK(tok->flag == tt_word);
	TEST_CHECK(strcmp(tok->str, "\'<<\'") == 0);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("\'10\'");
	tok = out->data;
	TEST_CHECK(1 == 0);
	tok = out->data;
	TEST_CHECK(tok->flag == tt_word);
	TEST_CHECK(strcmp(tok->str, "\'10\'") == 0);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("\'$word\'");
	tok = out->data;
	TEST_CHECK(1 == 0);
	tok = out->data;
	TEST_CHECK(tok->flag == tt_word);
	TEST_CHECK(strcmp(tok->str, "\'$word\'") == 0);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("\'$(word)\'");
	tok = out->data;
	TEST_CHECK(1 == 0);
	tok = out->data;
	TEST_CHECK(tok->flag == tt_word);
	TEST_CHECK(strcmp(tok->str, "\'$(word)\'") == 0);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("\'${word}\'");
	tok = out->data;
	TEST_CHECK(1 == 0);
	tok = out->data;
	TEST_CHECK(tok->flag == tt_word);
	TEST_CHECK(strcmp(tok->str, "\'${word}\'") == 0);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("\'wo*rd\'");
	tok = out->data;
	TEST_CHECK(1 == 0);
	tok = out->data;
	TEST_CHECK(tok->flag == tt_word);
	TEST_CHECK(strcmp(tok->str, "\'wo*rd\'") == 0);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
}

void	test_doubleq(void)
{
	t_dlst *out = NULL;
	t_token	*tok;

	out = tokenize("\"\"");
	tok = out->data;
	TEST_CHECK(tok->flag == tt_word);
	TEST_CHECK(strcmp(tok->str, "\"\"") == 0);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("\"\'\"");
	tok = out->data;
	TEST_CHECK(tok->flag == tt_word);
	TEST_CHECK(strcmp(tok->str, "\"\'\"") == 0);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("\"\'\'\"");
	tok = out->data;
	TEST_CHECK(tok->flag == tt_word);
	TEST_CHECK(strcmp(tok->str, "\"\'\'\"") == 0);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("\"\t\"");
	tok = out->data;
	TEST_CHECK(tok->flag == tt_word);
	TEST_CHECK(strcmp(tok->str, "\"\t\"") == 0);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("\" \"");
	tok = out->data;
	TEST_CHECK(tok->flag == tt_word);
	TEST_CHECK(strcmp(tok->str, "\" \"") == 0);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("\"\n\"");
	tok = out->data;
	TEST_CHECK(tok->flag == tt_word);
	TEST_CHECK(strcmp(tok->str, "\"\n\"") == 0);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("\"&&\"");
	tok = out->data;
	TEST_CHECK(tok->flag == tt_word);
	TEST_CHECK(strcmp(tok->str, "\"&&\"") == 0);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("\"||\"");
	tok = out->data;
	TEST_CHECK(tok->flag == tt_word);
	TEST_CHECK(strcmp(tok->str, "\"||\"") == 0);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("\"|\"");
	tok = out->data;
	TEST_CHECK(tok->flag == tt_word);
	TEST_CHECK(strcmp(tok->str, "\"|\"") == 0);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("\"{ }\"");
	tok = out->data;
	TEST_CHECK(tok->flag == tt_word);
	TEST_CHECK(strcmp(tok->str, "\"{ }\"") == 0);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("\"{}\"");
	tok = out->data;
	TEST_CHECK(tok->flag == tt_word);
	TEST_CHECK(strcmp(tok->str, "\"{}\"") == 0);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("\"( )\"");
	tok = out->data;
	TEST_CHECK(tok->flag == tt_word);
	TEST_CHECK(strcmp(tok->str, "\"( )\"") == 0);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("\"()\"");
	tok = out->data;
	TEST_CHECK(1 == 0);
	tok = out->data;
	TEST_CHECK(tok->flag == tt_word);
	TEST_CHECK(strcmp(tok->str, "\"()\"") == 0);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("\"word\"");
	tok = out->data;
	TEST_CHECK(1 == 0);
	tok = out->data;
	TEST_CHECK(tok->flag == tt_word);
	TEST_CHECK(strcmp(tok->str, "\"word\"") == 0);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("\"<\"");
	tok = out->data;
	TEST_CHECK(1 == 0);
	tok = out->data;
	TEST_CHECK(tok->flag == tt_word);
	TEST_CHECK(strcmp(tok->str, "\"\"") == 0);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("\">\"");
	tok = out->data;
	TEST_CHECK(1 == 0);
	tok = out->data;
	TEST_CHECK(tok->flag == tt_word);
	TEST_CHECK(strcmp(tok->str, "\">\"") == 0);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("\">>\"");
	tok = out->data;
	TEST_CHECK(1 == 0);
	tok = out->data;
	TEST_CHECK(tok->flag == tt_word);
	TEST_CHECK(strcmp(tok->str, "\">>\"") == 0);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("\"<<\"");
	tok = out->data;
	TEST_CHECK(1 == 0);
	tok = out->data;
	TEST_CHECK(tok->flag == tt_word);
	TEST_CHECK(strcmp(tok->str, "\"<<\"") == 0);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("\"10\"");
	tok = out->data;
	TEST_CHECK(1 == 0);
	tok = out->data;
	TEST_CHECK(tok->flag == tt_word);
	TEST_CHECK(strcmp(tok->str, "\"10\"") == 0);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("\"$word\"");
	tok = out->data;
	TEST_CHECK(1 == 0);
	tok = out->data;
	TEST_CHECK(tok->flag == tt_word|PARAM_E);
	TEST_CHECK(strcmp(tok->str, "\"$word\"") == 0);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("\"$(word)\"");
	tok = out->data;
	TEST_CHECK(1 == 0);
	tok = out->data;
	TEST_CHECK(tok->flag == tt_word|COMMD_SUB);
	TEST_CHECK(strcmp(tok->str, "\"$(word)\"") == 0);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("\"${word}\"");
	tok = out->data;
	TEST_CHECK(1 == 0);
	tok = out->data;
	TEST_CHECK(tok->flag == tt_word|PARAM_E);
	TEST_CHECK(strcmp(tok->str, "\"${word}\"") == 0);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("\"wo*rd\"");
	tok = out->data;
	TEST_CHECK(1 == 0);
	tok = out->data;
	TEST_CHECK(tok->flag == tt_word);
	TEST_CHECK(strcmp(tok->str, "\"wo*rd\"") == 0);
	tok = out->next->data;
	TEST_CHECK(tok->flag == tt_end);
	TEST_CHECK(tok->str == NULL);
	ft_dlstclear(&out, free_token);
}

void	test_multitok(void)
{
	t_dlst *out = NULL;
	t_token	*tok;

	out = tokenize("word word");
	TEST_CHECK(1 == 0);
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("word | word");
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("word && word");
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("word || word");
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("(word)");
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("{word}");
	ft_dlstclear(&out, free_token);
//----------------------------
	out = tokenize("word > 10");
	ft_dlstclear(&out, free_token);
//----------------------------
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                 GRAMMAR TEST
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////// TABLE ACTION 

void	test_action_table(void)
{
	//tt_and_if
	TEST_CHECK(table_action(0, tt_and_if) + 32 == 126);
	TEST_CHECK(table_action(1, tt_and_if) + 32 == 126);
	TEST_CHECK(table_action(2, tt_and_if) + 32 == 126);
	TEST_CHECK(table_action(3, tt_and_if) + 32 == 53);
	TEST_CHECK(table_action(4, tt_and_if) + 32 == 90);
	TEST_CHECK(table_action(5, tt_and_if) + 32 == 93);
	TEST_CHECK(table_action(6, tt_and_if) + 32 == 95);
	TEST_CHECK(table_action(7, tt_and_if) + 32 == 96);
	TEST_CHECK(table_action(8, tt_and_if) + 32 == 104);
	TEST_CHECK(table_action(9, tt_and_if) + 32 == 106);
	TEST_CHECK(table_action(10, tt_and_if) + 32 == 98);
	TEST_CHECK(table_action(11, tt_and_if) + 32 == 99);
	TEST_CHECK(table_action(12, tt_and_if) + 32 == 107);
	TEST_CHECK(table_action(13, tt_and_if) + 32 == 109);
	TEST_CHECK(table_action(14, tt_and_if) + 32 == 126);
	TEST_CHECK(table_action(15, tt_and_if) + 32 == 126);
	TEST_CHECK(table_action(16, tt_and_if) + 32 == 126);
	TEST_CHECK(table_action(17, tt_and_if) + 32 == 126);
	TEST_CHECK(table_action(18, tt_and_if) + 32 == 126);
	TEST_CHECK(table_action(19, tt_and_if) + 32 == 126);
	TEST_CHECK(table_action(20, tt_and_if) + 32 == 126);
	TEST_CHECK(table_action(21, tt_and_if) + 32 == 126);
	TEST_CHECK(table_action(22, tt_and_if) + 32 == 126);
	TEST_CHECK(table_action(23, tt_and_if) + 32 == 126);
	TEST_CHECK(table_action(24, tt_and_if) + 32 == 97);
	TEST_CHECK(table_action(25, tt_and_if) + 32 == 115);
	TEST_CHECK(table_action(26, tt_and_if) + 32 == 103);
	TEST_CHECK(table_action(27, tt_and_if) + 32 == 108);
	TEST_CHECK(table_action(28, tt_and_if) + 32 == 110);
	TEST_CHECK(table_action(29, tt_and_if) + 32 == 105);
	TEST_CHECK(table_action(30, tt_and_if) + 32 == 111);
	TEST_CHECK(table_action(31, tt_and_if) + 32 == 113);
	TEST_CHECK(table_action(32, tt_and_if) + 32 == 53);
	TEST_CHECK(table_action(33, tt_and_if) + 32 == 53);
	TEST_CHECK(table_action(34, tt_and_if) + 32 == 117);
	TEST_CHECK(table_action(35, tt_and_if) + 32 == 118);
	TEST_CHECK(table_action(36, tt_and_if) + 32 == 119);
	TEST_CHECK(table_action(37, tt_and_if) + 32 == 126);
	TEST_CHECK(table_action(38, tt_and_if) + 32 == 126);
	TEST_CHECK(table_action(39, tt_and_if) + 32 == 126);
	TEST_CHECK(table_action(40, tt_and_if) + 32 == 126);
	TEST_CHECK(table_action(41, tt_and_if) + 32 == 123);
	TEST_CHECK(table_action(42, tt_and_if) + 32 == 91);
	TEST_CHECK(table_action(43, tt_and_if) + 32 == 92);
	TEST_CHECK(table_action(44, tt_and_if) + 32 == 94);
	TEST_CHECK(table_action(45, tt_and_if) + 32 == 116);
	TEST_CHECK(table_action(46, tt_and_if) + 32 == 102);
	TEST_CHECK(table_action(47, tt_and_if) + 32 == 112);
	TEST_CHECK(table_action(48, tt_and_if) + 32 == 114);
	TEST_CHECK(table_action(49, tt_and_if) + 32 == 100);
	TEST_CHECK(table_action(50, tt_and_if) + 32 == 101);
	TEST_CHECK(table_action(51, tt_and_if) + 32 == 120);
	TEST_CHECK(table_action(52, tt_and_if) + 32 == 121);
	TEST_CHECK(table_action(53, tt_and_if) + 32 == 122);
	TEST_CHECK(table_action(54, tt_and_if) + 32 == 124);

	//tt_or_if

	TEST_CHECK(table_action(0, tt_or_if) + 32 == 126);
	TEST_CHECK(table_action(1, tt_or_if) + 32 == 126);
	TEST_CHECK(table_action(2, tt_or_if) + 32 == 126);
	TEST_CHECK(table_action(3, tt_or_if) + 32 == 54);
	TEST_CHECK(table_action(4, tt_or_if) + 32 == 90);
	TEST_CHECK(table_action(5, tt_or_if) + 32 == 93);
	TEST_CHECK(table_action(6, tt_or_if) + 32 == 95);
	TEST_CHECK(table_action(7, tt_or_if) + 32 == 96);
	TEST_CHECK(table_action(8, tt_or_if) + 32 == 104);
	TEST_CHECK(table_action(9, tt_or_if) + 32 == 106);
	TEST_CHECK(table_action(10, tt_or_if) + 32 == 98);
	TEST_CHECK(table_action(11, tt_or_if) + 32 == 99);
	TEST_CHECK(table_action(12, tt_or_if) + 32 == 107);
	TEST_CHECK(table_action(13, tt_or_if) + 32 == 109);
	TEST_CHECK(table_action(14, tt_or_if) + 32 == 126);
	TEST_CHECK(table_action(15, tt_or_if) + 32 == 126);
	TEST_CHECK(table_action(16, tt_or_if) + 32 == 126);
	TEST_CHECK(table_action(17, tt_or_if) + 32 == 126);
	TEST_CHECK(table_action(18, tt_or_if) + 32 == 126);
	TEST_CHECK(table_action(19, tt_or_if) + 32 == 126);
	TEST_CHECK(table_action(20, tt_or_if) + 32 == 126);
	TEST_CHECK(table_action(21, tt_or_if) + 32 == 126);
	TEST_CHECK(table_action(22, tt_or_if) + 32 == 126);
	TEST_CHECK(table_action(23, tt_or_if) + 32 == 126);
	TEST_CHECK(table_action(24, tt_or_if) + 32 == 97);
	TEST_CHECK(table_action(25, tt_or_if) + 32 == 115);
	TEST_CHECK(table_action(26, tt_or_if) + 32 == 103);
	TEST_CHECK(table_action(27, tt_or_if) + 32 == 108);
	TEST_CHECK(table_action(28, tt_or_if) + 32 == 110);
	TEST_CHECK(table_action(29, tt_or_if) + 32 == 105);
	TEST_CHECK(table_action(30, tt_or_if) + 32 == 111);
	TEST_CHECK(table_action(31, tt_or_if) + 32 == 113);
	TEST_CHECK(table_action(32, tt_or_if) + 32 == 54);
	TEST_CHECK(table_action(33, tt_or_if) + 32 == 54);
	TEST_CHECK(table_action(34, tt_or_if) + 32 == 117);
	TEST_CHECK(table_action(35, tt_or_if) + 32 == 118);
	TEST_CHECK(table_action(36, tt_or_if) + 32 == 119);
	TEST_CHECK(table_action(37, tt_or_if) + 32 == 126);
	TEST_CHECK(table_action(38, tt_or_if) + 32 == 126);
	TEST_CHECK(table_action(39, tt_or_if) + 32 == 126);
	TEST_CHECK(table_action(40, tt_or_if) + 32 == 126);
	TEST_CHECK(table_action(41, tt_or_if) + 32 == 123);
	TEST_CHECK(table_action(42, tt_or_if) + 32 == 91);
	TEST_CHECK(table_action(43, tt_or_if) + 32 == 92);
	TEST_CHECK(table_action(44, tt_or_if) + 32 == 94);
	TEST_CHECK(table_action(45, tt_or_if) + 32 == 116);
	TEST_CHECK(table_action(46, tt_or_if) + 32 == 102);
	TEST_CHECK(table_action(47, tt_or_if) + 32 == 112);
	TEST_CHECK(table_action(48, tt_or_if) + 32 == 114);
	TEST_CHECK(table_action(49, tt_or_if) + 32 == 100);
	TEST_CHECK(table_action(50, tt_or_if) + 32 == 101);
	TEST_CHECK(table_action(51, tt_or_if) + 32 == 120);
	TEST_CHECK(table_action(52, tt_or_if) + 32 == 121);
	TEST_CHECK(table_action(53, tt_or_if) + 32 == 122);
	TEST_CHECK(table_action(54, tt_or_if) + 32 == 124);	

	//tt_pipe

	TEST_CHECK(table_action(0, tt_pipe) + 32 == 126);
	TEST_CHECK(table_action(1, tt_pipe) + 32 == 126);
	TEST_CHECK(table_action(2, tt_pipe) + 32 == 126);
	TEST_CHECK(table_action(3, tt_pipe) + 32 == 126);
	TEST_CHECK(table_action(4, tt_pipe) + 32 == 55);
	TEST_CHECK(table_action(5, tt_pipe) + 32 == 93);
	TEST_CHECK(table_action(6, tt_pipe) + 32 == 95);
	TEST_CHECK(table_action(7, tt_pipe) + 32 == 96);
	TEST_CHECK(table_action(8, tt_pipe) + 32 == 104);
	TEST_CHECK(table_action(9, tt_pipe) + 32 == 106);
	TEST_CHECK(table_action(10, tt_pipe) + 32 == 98);
	TEST_CHECK(table_action(11, tt_pipe) + 32 == 99);
	TEST_CHECK(table_action(12, tt_pipe) + 32 == 107);
	TEST_CHECK(table_action(13, tt_pipe) + 32 == 109);
	TEST_CHECK(table_action(14, tt_pipe) + 32 == 126);
	TEST_CHECK(table_action(15, tt_pipe) + 32 == 126);
	TEST_CHECK(table_action(16, tt_pipe) + 32 == 126);
	TEST_CHECK(table_action(17, tt_pipe) + 32 == 126);
	TEST_CHECK(table_action(18, tt_pipe) + 32 == 126);
	TEST_CHECK(table_action(19, tt_pipe) + 32 == 126);
	TEST_CHECK(table_action(20, tt_pipe) + 32 == 126);
	TEST_CHECK(table_action(21, tt_pipe) + 32 == 126);
	TEST_CHECK(table_action(22, tt_pipe) + 32 == 126);
	TEST_CHECK(table_action(23, tt_pipe) + 32 == 126);
	TEST_CHECK(table_action(24, tt_pipe) + 32 == 97);
	TEST_CHECK(table_action(25, tt_pipe) + 32 == 115);
	TEST_CHECK(table_action(26, tt_pipe) + 32 == 103);
	TEST_CHECK(table_action(27, tt_pipe) + 32 == 108);
	TEST_CHECK(table_action(28, tt_pipe) + 32 == 110);
	TEST_CHECK(table_action(29, tt_pipe) + 32 == 105);
	TEST_CHECK(table_action(30, tt_pipe) + 32 == 111);
	TEST_CHECK(table_action(31, tt_pipe) + 32 == 113);
	TEST_CHECK(table_action(32, tt_pipe) + 32 == 126);
	TEST_CHECK(table_action(33, tt_pipe) + 32 == 126);
	TEST_CHECK(table_action(34, tt_pipe) + 32 == 117);
	TEST_CHECK(table_action(35, tt_pipe) + 32 == 118);
	TEST_CHECK(table_action(36, tt_pipe) + 32 == 119);
	TEST_CHECK(table_action(37, tt_pipe) + 32 == 126);
	TEST_CHECK(table_action(38, tt_pipe) + 32 == 126);
	TEST_CHECK(table_action(39, tt_pipe) + 32 == 126);
	TEST_CHECK(table_action(40, tt_pipe) + 32 == 126);
	TEST_CHECK(table_action(41, tt_pipe) + 32 == 123);
	TEST_CHECK(table_action(42, tt_pipe) + 32 == 55);
	TEST_CHECK(table_action(43, tt_pipe) + 32 == 55);
	TEST_CHECK(table_action(44, tt_pipe) + 32 == 94);
	TEST_CHECK(table_action(45, tt_pipe) + 32 == 116);
	TEST_CHECK(table_action(46, tt_pipe) + 32 == 102);
	TEST_CHECK(table_action(47, tt_pipe) + 32 == 112);
	TEST_CHECK(table_action(48, tt_pipe) + 32 == 114);
	TEST_CHECK(table_action(49, tt_pipe) + 32 == 100);
	TEST_CHECK(table_action(50, tt_pipe) + 32 == 101);
	TEST_CHECK(table_action(51, tt_pipe) + 32 == 120);
	TEST_CHECK(table_action(52, tt_pipe) + 32 == 121);
	TEST_CHECK(table_action(53, tt_pipe) + 32 == 122);
	TEST_CHECK(table_action(54, tt_pipe) + 32 == 124);

	//tt_lbrace

	TEST_CHECK(table_action(0, tt_lbrace) + 32 == 46);
	TEST_CHECK(table_action(1, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(2, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(3, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(4, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(5, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(6, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(7, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(8, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(9, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(10, tt_lbrace) + 32 ==126);
	TEST_CHECK(table_action(11, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(12, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(13, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(14, tt_lbrace) + 32 == 46);
	TEST_CHECK(table_action(15, tt_lbrace) + 32 == 46);
	TEST_CHECK(table_action(16, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(17, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(18, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(19, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(20, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(21, tt_lbrace) + 32 == 46);
	TEST_CHECK(table_action(22, tt_lbrace) + 32 == 46);
	TEST_CHECK(table_action(23, tt_lbrace) + 32 == 46);
	TEST_CHECK(table_action(24, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(25, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(26, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(27, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(28, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(29, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(30, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(31, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(32, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(33, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(34, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(35, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(36, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(37, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(38, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(39, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(40, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(41, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(42, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(43, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(44, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(45, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(46, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(47, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(48, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(49, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(50, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(51, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(52, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(53, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(54, tt_lbrace) + 32 == 126);

	//tt_rbrace

	TEST_CHECK(table_action(0, tt_rbrace) + 32 == 126);
	TEST_CHECK(table_action(1, tt_rbrace) + 32 == 126);
	TEST_CHECK(table_action(2, tt_rbrace) + 32 == 126);
	TEST_CHECK(table_action(3, tt_rbrace) + 32 == 126);
	TEST_CHECK(table_action(4, tt_rbrace) + 32 == 90);
	TEST_CHECK(table_action(5, tt_rbrace) + 32 == 93);
	TEST_CHECK(table_action(6, tt_rbrace) + 32 == 95);
	TEST_CHECK(table_action(7, tt_rbrace) + 32 == 96);
	TEST_CHECK(table_action(8, tt_rbrace) + 32 == 104);
	TEST_CHECK(table_action(9, tt_rbrace) + 32 == 106);
	TEST_CHECK(table_action(10, tt_rbrace) + 32 == 98);
	TEST_CHECK(table_action(11, tt_rbrace) + 32 == 99);
	TEST_CHECK(table_action(12, tt_rbrace) + 32 == 107);
	TEST_CHECK(table_action(13, tt_rbrace) + 32 == 109);
	TEST_CHECK(table_action(14, tt_rbrace) + 32 == 126);
	TEST_CHECK(table_action(15, tt_rbrace) + 32 == 126);
	TEST_CHECK(table_action(16, tt_rbrace) + 32 == 126);
	TEST_CHECK(table_action(17, tt_rbrace) + 32 == 126);
	TEST_CHECK(table_action(18, tt_rbrace) + 32 == 126);
	TEST_CHECK(table_action(19, tt_rbrace) + 32 == 126);
	TEST_CHECK(table_action(20, tt_rbrace) + 32 == 126);
	TEST_CHECK(table_action(21, tt_rbrace) + 32 == 126);
	TEST_CHECK(table_action(22, tt_rbrace) + 32 == 126);
	TEST_CHECK(table_action(23, tt_rbrace) + 32 == 126);
	TEST_CHECK(table_action(24, tt_rbrace) + 32 == 97);
	TEST_CHECK(table_action(25, tt_rbrace) + 32 == 115);
	TEST_CHECK(table_action(26, tt_rbrace) + 32 == 103);
	TEST_CHECK(table_action(27, tt_rbrace) + 32 == 108);
	TEST_CHECK(table_action(28, tt_rbrace) + 32 == 110);
	TEST_CHECK(table_action(29, tt_rbrace) + 32 == 105);
	TEST_CHECK(table_action(30, tt_rbrace) + 32 == 111);
	TEST_CHECK(table_action(31, tt_rbrace) + 32 == 113);
	TEST_CHECK(table_action(32, tt_rbrace) + 32 == 81);
	TEST_CHECK(table_action(33, tt_rbrace) + 32 == 126);
	TEST_CHECK(table_action(34, tt_rbrace) + 32 == 117);
	TEST_CHECK(table_action(35, tt_rbrace) + 32 == 118);
	TEST_CHECK(table_action(36, tt_rbrace) + 32 == 119);
	TEST_CHECK(table_action(37, tt_rbrace) + 32 == 126);
	TEST_CHECK(table_action(38, tt_rbrace) + 32 == 126);
	TEST_CHECK(table_action(39, tt_rbrace) + 32 == 126);
	TEST_CHECK(table_action(40, tt_rbrace) + 32 == 126);
	TEST_CHECK(table_action(41, tt_rbrace) + 32 == 123);
	TEST_CHECK(table_action(42, tt_rbrace) + 32 == 91);
	TEST_CHECK(table_action(43, tt_rbrace) + 32 == 92);
	TEST_CHECK(table_action(44, tt_rbrace) + 32 == 94);
	TEST_CHECK(table_action(45, tt_rbrace) + 32 == 116);
	TEST_CHECK(table_action(46, tt_rbrace) + 32 == 102);
	TEST_CHECK(table_action(47, tt_rbrace) + 32 == 112);
	TEST_CHECK(table_action(48, tt_rbrace) + 32 == 114);
	TEST_CHECK(table_action(49, tt_rbrace) + 32 == 100);
	TEST_CHECK(table_action(50, tt_rbrace) + 32 == 101);
	TEST_CHECK(table_action(51, tt_rbrace) + 32 == 120);
	TEST_CHECK(table_action(52, tt_rbrace) + 32 == 121);
	TEST_CHECK(table_action(53, tt_rbrace) + 32 == 122);
	TEST_CHECK(table_action(54, tt_rbrace) + 32 == 124);	

	//tt_lbraket

	TEST_CHECK(table_action(0, tt_lbraket) + 32 == 47);
	TEST_CHECK(table_action(1, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(2, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(3, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(4, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(5, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(6, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(7, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(8, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(9, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(10, tt_lbraket) + 32 ==126);
	TEST_CHECK(table_action(11, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(12, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(13, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(14, tt_lbraket) + 32 == 47);
	TEST_CHECK(table_action(15, tt_lbraket) + 32 == 47);
	TEST_CHECK(table_action(16, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(17, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(18, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(19, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(20, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(21, tt_lbraket) + 32 == 47);
	TEST_CHECK(table_action(22, tt_lbraket) + 32 == 47);
	TEST_CHECK(table_action(23, tt_lbraket) + 32 == 47);
	TEST_CHECK(table_action(24, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(25, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(26, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(27, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(28, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(29, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(30, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(31, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(32, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(33, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(34, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(35, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(36, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(37, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(38, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(39, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(40, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(41, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(42, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(43, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(44, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(45, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(46, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(47, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(48, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(49, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(50, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(51, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(52, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(53, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(54, tt_lbraket) + 32 == 126);

	//tt_rbraket

	TEST_CHECK(table_action(0, tt_rbraket) + 32 == 126);
	TEST_CHECK(table_action(1, tt_rbraket) + 32 == 126);
	TEST_CHECK(table_action(2, tt_rbraket) + 32 == 126);
	TEST_CHECK(table_action(3, tt_rbraket) + 32 == 126);
	TEST_CHECK(table_action(4, tt_rbraket) + 32 == 90);
	TEST_CHECK(table_action(5, tt_rbraket) + 32 == 93);
	TEST_CHECK(table_action(6, tt_rbraket) + 32 == 95);
	TEST_CHECK(table_action(7, tt_rbraket) + 32 == 96);
	TEST_CHECK(table_action(8, tt_rbraket) + 32 == 104);
	TEST_CHECK(table_action(9, tt_rbraket) + 32 == 106);
	TEST_CHECK(table_action(10, tt_rbraket) + 32 == 98);
	TEST_CHECK(table_action(11, tt_rbraket) + 32 == 99);
	TEST_CHECK(table_action(12, tt_rbraket) + 32 == 107);
	TEST_CHECK(table_action(13, tt_rbraket) + 32 == 109);
	TEST_CHECK(table_action(14, tt_rbraket) + 32 == 126);
	TEST_CHECK(table_action(15, tt_rbraket) + 32 == 126);
	TEST_CHECK(table_action(16, tt_rbraket) + 32 == 126);
	TEST_CHECK(table_action(17, tt_rbraket) + 32 == 126);
	TEST_CHECK(table_action(18, tt_rbraket) + 32 == 126);
	TEST_CHECK(table_action(19, tt_rbraket) + 32 == 126);
	TEST_CHECK(table_action(20, tt_rbraket) + 32 == 126);
	TEST_CHECK(table_action(21, tt_rbraket) + 32 == 126);
	TEST_CHECK(table_action(22, tt_rbraket) + 32 == 126);
	TEST_CHECK(table_action(23, tt_rbraket) + 32 == 126);
	TEST_CHECK(table_action(24, tt_rbraket) + 32 == 97);
	TEST_CHECK(table_action(25, tt_rbraket) + 32 == 115);
	TEST_CHECK(table_action(26, tt_rbraket) + 32 == 103);
	TEST_CHECK(table_action(27, tt_rbraket) + 32 == 108);
	TEST_CHECK(table_action(28, tt_rbraket) + 32 == 110);
	TEST_CHECK(table_action(29, tt_rbraket) + 32 == 105);
	TEST_CHECK(table_action(30, tt_rbraket) + 32 == 111);
	TEST_CHECK(table_action(31, tt_rbraket) + 32 == 113);
	TEST_CHECK(table_action(32, tt_rbraket) + 32 == 126);
	TEST_CHECK(table_action(33, tt_rbraket) + 32 == 82);
	TEST_CHECK(table_action(34, tt_rbraket) + 32 == 117);
	TEST_CHECK(table_action(35, tt_rbraket) + 32 == 118);
	TEST_CHECK(table_action(36, tt_rbraket) + 32 == 119);
	TEST_CHECK(table_action(37, tt_rbraket) + 32 == 126);
	TEST_CHECK(table_action(38, tt_rbraket) + 32 == 126);
	TEST_CHECK(table_action(39, tt_rbraket) + 32 == 126);
	TEST_CHECK(table_action(40, tt_rbraket) + 32 == 126);
	TEST_CHECK(table_action(41, tt_rbraket) + 32 == 123);
	TEST_CHECK(table_action(42, tt_rbraket) + 32 == 91);
	TEST_CHECK(table_action(43, tt_rbraket) + 32 == 92);
	TEST_CHECK(table_action(44, tt_rbraket) + 32 == 94);
	TEST_CHECK(table_action(45, tt_rbraket) + 32 == 116);
	TEST_CHECK(table_action(46, tt_rbraket) + 32 == 102);
	TEST_CHECK(table_action(47, tt_rbraket) + 32 == 112);
	TEST_CHECK(table_action(48, tt_rbraket) + 32 == 114);
	TEST_CHECK(table_action(49, tt_rbraket) + 32 == 100);
	TEST_CHECK(table_action(50, tt_rbraket) + 32 == 101);
	TEST_CHECK(table_action(51, tt_rbraket) + 32 == 120);
	TEST_CHECK(table_action(52, tt_rbraket) + 32 == 121);
	TEST_CHECK(table_action(53, tt_rbraket) + 32 == 122);
	TEST_CHECK(table_action(54, tt_rbraket) + 32 == 124);

	//WORD

	TEST_CHECK(table_action(0, tt_word) + 32 == 41);
	TEST_CHECK(table_action(1, tt_word) + 32 == 126);
	TEST_CHECK(table_action(2, tt_word) + 32 == 126);
	TEST_CHECK(table_action(3, tt_word) + 32 == 126);
	TEST_CHECK(table_action(4, tt_word) + 32 == 126);
	TEST_CHECK(table_action(5, tt_word) + 32 == 126);
	TEST_CHECK(table_action(6, tt_word) + 32 == 126);
	TEST_CHECK(table_action(7, tt_word) + 32 == 126);
	TEST_CHECK(table_action(8, tt_word) + 32 == 58);
	TEST_CHECK(table_action(9, tt_word) + 32 == 63);
	TEST_CHECK(table_action(10, tt_word) + 32 == 126);
	TEST_CHECK(table_action(11, tt_word) + 32 == 126);
	TEST_CHECK(table_action(12, tt_word) + 32 == 107);
	TEST_CHECK(table_action(13, tt_word) + 32 == 109);
	TEST_CHECK(table_action(14, tt_word) + 32 == 41);
	TEST_CHECK(table_action(15, tt_word) + 32 == 41);
	TEST_CHECK(table_action(16, tt_word) + 32 == 66);
	TEST_CHECK(table_action(17, tt_word) + 32 == 67);
	TEST_CHECK(table_action(18, tt_word) + 32 == 68);
	TEST_CHECK(table_action(19, tt_word) + 32 == 126);
	TEST_CHECK(table_action(20, tt_word) + 32 == 73);
	TEST_CHECK(table_action(21, tt_word) + 32 == 41);
	TEST_CHECK(table_action(22, tt_word) + 32 == 41);
	TEST_CHECK(table_action(23, tt_word) + 32 == 41);
	TEST_CHECK(table_action(24, tt_word) + 32 == 126);
	TEST_CHECK(table_action(25, tt_word) + 32 == 126);
	TEST_CHECK(table_action(26, tt_word) + 32 == 63);
	TEST_CHECK(table_action(27, tt_word) + 32 == 108);
	TEST_CHECK(table_action(28, tt_word) + 32 == 110);
	TEST_CHECK(table_action(29, tt_word) + 32 == 80);
	TEST_CHECK(table_action(30, tt_word) + 32 == 111);
	TEST_CHECK(table_action(31, tt_word) + 32 == 113);
	TEST_CHECK(table_action(32, tt_word) + 32 == 126);
	TEST_CHECK(table_action(33, tt_word) + 32 == 126);
	TEST_CHECK(table_action(34, tt_word) + 32 == 117);
	TEST_CHECK(table_action(35, tt_word) + 32 == 118);
	TEST_CHECK(table_action(36, tt_word) + 32 == 119);
	TEST_CHECK(table_action(37, tt_word) + 32 == 83);
	TEST_CHECK(table_action(38, tt_word) + 32 == 84);
	TEST_CHECK(table_action(39, tt_word) + 32 == 85);
	TEST_CHECK(table_action(40, tt_word) + 32 == 86);
	TEST_CHECK(table_action(41, tt_word) + 32 == 123);
	TEST_CHECK(table_action(42, tt_word) + 32 == 126);
	TEST_CHECK(table_action(43, tt_word) + 32 == 126);
	TEST_CHECK(table_action(44, tt_word) + 32 == 126);
	TEST_CHECK(table_action(45, tt_word) + 32 == 126);
	TEST_CHECK(table_action(46, tt_word) + 32 == 80);
	TEST_CHECK(table_action(47, tt_word) + 32 == 112);
	TEST_CHECK(table_action(48, tt_word) + 32 == 114);
	TEST_CHECK(table_action(49, tt_word) + 32 == 126);
	TEST_CHECK(table_action(50, tt_word) + 32 == 126);
	TEST_CHECK(table_action(51, tt_word) + 32 == 120);
	TEST_CHECK(table_action(52, tt_word) + 32 == 121);
	TEST_CHECK(table_action(53, tt_word) + 32 == 122);
	TEST_CHECK(table_action(54, tt_word) + 32 == 124);

	//ASSIGMENT T_WORD

	TEST_CHECK(table_action(0, tt_assignment_word) + 32 == 45);
	TEST_CHECK(table_action(1, tt_assignment_word) + 32 == 126);
	TEST_CHECK(table_action(2, tt_assignment_word) + 32 == 126);
	TEST_CHECK(table_action(3, tt_assignment_word) + 32 == 126);
	TEST_CHECK(table_action(4, tt_assignment_word) + 32 == 126);
	TEST_CHECK(table_action(5, tt_assignment_word) + 32 == 126);
	TEST_CHECK(table_action(6, tt_assignment_word) + 32 == 126);
	TEST_CHECK(table_action(7, tt_assignment_word) + 32 == 126);
	TEST_CHECK(table_action(8, tt_assignment_word) + 32 == 60);
	TEST_CHECK(table_action(9, tt_assignment_word) + 32 == 126);
	TEST_CHECK(table_action(10, tt_assignment_word) + 32 ==126);
	TEST_CHECK(table_action(11, tt_assignment_word) + 32 == 126);
	TEST_CHECK(table_action(12, tt_assignment_word) + 32 == 107);
	TEST_CHECK(table_action(13, tt_assignment_word) + 32 == 109);
	TEST_CHECK(table_action(14, tt_assignment_word) + 32 == 45);
	TEST_CHECK(table_action(15, tt_assignment_word) + 32 == 45);
	TEST_CHECK(table_action(16, tt_assignment_word) + 32 == 126);
	TEST_CHECK(table_action(17, tt_assignment_word) + 32 == 126);
	TEST_CHECK(table_action(18, tt_assignment_word) + 32 == 126);
	TEST_CHECK(table_action(19, tt_assignment_word) + 32 == 126);
	TEST_CHECK(table_action(20, tt_assignment_word) + 32 == 126);
	TEST_CHECK(table_action(21, tt_assignment_word) + 32 == 45);
	TEST_CHECK(table_action(22, tt_assignment_word) + 32 == 45);
	TEST_CHECK(table_action(23, tt_assignment_word) + 32 == 45);
	TEST_CHECK(table_action(24, tt_assignment_word) + 32 == 126);
	TEST_CHECK(table_action(25, tt_assignment_word) + 32 == 126);
	TEST_CHECK(table_action(26, tt_assignment_word) + 32 == 126);
	TEST_CHECK(table_action(27, tt_assignment_word) + 32 == 108);
	TEST_CHECK(table_action(28, tt_assignment_word) + 32 == 110);
	TEST_CHECK(table_action(29, tt_assignment_word) + 32 == 126);
	TEST_CHECK(table_action(30, tt_assignment_word) + 32 == 126);
	TEST_CHECK(table_action(31, tt_assignment_word) + 32 == 126);
	TEST_CHECK(table_action(32, tt_assignment_word) + 32 == 126);
	TEST_CHECK(table_action(33, tt_assignment_word) + 32 == 126);
	TEST_CHECK(table_action(34, tt_assignment_word) + 32 == 117);
	TEST_CHECK(table_action(35, tt_assignment_word) + 32 == 118);
	TEST_CHECK(table_action(36, tt_assignment_word) + 32 == 119);
	TEST_CHECK(table_action(37, tt_assignment_word) + 32 == 126);
	TEST_CHECK(table_action(38, tt_assignment_word) + 32 == 126);
	TEST_CHECK(table_action(39, tt_assignment_word) + 32 == 126);
	TEST_CHECK(table_action(40, tt_assignment_word) + 32 == 126);
	TEST_CHECK(table_action(41, tt_assignment_word) + 32 == 123);
	TEST_CHECK(table_action(42, tt_assignment_word) + 32 == 126);
	TEST_CHECK(table_action(43, tt_assignment_word) + 32 == 126);
	TEST_CHECK(table_action(44, tt_assignment_word) + 32 == 126);
	TEST_CHECK(table_action(45, tt_assignment_word) + 32 == 126);
	TEST_CHECK(table_action(46, tt_assignment_word) + 32 == 126);
	TEST_CHECK(table_action(47, tt_assignment_word) + 32 == 126);
	TEST_CHECK(table_action(48, tt_assignment_word) + 32 == 126);
	TEST_CHECK(table_action(49, tt_assignment_word) + 32 == 126);
	TEST_CHECK(table_action(50, tt_assignment_word) + 32 == 126);
	TEST_CHECK(table_action(51, tt_assignment_word) + 32 == 120);
	TEST_CHECK(table_action(52, tt_assignment_word) + 32 == 121);
	TEST_CHECK(table_action(53, tt_assignment_word) + 32 == 122);
	TEST_CHECK(table_action(54, tt_assignment_word) + 32 == 124);

	//tt_less

	TEST_CHECK(table_action(0, tt_less) + 32 == 48);
	TEST_CHECK(table_action(1, tt_less) + 32 == 126);
	TEST_CHECK(table_action(2, tt_less) + 32 == 126);
	TEST_CHECK(table_action(3, tt_less) + 32 == 126);
	TEST_CHECK(table_action(4, tt_less) + 32 == 126);
	TEST_CHECK(table_action(5, tt_less) + 32 == 126);
	TEST_CHECK(table_action(6, tt_less) + 32 == 126);
	TEST_CHECK(table_action(7, tt_less) + 32 == 48);
	TEST_CHECK(table_action(8, tt_less) + 32 == 48);
	TEST_CHECK(table_action(9, tt_less) + 32 == 48);
	TEST_CHECK(table_action(10, tt_less) + 32 ==98);
	TEST_CHECK(table_action(11, tt_less) + 32 == 99);
	TEST_CHECK(table_action(12, tt_less) + 32 == 107);
	TEST_CHECK(table_action(13, tt_less) + 32 == 109);
	TEST_CHECK(table_action(14, tt_less) + 32 == 48);
	TEST_CHECK(table_action(15, tt_less) + 32 == 48);
	TEST_CHECK(table_action(16, tt_less) + 32 == 126);
	TEST_CHECK(table_action(17, tt_less) + 32 == 126);
	TEST_CHECK(table_action(18, tt_less) + 32 == 126);
	TEST_CHECK(table_action(19, tt_less) + 32 == 69);
	TEST_CHECK(table_action(20, tt_less) + 32 == 126);
	TEST_CHECK(table_action(21, tt_less) + 32 == 48);
	TEST_CHECK(table_action(22, tt_less) + 32 == 48);
	TEST_CHECK(table_action(23, tt_less) + 32 == 48);
	TEST_CHECK(table_action(24, tt_less) + 32 == 48);
	TEST_CHECK(table_action(25, tt_less) + 32 == 115);
	TEST_CHECK(table_action(26, tt_less) + 32 == 48);
	TEST_CHECK(table_action(27, tt_less) + 32 == 108);
	TEST_CHECK(table_action(28, tt_less) + 32 == 110);
	TEST_CHECK(table_action(29, tt_less) + 32 == 48);
	TEST_CHECK(table_action(30, tt_less) + 32 == 111);
	TEST_CHECK(table_action(31, tt_less) + 32 == 113);
	TEST_CHECK(table_action(32, tt_less) + 32 == 126);
	TEST_CHECK(table_action(33, tt_less) + 32 == 126);
	TEST_CHECK(table_action(34, tt_less) + 32 == 117);
	TEST_CHECK(table_action(35, tt_less) + 32 == 118);
	TEST_CHECK(table_action(36, tt_less) + 32 == 119);
	TEST_CHECK(table_action(37, tt_less) + 32 == 126);
	TEST_CHECK(table_action(38, tt_less) + 32 == 126);
	TEST_CHECK(table_action(39, tt_less) + 32 == 126);
	TEST_CHECK(table_action(40, tt_less) + 32 == 126);
	TEST_CHECK(table_action(41, tt_less) + 32 == 123);
	TEST_CHECK(table_action(42, tt_less) + 32 == 126);
	TEST_CHECK(table_action(43, tt_less) + 32 == 126);
	TEST_CHECK(table_action(44, tt_less) + 32 == 126);
	TEST_CHECK(table_action(45, tt_less) + 32 == 116);
	TEST_CHECK(table_action(46, tt_less) + 32 == 48);
	TEST_CHECK(table_action(47, tt_less) + 32 == 112);
	TEST_CHECK(table_action(48, tt_less) + 32 == 114);
	TEST_CHECK(table_action(49, tt_less) + 32 == 100);
	TEST_CHECK(table_action(50, tt_less) + 32 == 101);
	TEST_CHECK(table_action(51, tt_less) + 32 == 120);
	TEST_CHECK(table_action(52, tt_less) + 32 == 121);
	TEST_CHECK(table_action(53, tt_less) + 32 == 122);
	TEST_CHECK(table_action(54, tt_less) + 32 == 124);

	//tt_great

	TEST_CHECK(table_action(0, tt_great) + 32 == 49);
	TEST_CHECK(table_action(1, tt_great) + 32 == 126);
	TEST_CHECK(table_action(2, tt_great) + 32 == 126);
	TEST_CHECK(table_action(3, tt_great) + 32 == 126);
	TEST_CHECK(table_action(4, tt_great) + 32 == 126);
	TEST_CHECK(table_action(5, tt_great) + 32 == 126);
	TEST_CHECK(table_action(6, tt_great) + 32 == 126);
	TEST_CHECK(table_action(7, tt_great) + 32 == 49);
	TEST_CHECK(table_action(8, tt_great) + 32 == 49);
	TEST_CHECK(table_action(9, tt_great) + 32 == 49);
	TEST_CHECK(table_action(10, tt_great) + 32 ==98);
	TEST_CHECK(table_action(11, tt_great) + 32 == 99);
	TEST_CHECK(table_action(12, tt_great) + 32 == 107);
	TEST_CHECK(table_action(13, tt_great) + 32 == 109);
	TEST_CHECK(table_action(14, tt_great) + 32 == 49);
	TEST_CHECK(table_action(15, tt_great) + 32 == 49);
	TEST_CHECK(table_action(16, tt_great) + 32 == 126);
	TEST_CHECK(table_action(17, tt_great) + 32 == 126);
	TEST_CHECK(table_action(18, tt_great) + 32 == 126);
	TEST_CHECK(table_action(19, tt_great) + 32 == 70);
	TEST_CHECK(table_action(20, tt_great) + 32 == 126);
	TEST_CHECK(table_action(21, tt_great) + 32 == 49);
	TEST_CHECK(table_action(22, tt_great) + 32 == 49);
	TEST_CHECK(table_action(23, tt_great) + 32 == 49);
	TEST_CHECK(table_action(24, tt_great) + 32 == 49);
	TEST_CHECK(table_action(25, tt_great) + 32 == 115);
	TEST_CHECK(table_action(26, tt_great) + 32 == 49);
	TEST_CHECK(table_action(27, tt_great) + 32 == 108);
	TEST_CHECK(table_action(28, tt_great) + 32 == 110);
	TEST_CHECK(table_action(29, tt_great) + 32 == 49);
	TEST_CHECK(table_action(30, tt_great) + 32 == 111);
	TEST_CHECK(table_action(31, tt_great) + 32 == 113);
	TEST_CHECK(table_action(32, tt_great) + 32 == 126);
	TEST_CHECK(table_action(33, tt_great) + 32 == 126);
	TEST_CHECK(table_action(34, tt_great) + 32 == 117);
	TEST_CHECK(table_action(35, tt_great) + 32 == 118);
	TEST_CHECK(table_action(36, tt_great) + 32 == 119);
	TEST_CHECK(table_action(37, tt_great) + 32 == 126);
	TEST_CHECK(table_action(38, tt_great) + 32 == 126);
	TEST_CHECK(table_action(39, tt_great) + 32 == 126);
	TEST_CHECK(table_action(40, tt_great) + 32 == 126);
	TEST_CHECK(table_action(41, tt_great) + 32 == 123);
	TEST_CHECK(table_action(42, tt_great) + 32 == 126);
	TEST_CHECK(table_action(43, tt_great) + 32 == 126);
	TEST_CHECK(table_action(44, tt_great) + 32 == 126);
	TEST_CHECK(table_action(45, tt_great) + 32 == 116);
	TEST_CHECK(table_action(46, tt_great) + 32 == 49);
	TEST_CHECK(table_action(47, tt_great) + 32 == 112);
	TEST_CHECK(table_action(48, tt_great) + 32 == 114);
	TEST_CHECK(table_action(49, tt_great) + 32 == 100);
	TEST_CHECK(table_action(50, tt_great) + 32 == 101);
	TEST_CHECK(table_action(51, tt_great) + 32 == 120);
	TEST_CHECK(table_action(52, tt_great) + 32 == 121);
	TEST_CHECK(table_action(53, tt_great) + 32 == 122);
	TEST_CHECK(table_action(54, tt_great) + 32 == 124);

	//tt_dgreat

	TEST_CHECK(table_action(0, tt_dgreat) + 32 == 50);
	TEST_CHECK(table_action(1, tt_dgreat) + 32 == 126);
	TEST_CHECK(table_action(2, tt_dgreat) + 32 == 126);
	TEST_CHECK(table_action(3, tt_dgreat) + 32 == 126);
	TEST_CHECK(table_action(4, tt_dgreat) + 32 == 126);
	TEST_CHECK(table_action(5, tt_dgreat) + 32 == 126);
	TEST_CHECK(table_action(6, tt_dgreat) + 32 == 126);
	TEST_CHECK(table_action(7, tt_dgreat) + 32 == 50);
	TEST_CHECK(table_action(8, tt_dgreat) + 32 == 50);
	TEST_CHECK(table_action(9, tt_dgreat) + 32 == 50);
	TEST_CHECK(table_action(10, tt_dgreat) + 32 ==98);
	TEST_CHECK(table_action(11, tt_dgreat) + 32 == 99);
	TEST_CHECK(table_action(12, tt_dgreat) + 32 == 107);
	TEST_CHECK(table_action(13, tt_dgreat) + 32 == 109);
	TEST_CHECK(table_action(14, tt_dgreat) + 32 == 50);
	TEST_CHECK(table_action(15, tt_dgreat) + 32 == 50);
	TEST_CHECK(table_action(16, tt_dgreat) + 32 == 126);
	TEST_CHECK(table_action(17, tt_dgreat) + 32 == 126);
	TEST_CHECK(table_action(18, tt_dgreat) + 32 == 126);
	TEST_CHECK(table_action(19, tt_dgreat) + 32 == 71);
	TEST_CHECK(table_action(20, tt_dgreat) + 32 == 126);
	TEST_CHECK(table_action(21, tt_dgreat) + 32 == 50);
	TEST_CHECK(table_action(22, tt_dgreat) + 32 == 50);
	TEST_CHECK(table_action(23, tt_dgreat) + 32 == 50);
	TEST_CHECK(table_action(24, tt_dgreat) + 32 == 50);
	TEST_CHECK(table_action(25, tt_dgreat) + 32 == 115);
	TEST_CHECK(table_action(26, tt_dgreat) + 32 == 50);
	TEST_CHECK(table_action(27, tt_dgreat) + 32 == 108);
	TEST_CHECK(table_action(28, tt_dgreat) + 32 == 110);
	TEST_CHECK(table_action(29, tt_dgreat) + 32 == 50);
	TEST_CHECK(table_action(30, tt_dgreat) + 32 == 111);
	TEST_CHECK(table_action(31, tt_dgreat) + 32 == 113);
	TEST_CHECK(table_action(32, tt_dgreat) + 32 == 126);
	TEST_CHECK(table_action(33, tt_dgreat) + 32 == 126);
	TEST_CHECK(table_action(34, tt_dgreat) + 32 == 117);
	TEST_CHECK(table_action(35, tt_dgreat) + 32 == 118);
	TEST_CHECK(table_action(36, tt_dgreat) + 32 == 119);
	TEST_CHECK(table_action(37, tt_dgreat) + 32 == 126);
	TEST_CHECK(table_action(38, tt_dgreat) + 32 == 126);
	TEST_CHECK(table_action(39, tt_dgreat) + 32 == 126);
	TEST_CHECK(table_action(40, tt_dgreat) + 32 == 126);
	TEST_CHECK(table_action(41, tt_dgreat) + 32 == 123);
	TEST_CHECK(table_action(42, tt_dgreat) + 32 == 126);
	TEST_CHECK(table_action(43, tt_dgreat) + 32 == 126);
	TEST_CHECK(table_action(44, tt_dgreat) + 32 == 126);
	TEST_CHECK(table_action(45, tt_dgreat) + 32 == 116);
	TEST_CHECK(table_action(46, tt_dgreat) + 32 == 50);
	TEST_CHECK(table_action(47, tt_dgreat) + 32 == 112);
	TEST_CHECK(table_action(48, tt_dgreat) + 32 == 114);
	TEST_CHECK(table_action(49, tt_dgreat) + 32 == 100);
	TEST_CHECK(table_action(50, tt_dgreat) + 32 == 101);
	TEST_CHECK(table_action(51, tt_dgreat) + 32 == 120);
	TEST_CHECK(table_action(52, tt_dgreat) + 32 == 121);
	TEST_CHECK(table_action(53, tt_dgreat) + 32 == 122);
	TEST_CHECK(table_action(54, tt_dgreat) + 32 == 124);

	//tt_io_number

	TEST_CHECK(table_action(0, tt_io_number) + 32 == 51);
	TEST_CHECK(table_action(1, tt_io_number) + 32 == 126);
	TEST_CHECK(table_action(2, tt_io_number) + 32 == 126);
	TEST_CHECK(table_action(3, tt_io_number) + 32 == 126);
	TEST_CHECK(table_action(4, tt_io_number) + 32 == 126);
	TEST_CHECK(table_action(5, tt_io_number) + 32 == 126);
	TEST_CHECK(table_action(6, tt_io_number) + 32 == 126);
	TEST_CHECK(table_action(7, tt_io_number) + 32 == 51);
	TEST_CHECK(table_action(8, tt_io_number) + 32 == 51);
	TEST_CHECK(table_action(9, tt_io_number) + 32 == 51);
	TEST_CHECK(table_action(10, tt_io_number) + 32 ==98);
	TEST_CHECK(table_action(11, tt_io_number) + 32 == 99);
	TEST_CHECK(table_action(12, tt_io_number) + 32 == 107);
	TEST_CHECK(table_action(13, tt_io_number) + 32 == 109);
	TEST_CHECK(table_action(14, tt_io_number) + 32 == 51);
	TEST_CHECK(table_action(15, tt_io_number) + 32 == 51);
	TEST_CHECK(table_action(16, tt_io_number) + 32 == 126);
	TEST_CHECK(table_action(17, tt_io_number) + 32 == 126);
	TEST_CHECK(table_action(18, tt_io_number) + 32 == 126);
	TEST_CHECK(table_action(19, tt_io_number) + 32 == 126);
	TEST_CHECK(table_action(20, tt_io_number) + 32 == 126);
	TEST_CHECK(table_action(21, tt_io_number) + 32 == 51);
	TEST_CHECK(table_action(22, tt_io_number) + 32 == 51);
	TEST_CHECK(table_action(23, tt_io_number) + 32 == 51);
	TEST_CHECK(table_action(24, tt_io_number) + 32 == 51);
	TEST_CHECK(table_action(25, tt_io_number) + 32 == 115);
	TEST_CHECK(table_action(26, tt_io_number) + 32 == 51);
	TEST_CHECK(table_action(27, tt_io_number) + 32 == 108);
	TEST_CHECK(table_action(28, tt_io_number) + 32 == 110);
	TEST_CHECK(table_action(29, tt_io_number) + 32 == 51);
	TEST_CHECK(table_action(30, tt_io_number) + 32 == 111);
	TEST_CHECK(table_action(31, tt_io_number) + 32 == 113);
	TEST_CHECK(table_action(32, tt_io_number) + 32 == 126);
	TEST_CHECK(table_action(33, tt_io_number) + 32 == 126);
	TEST_CHECK(table_action(34, tt_io_number) + 32 == 117);
	TEST_CHECK(table_action(35, tt_io_number) + 32 == 118);
	TEST_CHECK(table_action(36, tt_io_number) + 32 == 119);
	TEST_CHECK(table_action(37, tt_io_number) + 32 == 126);
	TEST_CHECK(table_action(38, tt_io_number) + 32 == 126);
	TEST_CHECK(table_action(39, tt_io_number) + 32 == 126);
	TEST_CHECK(table_action(40, tt_io_number) + 32 == 126);
	TEST_CHECK(table_action(41, tt_io_number) + 32 == 123);
	TEST_CHECK(table_action(42, tt_io_number) + 32 == 126);
	TEST_CHECK(table_action(43, tt_io_number) + 32 == 126);
	TEST_CHECK(table_action(44, tt_io_number) + 32 == 126);
	TEST_CHECK(table_action(45, tt_io_number) + 32 == 116);
	TEST_CHECK(table_action(46, tt_io_number) + 32 == 51);
	TEST_CHECK(table_action(47, tt_io_number) + 32 == 112);
	TEST_CHECK(table_action(48, tt_io_number) + 32 == 114);
	TEST_CHECK(table_action(49, tt_io_number) + 32 == 100);
	TEST_CHECK(table_action(50, tt_io_number) + 32 == 101);
	TEST_CHECK(table_action(51, tt_io_number) + 32 == 120);
	TEST_CHECK(table_action(52, tt_io_number) + 32 == 121);
	TEST_CHECK(table_action(53, tt_io_number) + 32 == 122);
	TEST_CHECK(table_action(54, tt_io_number) + 32 == 124);

	//tt_dless

	TEST_CHECK(table_action(0, tt_dless) + 32 == 52);
	TEST_CHECK(table_action(1, tt_dless) + 32 == 126);
	TEST_CHECK(table_action(2, tt_dless) + 32 == 126);
	TEST_CHECK(table_action(3, tt_dless) + 32 == 126);
	TEST_CHECK(table_action(4, tt_dless) + 32 == 126);
	TEST_CHECK(table_action(5, tt_dless) + 32 == 126);
	TEST_CHECK(table_action(6, tt_dless) + 32 == 126);
	TEST_CHECK(table_action(7, tt_dless) + 32 == 52);
	TEST_CHECK(table_action(8, tt_dless) + 32 == 52);
	TEST_CHECK(table_action(9, tt_dless) + 32 == 52);
	TEST_CHECK(table_action(10, tt_dless) + 32 ==98);
	TEST_CHECK(table_action(11, tt_dless) + 32 == 99);
	TEST_CHECK(table_action(12, tt_dless) + 32 == 107);
	TEST_CHECK(table_action(13, tt_dless) + 32 == 109);
	TEST_CHECK(table_action(14, tt_dless) + 32 == 52);
	TEST_CHECK(table_action(15, tt_dless) + 32 == 52);
	TEST_CHECK(table_action(16, tt_dless) + 32 == 126);
	TEST_CHECK(table_action(17, tt_dless) + 32 == 126);
	TEST_CHECK(table_action(18, tt_dless) + 32 == 126);
	TEST_CHECK(table_action(19, tt_dless) + 32 == 72);
	TEST_CHECK(table_action(20, tt_dless) + 32 == 126);
	TEST_CHECK(table_action(21, tt_dless) + 32 == 52);
	TEST_CHECK(table_action(22, tt_dless) + 32 == 52);
	TEST_CHECK(table_action(23, tt_dless) + 32 == 52);
	TEST_CHECK(table_action(24, tt_dless) + 32 == 52);
	TEST_CHECK(table_action(25, tt_dless) + 32 == 115);
	TEST_CHECK(table_action(26, tt_dless) + 32 == 52);
	TEST_CHECK(table_action(27, tt_dless) + 32 == 108);
	TEST_CHECK(table_action(28, tt_dless) + 32 == 110);
	TEST_CHECK(table_action(29, tt_dless) + 32 == 52);
	TEST_CHECK(table_action(30, tt_dless) + 32 == 111);
	TEST_CHECK(table_action(31, tt_dless) + 32 == 113);
	TEST_CHECK(table_action(32, tt_dless) + 32 == 126);
	TEST_CHECK(table_action(33, tt_dless) + 32 == 126);
	TEST_CHECK(table_action(34, tt_dless) + 32 == 117);
	TEST_CHECK(table_action(35, tt_dless) + 32 == 118);
	TEST_CHECK(table_action(36, tt_dless) + 32 == 119);
	TEST_CHECK(table_action(37, tt_dless) + 32 == 126);
	TEST_CHECK(table_action(38, tt_dless) + 32 == 126);
	TEST_CHECK(table_action(39, tt_dless) + 32 == 126);
	TEST_CHECK(table_action(40, tt_dless) + 32 == 126);
	TEST_CHECK(table_action(41, tt_dless) + 32 == 123);
	TEST_CHECK(table_action(42, tt_dless) + 32 == 126);
	TEST_CHECK(table_action(43, tt_dless) + 32 == 126);
	TEST_CHECK(table_action(44, tt_dless) + 32 == 126);
	TEST_CHECK(table_action(45, tt_dless) + 32 == 116);
	TEST_CHECK(table_action(46, tt_dless) + 32 == 52);
	TEST_CHECK(table_action(47, tt_dless) + 32 == 112);
	TEST_CHECK(table_action(48, tt_dless) + 32 == 114);
	TEST_CHECK(table_action(49, tt_dless) + 32 == 100);
	TEST_CHECK(table_action(50, tt_dless) + 32 == 101);
	TEST_CHECK(table_action(51, tt_dless) + 32 == 120);
	TEST_CHECK(table_action(52, tt_dless) + 32 == 121);
	TEST_CHECK(table_action(53, tt_dless) + 32 == 122);
	TEST_CHECK(table_action(54, tt_dless) + 32 == 124);

	//tt_end

	TEST_CHECK(table_action(0, tt_end) + 32 == 89);
	TEST_CHECK(table_action(1, tt_end) + 32 == 125);
	TEST_CHECK(table_action(2, tt_end) + 32 == 87);
	TEST_CHECK(table_action(3, tt_end) + 32 == 88);
	TEST_CHECK(table_action(4, tt_end) + 32 == 90);
	TEST_CHECK(table_action(5, tt_end) + 32 == 93);
	TEST_CHECK(table_action(6, tt_end) + 32 == 95);
	TEST_CHECK(table_action(7, tt_end) + 32 == 96);
	TEST_CHECK(table_action(8, tt_end) + 32 == 104);
	TEST_CHECK(table_action(9, tt_end) + 32 == 106);
	TEST_CHECK(table_action(10, tt_end) + 32 == 98);
	TEST_CHECK(table_action(11, tt_end) + 32 == 99);
	TEST_CHECK(table_action(12, tt_end) + 32 == 107);
	TEST_CHECK(table_action(13, tt_end) + 32 == 109);
	TEST_CHECK(table_action(14, tt_end) + 32 == 126);
	TEST_CHECK(table_action(15, tt_end) + 32 == 126);
	TEST_CHECK(table_action(16, tt_end) + 32 == 126);
	TEST_CHECK(table_action(17, tt_end) + 32 == 126);
	TEST_CHECK(table_action(18, tt_end) + 32 == 126);
	TEST_CHECK(table_action(19, tt_end) + 32 == 126);
	TEST_CHECK(table_action(20, tt_end) + 32 == 126);
	TEST_CHECK(table_action(21, tt_end) + 32 == 126);
	TEST_CHECK(table_action(22, tt_end) + 32 == 126);
	TEST_CHECK(table_action(23, tt_end) + 32 == 126);
	TEST_CHECK(table_action(24, tt_end) + 32 == 97);
	TEST_CHECK(table_action(25, tt_end) + 32 == 115);
	TEST_CHECK(table_action(26, tt_end) + 32 == 103);
	TEST_CHECK(table_action(27, tt_end) + 32 == 108);
	TEST_CHECK(table_action(28, tt_end) + 32 == 110);
	TEST_CHECK(table_action(29, tt_end) + 32 == 105);
	TEST_CHECK(table_action(30, tt_end) + 32 == 111);
	TEST_CHECK(table_action(31, tt_end) + 32 == 113);
	TEST_CHECK(table_action(32, tt_end) + 32 == 126);
	TEST_CHECK(table_action(33, tt_end) + 32 == 126);
	TEST_CHECK(table_action(34, tt_end) + 32 == 117);
	TEST_CHECK(table_action(35, tt_end) + 32 == 118);
	TEST_CHECK(table_action(36, tt_end) + 32 == 119);
	TEST_CHECK(table_action(37, tt_end) + 32 == 126);
	TEST_CHECK(table_action(38, tt_end) + 32 == 126);
	TEST_CHECK(table_action(39, tt_end) + 32 == 126);
	TEST_CHECK(table_action(40, tt_end) + 32 == 126);
	TEST_CHECK(table_action(41, tt_end) + 32 == 123);
	TEST_CHECK(table_action(42, tt_end) + 32 == 91);
	TEST_CHECK(table_action(43, tt_end) + 32 == 92);
	TEST_CHECK(table_action(44, tt_end) + 32 == 94);
	TEST_CHECK(table_action(45, tt_end) + 32 == 116);
	TEST_CHECK(table_action(46, tt_end) + 32 == 102);
	TEST_CHECK(table_action(47, tt_end) + 32 == 112);
	TEST_CHECK(table_action(48, tt_end) + 32 == 114);
	TEST_CHECK(table_action(49, tt_end) + 32 == 100);
	TEST_CHECK(table_action(50, tt_end) + 32 == 101);
	TEST_CHECK(table_action(51, tt_end) + 32 == 120);
	TEST_CHECK(table_action(52, tt_end) + 32 == 121);
	TEST_CHECK(table_action(53, tt_end) + 32 == 122);
	TEST_CHECK(table_action(54, tt_end) + 32 == 124);
}

///////////////////////// TABLE GOTO

void	test_goto_table(void)
{
// GO_TO table

	//ok

	TEST_CHECK(table_goto(0, nt_accept) == 1);

	//program

	TEST_CHECK(table_goto(0, nt_program) == 2);

	//and_or

	TEST_CHECK(table_goto(0, nt_and_or) == 3);
	TEST_CHECK(table_goto(14, nt_and_or) == 32);
	TEST_CHECK(table_goto(15, nt_and_or) == 33);

	//pipeline

	TEST_CHECK(table_goto(0, nt_pipeline) == 4);
	TEST_CHECK(table_goto(14, nt_pipeline) == 4);
	TEST_CHECK(table_goto(15, nt_pipeline) == 4);
	TEST_CHECK(table_goto(21, nt_pipeline) == 42);
	TEST_CHECK(table_goto(22, nt_pipeline) == 43);

	//command

	TEST_CHECK(table_goto(0, nt_command) == 5);
	TEST_CHECK(table_goto(14, nt_command) == 5);
	TEST_CHECK(table_goto(15, nt_command) == 5);
	TEST_CHECK(table_goto(21, nt_command) == 5);
	TEST_CHECK(table_goto(22, nt_command) == 5);
	TEST_CHECK(table_goto(23, nt_command) == 44);

	//simple_command

	TEST_CHECK(table_goto(0, nt_simple_command) == 6);
	TEST_CHECK(table_goto(14, nt_simple_command) == 6);
	TEST_CHECK(table_goto(15, nt_simple_command) == 6);
	TEST_CHECK(table_goto(21, nt_simple_command) == 6);
	TEST_CHECK(table_goto(22, nt_simple_command) == 6);
	TEST_CHECK(table_goto(23, nt_simple_command) == 6);

	//compound_command

	TEST_CHECK(table_goto(0, nt_compound_command) == 7);
	TEST_CHECK(table_goto(14, nt_compound_command) == 7);
	TEST_CHECK(table_goto(15, nt_compound_command) == 7);
	TEST_CHECK(table_goto(21, nt_compound_command) == 7);
	TEST_CHECK(table_goto(22, nt_compound_command) == 7);
	TEST_CHECK(table_goto(23, nt_compound_command) == 7);

	//redirect_list

	TEST_CHECK(table_goto(7, nt_redirect_list) == 24);

	//brace_group

	TEST_CHECK(table_goto(0, nt_brace_group) == 10);
	TEST_CHECK(table_goto(14, nt_brace_group) == 10);
	TEST_CHECK(table_goto(15, nt_brace_group) == 10);
	TEST_CHECK(table_goto(21, nt_brace_group) == 10);
	TEST_CHECK(table_goto(22, nt_brace_group) == 10);
	TEST_CHECK(table_goto(23, nt_brace_group) == 10);

	//subshell

	TEST_CHECK(table_goto(0, nt_subshell) == 11);
	TEST_CHECK(table_goto(14, nt_subshell) == 11);
	TEST_CHECK(table_goto(15, nt_subshell) == 11);
	TEST_CHECK(table_goto(21, nt_subshell) == 11);
	TEST_CHECK(table_goto(22, nt_subshell) == 11);
	TEST_CHECK(table_goto(23, nt_subshell) == 11);

	//cmd_prefix

	TEST_CHECK(table_goto(0, nt_cmd_prefix) == 8);
	TEST_CHECK(table_goto(14, nt_cmd_prefix) == 8);
	TEST_CHECK(table_goto(15, nt_cmd_prefix) == 8);
	TEST_CHECK(table_goto(21, nt_cmd_prefix) == 8);
	TEST_CHECK(table_goto(22, nt_cmd_prefix) == 8);
	TEST_CHECK(table_goto(23, nt_cmd_prefix) == 8);

	//cmd_sufix

	TEST_CHECK(table_goto(9, nt_cmd_suffix) == 29);
	TEST_CHECK(table_goto(26, nt_cmd_suffix) == 46);

	//io_redirect

	TEST_CHECK(table_goto(0, nt_io_redirect) == 12);
	TEST_CHECK(table_goto(7, nt_io_redirect) == 25);
	TEST_CHECK(table_goto(8, nt_io_redirect) == 27);
	TEST_CHECK(table_goto(9, nt_io_redirect) == 30);
	TEST_CHECK(table_goto(14, nt_io_redirect) == 12);
	TEST_CHECK(table_goto(15, nt_io_redirect) == 12);
	TEST_CHECK(table_goto(21, nt_io_redirect) == 12);
	TEST_CHECK(table_goto(22, nt_io_redirect) == 12);
	TEST_CHECK(table_goto(23, nt_io_redirect) == 12);
	TEST_CHECK(table_goto(24, nt_io_redirect) == 45);	
	TEST_CHECK(table_goto(26, nt_io_redirect) == 30);
	TEST_CHECK(table_goto(29, nt_io_redirect) == 47);
	TEST_CHECK(table_goto(46, nt_io_redirect) == 47);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                 TEST GRAMMAR UTILS
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

void	test_word1(void)
{
	t_word_list *out = NULL;
	t_token *t1 = new_token(); set_token("a", 0, 1, tt_word, t1);
	t_word_list *word1 = make_word(t1);
	TEST_CHECK(strcmp(word1->word, "a") == 0);
	t_token *t2 = new_token(); set_token("b", 0, 1, tt_word, t2);
	t_word_list *word2 = make_word(t2);
	TEST_CHECK(strcmp(word2->word, "b") == 0);
	t_token *t3 = new_token(); set_token("c", 0, 1, tt_word, t3);
	t_word_list *word3 = make_word(t3);
	TEST_CHECK(strcmp(word3->word, "c") == 0);
	t_token *t4 = new_token(); set_token("d", 0, 1, tt_word, t4);
	t_word_list *word4 = make_word(t4);
	TEST_CHECK(strcmp(word4->word, "d") == 0);
	join_word(&word1, word2);
	join_word(&word1, word3);
	join_word(&word1, word4);
	TEST_CHECK(strcmp(word1->word, "a") == 0);
	TEST_CHECK(strcmp(word1->next->word, "b") == 0);
	TEST_CHECK(strcmp(word1->next->next->word, "c") == 0);
	TEST_CHECK(strcmp(word1->next->next->next->word, "d") == 0);
	TEST_CHECK(word1->next->next->next->next == NULL);
	clean_word(&word1);
}

void	test_word2(void)
{
	t_word_list *word1 = NULL;
	t_token *t = new_token(); set_token("a", 0, 1, tt_word, t);
	t_word_list *word2 = make_word(t);
	TEST_CHECK(strcmp(word2->word, "a") == 0);
	join_word(&word1, word2);
	TEST_CHECK(strcmp(word1->word, "a") == 0);
	TEST_CHECK(word1->next == NULL);
	clean_word(&word1);
}

void	test_word3(void)
{
	t_word_list *word2 = NULL;
	t_token *t = new_token(); set_token("a", 0, 1, tt_word, t);
	t_word_list *word1 = make_word(t);
	TEST_CHECK(strcmp(word1->word, "a") == 0);
	join_word(&word1, word2);
	TEST_CHECK(strcmp(word1->word, "a") == 0);
	TEST_CHECK(word1->next == NULL);
	clean_word(&word1);
}

void	test_number(void)
{
	t_token *t1 = new_token(); set_token("10", 0, 2, tt_io_number, t1);
	TEST_CHECK(make_number(t1) == 10);
	t_token *t2 = new_token(); set_token("0", 0, 1, tt_io_number, t2);
	TEST_CHECK(make_number(t2) == 0);
	t_token *t3 = new_token(); set_token("1", 0, 1, tt_io_number, t3);
	TEST_CHECK(make_number(t3) == 1);
}

void	test_redir_utils(void)
{
	t_redirect	*r1 = ft_malloc(sizeof(t_redirect));
	r1->flag = 1;
	r1->next = NULL;
	t_redirect	*r2 = ft_malloc(sizeof(t_redirect));
	r2->flag = 2;
	r2->next = NULL;
	t_redirect	*r3 = ft_malloc(sizeof(t_redirect));
	r3->flag = 3;
	r3->next = NULL;
	join_redir(&r1, r2);
	join_redir(&r1, r3);
	TEST_CHECK(r1->flag == 1);
	TEST_CHECK(r1->next->flag == 2);
	TEST_CHECK(r1->next->next->flag == 3);
	clean_redirection(&r1);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                 TEST GRAMMAR REDIRECTION
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

void	test_redir1(void)
{
	char		*input = strdup("<file");
	t_dlst 		*lex = NULL;
	t_token		*t;

	t = new_token(); set_token(input, 0, 1, tt_less, t); ft_dlstaddb(&lex, ft_dlstnew(t));
	t = new_token(); set_token(input, 1, 5, tt_word, t); ft_dlstaddb(&lex, ft_dlstnew(t));
	t = new_token(); set_token(input, 5, 5, tt_end, t); ft_dlstaddb(&lex, ft_dlstnew(t));
	syntax(&lex);
	// token
	TEST_CHECK(((t_token *)(lex->data))->flag == tt_end);
	TEST_CHECK(lex->next == NULL);
	TEST_CHECK(lex->prev != NULL);
	//command
	t_command	*out = lex->prev->data;
	TEST_CHECK(out->type == cmd_simple);
	TEST_CHECK(out->value.simple->redirects->source.fd == 1);
	TEST_CHECK(strcmp(out->value.simple->redirects->dest.filename, "file") == 0);
	TEST_CHECK(out->value.simple->redirects->rflags == 0);
	TEST_CHECK(out->value.simple->redirects->flag == 0);
	TEST_CHECK(out->value.simple->redirects->option == r_input_direction);
	TEST_CHECK(out->value.simple->redirects->mode_bits == O_TRUNC | O_WRONLY | O_CREAT);
	TEST_CHECK(out->value.simple->redirects->next == NULL);
	free(input);
}

void	test_redir2(void)
{
	char		*input = strdup(">file");
	t_dlst 		*lex = NULL;
	t_token		*t;

	
	t = new_token(); set_token(input, 0, 1, tt_less, t); ft_dlstaddb(&lex, ft_dlstnew(t));
	t = new_token(); set_token(input, 1, 5, tt_word, t); ft_dlstaddb(&lex, ft_dlstnew(t));
	t = new_token(); set_token(input, 5, 5, tt_end, t); ft_dlstaddb(&lex, ft_dlstnew(t));
	syntax(&lex);
	// token
	TEST_CHECK(((t_token *)(lex->data))->flag == tt_end);
	TEST_CHECK(lex->next == NULL);
	TEST_CHECK(lex->prev != NULL);
	//command
	t_command	*out = lex->prev->data;
	TEST_CHECK(out->type == cmd_simple);
	TEST_CHECK(out->value.simple->redirects->source.fd == 1);
	TEST_CHECK(strcmp(out->value.simple->redirects->dest.filename, "file") == 0);
	TEST_CHECK(out->value.simple->redirects->rflags == 0);
	TEST_CHECK(out->value.simple->redirects->flag == 0);
	TEST_CHECK(out->value.simple->redirects->option == r_input_direction);
	TEST_CHECK(out->value.simple->redirects->mode_bits == O_TRUNC | O_WRONLY | O_CREAT);
	TEST_CHECK(out->value.simple->redirects->next == NULL);
	free(input);
}

void	test_redir3(void)
{
	char		*input = strdup(">>file");
	t_dlst 		*lex = NULL;
	t_token		*t;

	
	t = new_token(); set_token(input, 0, 2, tt_dgreat, t); ft_dlstaddb(&lex, ft_dlstnew(t));
	t = new_token(); set_token(input, 2, 6, tt_word, t); ft_dlstaddb(&lex, ft_dlstnew(t));
	t = new_token(); set_token(input, 6, 6, tt_end, t); ft_dlstaddb(&lex, ft_dlstnew(t));
	syntax(&lex);
	// token
	TEST_CHECK(((t_token *)(lex->data))->flag == tt_end);
	TEST_CHECK(lex->next == NULL);
	TEST_CHECK(lex->prev != NULL);
	//command
	t_command	*out = lex->prev->data;
	TEST_CHECK(out->type == cmd_simple);
	TEST_CHECK(out->value.simple->redirects->source.fd == 0);
	TEST_CHECK(strcmp(out->value.simple->redirects->dest.filename, "file") == 0);
	TEST_CHECK(out->value.simple->redirects->rflags == 0);
	TEST_CHECK(out->value.simple->redirects->flag == 0);
	TEST_CHECK(out->value.simple->redirects->option == r_appending_to);
	TEST_CHECK(out->value.simple->redirects->mode_bits == (O_APPEND|O_WRONLY|O_CREAT));
	TEST_CHECK(out->value.simple->redirects->next == NULL);
	free(input);
}

void	test_redir4(void)
{
		char		*input = strdup("10<file");
	t_dlst 		*lex = NULL;
	t_token		*t;

	t = new_token(); set_token(input, 0, 2, tt_io_number, t); ft_dlstaddb(&lex, ft_dlstnew(t));
	t = new_token(); set_token(input, 2, 3, tt_less, t); ft_dlstaddb(&lex, ft_dlstnew(t));
	t = new_token(); set_token(input, 3, 7, tt_word, t); ft_dlstaddb(&lex, ft_dlstnew(t));
	t = new_token(); set_token(input, 7, 7, tt_end, t); ft_dlstaddb(&lex, ft_dlstnew(t));
	syntax(&lex);
	// token
	TEST_CHECK(((t_token *)(lex->data))->flag == tt_end);
	TEST_CHECK(lex->next == NULL);
	TEST_CHECK(lex->prev != NULL);
	//command
	t_command	*out = lex->prev->data;
	TEST_CHECK(out->type == cmd_simple);
	TEST_CHECK(out->value.simple->redirects->source.fd == 10);
	TEST_CHECK(strcmp(out->value.simple->redirects->dest.filename, "file") == 0);
	TEST_CHECK(out->value.simple->redirects->rflags == 0);
	TEST_CHECK(out->value.simple->redirects->flag == 0);
	TEST_CHECK(out->value.simple->redirects->option == r_input_direction);
	TEST_CHECK(out->value.simple->redirects->mode_bits == O_RDONLY);
	TEST_CHECK(out->value.simple->redirects->next == NULL);
	free(input);
}

void	test_redir5(void)
{
	char		*input = strdup("10>file");
	t_dlst 		*lex = NULL;
	t_token		*t;

	t = new_token(); set_token(input, 0, 2, tt_io_number, t); ft_dlstaddb(&lex, ft_dlstnew(t));
	t = new_token(); set_token(input, 2, 3, tt_great, t); ft_dlstaddb(&lex, ft_dlstnew(t));
	t = new_token(); set_token(input, 3, 7, tt_word, t); ft_dlstaddb(&lex, ft_dlstnew(t));
	t = new_token(); set_token(input, 7, 7, tt_end, t); ft_dlstaddb(&lex, ft_dlstnew(t));
	syntax(&lex);
	// token
	TEST_CHECK(((t_token *)(lex->data))->flag == tt_end);
	TEST_CHECK(lex->next == NULL);
	TEST_CHECK(lex->prev != NULL);
	//command
	t_command	*out = lex->prev->data;
	TEST_CHECK(out->type == cmd_simple);
	TEST_CHECK(out->value.simple->redirects->source.fd == 10);
	TEST_CHECK(strcmp(out->value.simple->redirects->dest.filename, "file") == 0);
	TEST_CHECK(out->value.simple->redirects->rflags == 0);
	TEST_CHECK(out->value.simple->redirects->flag == 0);
	TEST_CHECK(out->value.simple->redirects->option == r_output_direction);
	TEST_CHECK(out->value.simple->redirects->mode_bits == (O_TRUNC|O_WRONLY|O_CREAT));
	TEST_CHECK(out->value.simple->redirects->next == NULL);
	free(input);
}

 
void	test_redir6(void)
{
	char		*input = strdup("10>>file");
	t_dlst 		*lex = NULL;
	t_token		*t;

	t = new_token(); set_token(input, 0, 2, tt_io_number, t); ft_dlstaddb(&lex, ft_dlstnew(t));
	t = new_token(); set_token(input, 2, 4, tt_dgreat, t); ft_dlstaddb(&lex, ft_dlstnew(t));
	t = new_token(); set_token(input, 4, 8, tt_word, t); ft_dlstaddb(&lex, ft_dlstnew(t));
	t = new_token(); set_token(input, 8, 8, tt_end, t); ft_dlstaddb(&lex, ft_dlstnew(t));
	syntax(&lex);
	// token
	TEST_CHECK(((t_token *)(lex->data))->flag == tt_end);
	TEST_CHECK(lex->next == NULL);
	TEST_CHECK(lex->prev != NULL);
	//command
	t_command	*out = lex->prev->data;
	TEST_CHECK(out->type == cmd_simple);
	TEST_CHECK(out->value.simple->redirects->source.fd == 10);
	TEST_CHECK(strcmp(out->value.simple->redirects->dest.filename, "file") == 0);
	TEST_CHECK(out->value.simple->redirects->rflags == 0);
	TEST_CHECK(out->value.simple->redirects->flag == 0);
	TEST_CHECK(out->value.simple->redirects->option == r_appending_to);
	TEST_CHECK(out->value.simple->redirects->mode_bits == (O_APPEND|O_WRONLY|O_CREAT));
	TEST_CHECK(out->value.simple->redirects->next == NULL);
	free(input);
}

void	test_redir7(void)
{
	char		*input = strdup("<<file");
	t_dlst 		*lex = NULL;
	t_token		*t;

	t = new_token(); set_token(input, 0, 2, tt_dless, t); ft_dlstaddb(&lex, ft_dlstnew(t));
	t = new_token(); set_token(input, 2, 6, tt_word, t); ft_dlstaddb(&lex, ft_dlstnew(t));
	t = new_token(); set_token(input, 6, 6, tt_end, t); ft_dlstaddb(&lex, ft_dlstnew(t));
	syntax(&lex);
	// token
	TEST_CHECK(((t_token *)(lex->data))->flag == tt_end);
	TEST_CHECK(lex->next == NULL);
	TEST_CHECK(lex->prev != NULL);
	//command
	t_command	*out = lex->prev->data;
	TEST_CHECK(out->type == cmd_simple);
	TEST_CHECK(out->value.simple->redirects->source.fd == 0);
	TEST_CHECK(strcmp(out->value.simple->redirects->dest.filename, "file") == 0);
	TEST_CHECK(out->value.simple->redirects->rflags == 0);
	TEST_CHECK(out->value.simple->redirects->flag == 0);
	TEST_CHECK(out->value.simple->redirects->option == r_reading_until);
	TEST_CHECK(out->value.simple->redirects->mode_bits == 0);
	TEST_CHECK(out->value.simple->redirects->next == NULL);
	free(input);
}


void	test_redir8(void)
{
	char		*input = strdup("10<<file");
	t_dlst 		*lex = NULL;
	t_token		*t;

	t = new_token(); set_token(input, 0, 2, tt_io_number, t); ft_dlstaddb(&lex, ft_dlstnew(t));
	t = new_token(); set_token(input, 2, 4, tt_dless, t); ft_dlstaddb(&lex, ft_dlstnew(t));
	t = new_token(); set_token(input, 4, 8, tt_word, t); ft_dlstaddb(&lex, ft_dlstnew(t));
	t = new_token(); set_token(input, 8, 8, tt_end, t); ft_dlstaddb(&lex, ft_dlstnew(t));
	syntax(&lex);
	// token
	TEST_CHECK(((t_token *)(lex->data))->flag == tt_end);
	TEST_CHECK(lex->next == NULL);
	TEST_CHECK(lex->prev != NULL);
	//command
	t_command	*out = lex->prev->data;
	TEST_CHECK(out->type == cmd_simple);
	TEST_CHECK(out->value.simple->redirects->source.fd == 10);
	TEST_CHECK(strcmp(out->value.simple->redirects->dest.filename, "file") == 0);
	TEST_CHECK(out->value.simple->redirects->rflags == 0);
	TEST_CHECK(out->value.simple->redirects->flag == 0);
	TEST_CHECK(out->value.simple->redirects->option == r_reading_until);
	TEST_CHECK(out->value.simple->redirects->mode_bits == 0);
	TEST_CHECK(out->value.simple->redirects->next == NULL);
	free(input);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                 TEST GRAMMAR SUFFIX
//
//////////////////////////////////////////////////////////////////////////////////////////////////////


void	test_suffix1(void)
{
	char		*input = strdup("word1 >word2");
	t_dlst		*lex = NULL;
	t_token		*t;

	t = new_token(); set_token(input, 0, 5, tt_word, t); ft_dlstaddb(&lex, ft_dlstnew(t));
	t = new_token(); set_token(input, 6, 7, tt_great,t); ft_dlstaddb(&lex, ft_dlstnew(t));
	t = new_token(); set_token(input, 7, 12, tt_word,t); ft_dlstaddb(&lex, ft_dlstnew(t));
	t = new_token(); set_token(input, 12, 12,tt_end, t); ft_dlstaddb(&lex, ft_dlstnew(t));
	syntax(&lex);
	// token
	TEST_CHECK(((t_token *)(lex->data))->flag == tt_end);
	TEST_CHECK(lex->next == NULL);
	TEST_CHECK(lex->prev != NULL);
	//command
	t_command	*out = lex->prev->data;
	TEST_CHECK(out->type == cmd_simple);
	TEST_CHECK(strcmp(out->value.simple->words->word, "word1") == 0);
	TEST_CHECK(strcmp(out->value.simple->redirects->dest.filename, "word2") == 0);
	free(input);
}

void	test_suffix2(void)
{
	char		*input = strdup("word1 >word2 >word3");
	t_dlst 		*lex = NULL;
	t_token		*t;

	t = new_token(); set_token(input, 0, 5, tt_word,  t); ft_dlstaddb(&lex, ft_dlstnew(t));
	t = new_token(); set_token(input, 6, 7, tt_great, t); ft_dlstaddb(&lex, ft_dlstnew(t));
	t = new_token(); set_token(strdup("word2"), 0, 5, tt_word, t); ft_dlstaddb(&lex, ft_dlstnew(t));
	t = new_token(); set_token(input, 13, 14, tt_great, t); ft_dlstaddb(&lex, ft_dlstnew(t));
	t = new_token(); set_token(input, 14, 19, tt_word, t); ft_dlstaddb(&lex, ft_dlstnew(t));
	t = new_token(); set_token(input, 19, 19, tt_end, t); ft_dlstaddb(&lex, ft_dlstnew(t));
	syntax(&lex);
	// token
	TEST_CHECK(((t_token *)(lex->data))->flag == tt_end);
	TEST_CHECK(lex->next == NULL);
	TEST_CHECK(lex->prev != NULL);
	//command
	t_command	*out = lex->prev->data;
	TEST_CHECK(strcmp(out->value.simple->words->word, "word1") == 0);
	TEST_CHECK(out->value.simple->words->next == NULL);
	TEST_CHECK(strcmp(out->value.simple->redirects->dest.filename, "word2") == 0);
	TEST_CHECK(strcmp(out->value.simple->redirects->next->dest.filename, "word3") == 0);
	TEST_CHECK(out->value.simple->redirects->next->next == NULL);
	TEST_CHECK(out->type == cmd_simple);
	free(input);
}

void	test_suffix3(void)
{
	char		*input = strdup("word1 word2");
	t_dlst 		*lex = NULL;
	t_token		*t;
	t = new_token(); set_token(input, 0, 5, tt_word,  t); ft_dlstaddb(&lex, ft_dlstnew(t));
	t = new_token(); set_token(input, 6, 11, tt_word,  t); ft_dlstaddb(&lex, ft_dlstnew(t));
	t = new_token(); set_token(input, 11, 11, tt_end,  t); ft_dlstaddb(&lex, ft_dlstnew(t));
	syntax(&lex);
	// token
	TEST_CHECK(((t_token *)(lex->data))->flag == tt_end);
	TEST_CHECK(lex->next == NULL);
	TEST_CHECK(lex->prev != NULL);
	//command
	t_command	*out = lex->prev->data;
	TEST_CHECK(out->type == cmd_simple);
	TEST_CHECK(strcmp(out->value.simple->words->word, "word1") == 0);
	TEST_CHECK(strcmp(out->value.simple->words->next->word, "word2") == 0);
	TEST_CHECK(out->value.simple->redirects == NULL);
	free(input);
}

void	test_suffix4(void)
{
	char		*input = strdup("word1 word2 word3");
	t_dlst 		*lex = NULL;
	t_token		*t;
	t = new_token(); set_token(input, 0, 5, tt_word,  t); ft_dlstaddb(&lex, ft_dlstnew(t));
	t = new_token(); set_token(strdup("word2"), 0,5 , tt_word,  t); ft_dlstaddb(&lex, ft_dlstnew(t));
	t = new_token(); set_token(input, 12, 17, tt_word,  t); ft_dlstaddb(&lex, ft_dlstnew(t));
	t = new_token(); set_token(input, 17, 17, tt_end,  t); ft_dlstaddb(&lex, ft_dlstnew(t));
	syntax(&lex);
	// token
	TEST_CHECK(((t_token *)(lex->data))->flag == tt_end);
	TEST_CHECK(lex->next == NULL);
	TEST_CHECK(lex->prev != NULL);
	//command
	t_command	*out = lex->prev->data;
	TEST_CHECK(out->type == cmd_simple);
	TEST_CHECK(strcmp(out->value.simple->words->word, "word1") == 0);
	TEST_CHECK(strcmp(out->value.simple->words->next->word, "word2") == 0);
	TEST_CHECK(strcmp(out->value.simple->words->next->next->word, "word3") == 0);
	TEST_CHECK(out->value.simple->redirects == NULL);
	free(input);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                 TEST GRAMMAR PREFIX
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

void	test_prefix1(void)
{
	char		*input = strdup(">word1");
	t_dlst 		*lex = NULL;
	t_token		*t;
	t = new_token(); set_token(input, 0, 1, tt_great,  t); ft_dlstaddb(&lex, ft_dlstnew(t));
	t = new_token(); set_token(input, 1, 6, tt_word,  t); ft_dlstaddb(&lex, ft_dlstnew(t));
	t = new_token(); set_token(input, 6, 6, tt_end,  t); ft_dlstaddb(&lex, ft_dlstnew(t));
	syntax(&lex);
	// token
	TEST_CHECK(((t_token *)(lex->data))->flag == tt_end);
	TEST_CHECK(lex->next == NULL);
	TEST_CHECK(lex->prev != NULL);
	// command
	t_command	*out = lex->prev->data;
	TEST_CHECK(strcmp(out->value.simple->redirects->dest.filename, "word1") == 0);
	TEST_CHECK(out->value.simple->redirects->next == NULL);
	free(input);
}

void	test_prefix2(void)
{
	char		*input = strdup(">word1 >word2");
	t_dlst 		*lex = NULL;
	t_token		*t;
	t = new_token(); set_token(input, 0, 1, tt_great,  t); ft_dlstaddb(&lex, ft_dlstnew(t));
	t = new_token(); set_token(input, 1, 5, tt_word,  t); ft_dlstaddb(&lex, ft_dlstnew(t));
	t = new_token(); set_token(input, 7, 8, tt_great,  t); ft_dlstaddb(&lex, ft_dlstnew(t));
	t = new_token(); set_token(input, 8, 13, tt_word,  t); ft_dlstaddb(&lex, ft_dlstnew(t));
	t = new_token(); set_token(input, 14, 14, tt_end,  t); ft_dlstaddb(&lex, ft_dlstnew(t));
	syntax(&lex);
	// token
	TEST_CHECK(((t_token *)(lex->data))->flag == tt_end);
	TEST_CHECK(lex->next == NULL);
	TEST_CHECK(lex->prev != NULL);
	t_command	*out = lex->prev->data;
	TEST_CHECK(strcmp(out->value.simple->redirects->dest.filename, "word1") == 0);
	TEST_CHECK(strcmp(out->value.simple->redirects->next->dest.filename, "word2") == 0);
	TEST_CHECK(out->value.simple->redirects->next->next == NULL);
	free(input);
}

//void	test_prefix3(void)
//{
//	TEST_CHECK(1 == 0);
//}
//
//void	test_prefix4(void)
//{
//	TEST_CHECK(1 == 0);
//}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                 TEST GRAMMAR SIMPLE
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

void	test_simple1(void)
{
	t_dlst 		*lex = NULL;
	t_token		*t;

	t = new_token(); set_token(">", 0, 1, tt_great, t); ft_dlstaddb(&lex, ft_dlstnew(t));
	t = new_token(); set_token("word1", 0, 5, tt_word, t); ft_dlstaddb(&lex, ft_dlstnew(t));
	t = new_token(); set_token("word2", 0, 5, tt_word, t); ft_dlstaddb(&lex, ft_dlstnew(t));
	t = new_token(); set_token("word3", 0, 5, tt_word, t); ft_dlstaddb(&lex, ft_dlstnew(t));
	t = new_token(); set_token("", 0, 0, tt_end, t); ft_dlstaddb(&lex, ft_dlstnew(t));
	syntax(&lex);
	// token
	TEST_CHECK(((t_token *)(lex->data))->flag == tt_end);
	TEST_CHECK(lex->next == NULL);
	TEST_CHECK(lex->prev != NULL);
	//command
	t_command	*out = lex->prev->data;
	TEST_CHECK(out->type == cmd_simple);
	TEST_CHECK(out->value.simple->redirects->source.fd == 1);
	TEST_CHECK(strcmp(out->value.simple->redirects->dest.filename, "word1") == 0);
	TEST_CHECK(strcmp(out->value.simple->words->word, "word2") == 0);
	TEST_CHECK(strcmp(out->value.simple->words->next->word, "word3") == 0);
	TEST_CHECK(out->value.simple->redirects->next == NULL);
}


void	test_simple2(void)
{
	char		*input = strdup("word1 >word2");
	t_dlst		*lex = NULL;
	t_token		*t;

	t = new_token(); set_token(input, 0, 5, tt_word, t); ft_dlstaddb(&lex, ft_dlstnew(t));
	t = new_token(); set_token(input, 7, 7, tt_great,t); ft_dlstaddb(&lex, ft_dlstnew(t));
	t = new_token(); set_token(input, 7, 12, tt_word,t); ft_dlstaddb(&lex, ft_dlstnew(t));
	t = new_token(); set_token(input, 12, 12,tt_end, t); ft_dlstaddb(&lex, ft_dlstnew(t));
	syntax(&lex);
	// token
	TEST_CHECK(((t_token *)(lex->data))->flag == tt_end);
	TEST_CHECK(lex->next == NULL);
	TEST_CHECK(lex->prev != NULL);
	//command
	t_command	*out = lex->prev->data;
	TEST_CHECK(out->type == cmd_simple);
	TEST_CHECK(strcmp(out->value.simple->words->word, "word1") == 0);
	TEST_CHECK(strcmp(out->value.simple->redirects->dest.filename, "word2") == 0);
	free(input);
}

void	test_simple3(void)
{
	char		*input = strdup(">word1");
	t_dlst 		*lex = NULL;
	t_token		*t;

	t = new_token(); set_token(input, 0, 1, tt_less, t); ft_dlstaddb(&lex, ft_dlstnew(t));
	t = new_token(); set_token(input, 1, 5, tt_word, t); ft_dlstaddb(&lex, ft_dlstnew(t));
	t = new_token(); set_token(input, 5, 5, tt_end, t); ft_dlstaddb(&lex, ft_dlstnew(t));
	syntax(&lex);
	// token
	TEST_CHECK(((t_token *)(lex->data))->flag == tt_end);
	TEST_CHECK(lex->next == NULL);
	TEST_CHECK(lex->prev != NULL);
	//command
	t_command	*out = lex->prev->data;
	TEST_CHECK(out->type == cmd_simple);
	TEST_CHECK(out->value.simple->redirects->source.fd == 1);
	TEST_CHECK(strcmp(out->value.simple->redirects->dest.filename, "word1") == 0);
	TEST_CHECK(out->value.simple->words == NULL);
	TEST_CHECK(out->value.simple->redirects->next == NULL);
	free(input);
}

void	test_simple4(void)
{
	char		*input = strdup("word1 word2");
	t_dlst 		*lex = NULL;
	t_token		*t;
	t = new_token(); set_token(input, 0, 5, tt_word,  t); ft_dlstaddb(&lex, ft_dlstnew(t));
	t = new_token(); set_token(input, 6, 11, tt_word,  t); ft_dlstaddb(&lex, ft_dlstnew(t));
	t = new_token(); set_token(input, 11, 11, tt_end,  t); ft_dlstaddb(&lex, ft_dlstnew(t));
	syntax(&lex);
	// token
	TEST_CHECK(((t_token *)(lex->data))->flag == tt_end);
	TEST_CHECK(lex->next == NULL);
	TEST_CHECK(lex->prev != NULL);
	//command
	t_command	*out = lex->prev->data;
	TEST_CHECK(out->type == cmd_simple);
	TEST_CHECK(strcmp(out->value.simple->words->word, "word1") == 0);
	TEST_CHECK(strcmp(out->value.simple->words->next->word, "word2") == 0);
	TEST_CHECK(out->value.simple->words->next->next == NULL);
	TEST_CHECK(out->value.simple->redirects == NULL);
	free(input);
}

void	test_simple5(void)
{
	char		*input = strdup("word1");
	t_dlst 		*lex = NULL;
	t_token		*t;
	t = new_token(); set_token(input, 0, 5, tt_word,  t); ft_dlstaddb(&lex, ft_dlstnew(t));
	t = new_token(); set_token(input, 5, 5, tt_end,  t); ft_dlstaddb(&lex, ft_dlstnew(t));
	syntax(&lex);
	// token
	TEST_CHECK(((t_token *)(lex->data))->flag == tt_end);
	TEST_CHECK(lex->next == NULL);
	TEST_CHECK(lex->prev != NULL);
	//command
	t_command	*out = lex->prev->data;
	TEST_CHECK(out->type == cmd_simple);
	TEST_CHECK(strcmp(out->value.simple->words->word, "word1") == 0);
	TEST_CHECK(out->value.simple->words->next == NULL);
	TEST_CHECK(out->value.simple->redirects == NULL);
	free(input);
}


//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                 TEST GRAMMAR SUBSHELL
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

void	test_subshell1(void)
{ // ( cmd )
	char		*input = strdup("( word1 )");
	t_dlst 		*lex = NULL;
	t_token		*t;
	t = new_token(); set_token("(", 0, 1, tt_lbrace,  t); ft_dlstaddb(&lex, ft_dlstnew(t));
	t = new_token(); set_token("word1", 0, 5, tt_word,  t); ft_dlstaddb(&lex, ft_dlstnew(t));
	t = new_token(); set_token(")", 0, 1, tt_rbrace,  t); ft_dlstaddb(&lex, ft_dlstnew(t));
	t = new_token(); set_token("" , 0, 0, tt_end,  t); ft_dlstaddb(&lex, ft_dlstnew(t));
	syntax(&lex);
	// token
	TEST_CHECK(((t_token *)(lex->data))->flag == tt_end);
	TEST_CHECK(lex->next == NULL);
	TEST_CHECK(lex->prev != NULL);
	//command
	t_command	*out = lex->prev->data;
	TEST_CHECK(out->type == cmd_subshell);
	//TEST_CHECK(out->value.subshell->command->type == cmd_simple);
	//TEST_CHECK(strcmp(out->value.->, "word1") == 0);
}

void	test_subshell2(void)
{
	char		*input = strdup("( word1 ) >redir1");
	t_dlst 		*lex = NULL;
	t_token		*t;
	TEST_CHECK(1 == 0);
}

void	test_subshell3(void)
{
	char		*input = strdup("( word1 ) >redir1 >redir2");
	t_dlst 		*lex = NULL;
	t_token		*t;
	TEST_CHECK(1 == 0);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                 TEST GRAMMAR GROUP
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

void	test_group1(void)
{
	char		*input = strdup("{ word1 }");
	t_dlst 		*lex = NULL;
	t_token		*t;
	TEST_CHECK(1 == 0);
}

void	test_group2(void)
{
	char		*input = strdup("{ word1 } >redir1");
	t_dlst 		*lex = NULL;
	t_token		*t;
	TEST_CHECK(1 == 0);
}

void	test_group3(void)
{
	char		*input = strdup("{ word1 } >redir1 >redir2");
	t_dlst 		*lex = NULL;
	t_token		*t;
	TEST_CHECK(1 == 0);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                 TEST GRAMMAR PIPELINE
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

void	test_pipeline1(void)
{
	char		*input = strdup("word1 | word2");
	t_dlst 		*lex = NULL;
	t_token		*t;
	TEST_CHECK(1 == 0);
}

void	test_pipeline2(void)
{
	char		*input = strdup("word1 | word2 | word3");
	t_dlst 		*lex = NULL;
	t_token		*t;
	TEST_CHECK(1 == 0);
}

void	test_pipeline3(void)
{
	char		*input = strdup("word1 > redir1 | word2 > redir2 | word3 > redir3");
	t_dlst 		*lex = NULL;
	t_token		*t;
	TEST_CHECK(1 == 0);
}


//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                 TEST GRAMMAR AND OR
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

void	test_andor1(void)
{
	char		*input = strdup("word1 || word2");
	t_dlst 		*lex = NULL;
	t_token		*t;
	TEST_CHECK(1 == 0);
}

void	test_andor2(void)
{
	char		*input = strdup("word1 && word2");
	t_dlst 		*lex = NULL;
	t_token		*t;
	TEST_CHECK(1 == 0);
}

void	test_andor3(void)
{
	char		*input = strdup("word1 || word2 > redir2 && word3 > redir3");
	t_dlst 		*lex = NULL;
	t_token		*t;
	TEST_CHECK(1 == 0);
}


void	test_andor4(void)
{
	char		*input = strdup("word1 || word2 > redir2 | word3 > redir3");
	t_dlst 		*lex = NULL;
	t_token		*t;
	TEST_CHECK(1 == 0);
}

void	test_andor5(void)
{
	char		*input = strdup("word1 && word2 > redir2 | word3 > redir3");
	t_dlst 		*lex = NULL;
	t_token		*t;
	TEST_CHECK(1 == 0);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                 RUN TEST
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

TEST_LIST = {
	{ "test tokens"      , test_simple_tokens},
	{ "test expansion"   , test_expansion    },
	{ "test single quote", test_singleq   },
	{ "test double quote", test_doubleq   },
	{ "test multi tokens", test_multitok  },
	{ "table action"     , test_action_table },
	{ "table go to"      , test_goto_table   },
	{ "word utils 1"     , test_word1        },
	{ "word utils 2"     , test_word2        },
	{ "word utils 3"     , test_word3        },
	{ "number utils"     , test_number       },
	{ "join redir"       , test_redir_utils  },
	{ "rule  redir 1"    , test_redir1       },
	{ "rule  redir 2"    , test_redir2       },
	{ "rule  redir 3"    , test_redir3       },
	{ "rule  redir 4"    , test_redir4       },
	{ "rule  redir 5"    , test_redir5       },
	{ "rule  redir 6"    , test_redir6       },
	{ "rule  redir 7"    , test_redir7       },
	{ "rule  redir 8"    , test_redir8       },
	{ "rule suffix 1"    , test_suffix1      },
	{ "rule suffix 2"    , test_suffix2      },
	{ "rule suffix 3"    , test_suffix3      },
	{ "rule suffix 4"    , test_suffix4      },
	{ "rule prefix 1"    , test_prefix1      },
	{ "rule prefix 2"    , test_prefix2      },
//	{ "rule prefix 3"    , test_prefix3      }, // NO SE ME OCURRE EJEMPLO
//	{ "rule prefix 4"    , test_prefix4      }, // NO SE ME OCURRE EJEMPLO
	{ "rule simple 1"    , test_simple1      },
	{ "rule simple 2"    , test_simple2      },
	{ "rule simple 3"    , test_simple3      },
	{ "rule simple 4"    , test_simple4      },
	{ "rule simple 5"    , test_simple5      },
//	{ "rule subshell1"   , test_subshell1    }, // IMPLEMENTACION OPCIONAL 
//	{ "rule subshell2"   , test_subshell2    }, // IMPLEMENTACION OPCIONAL 
//	{ "rule subshell3"   , test_subshell3    }, // IMPLEMENTACION OPCIONAL 
//	{ "rule group1"      , test_group1       }, // IMPLEMENTACION OPCIONAL 
//	{ "rule group2"      , test_group2       }, // IMPLEMENTACION OPCIONAL 
//	{ "rule group3"      , test_group3       }, // IMPLEMENTACION OPCIONAL 
	{ "rule pipeline1"   , test_pipeline1    },
	{ "rule pipeline2"   , test_pipeline2    },
	{ "rule pipeline3"   , test_pipeline3    },
	{ "rule andor1"      , test_andor1       },
	{ "rule andor2"      , test_andor2       },
	{ "rule andor3"      , test_andor3       },
	{ "rule andor4"      , test_andor4       },
	{ "rule andor5"      , test_andor5       },
	{ NULL, NULL }
};
