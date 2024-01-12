#include <time.h>
#include <stdlib.h>
#include "common.h"

# define GET_TOKS(str) tokenize(str)
//t_dlst	*lexer(char *read_line, t_dlst **head)
//void syntax(t_dlst *lex)

t_test_out	compare_token(t_dlst *d, int type, int expand, char *str)
{
	t_token *t;
	t_dlst	*aux;

	if (!d)
		return (0);
	t = (t_token *)d->data;
	if (t->type != type || t->expand != expand || strcmp(t->str, str) != 0)
			return (FAIL);
	aux = d->next;
	ft_dlstdelone(d, free);
	d = aux;
	return (PASS);
}

void	test_eof(void)
{
	// EOF, Ctrl + D
	t_dlst *d= GET_TOKS((char *)NULL);
	TEST_CHECK(compare_token(d, 0, 0, (char *)NULL) == PASS);
	ft_dlstclear(&d, free);
}

void	test_basic_tokens_operator(void)
{
	t_dlst *d = GET_TOKS("&&");
	TEST_CHECK(compare_token(d, AND_IF, 0, (char *)NULL) == PASS);
	ft_dlstclear(&d, free);
	d = GET_TOKS("|");
	TEST_CHECK(compare_token(d, PIPE, 0, (char *)NULL) == PASS);
	ft_dlstclear(&d, free);
	d = GET_TOKS("||");
	TEST_CHECK(compare_token(d, AND_OR, 0, (char *)NULL) == PASS);
	ft_dlstclear(&d, free);
	d = GET_TOKS("<<");
	TEST_CHECK(compare_token(d, DLESS, 0, (char *)NULL) == PASS);
	ft_dlstclear(&d, free);
	d = GET_TOKS(">>");
	TEST_CHECK(compare_token(d, DGREAT, 0, (char *)NULL) == PASS);
	ft_dlstclear(&d, free);
	d = GET_TOKS(">");
	TEST_CHECK(compare_token(d, GREAT, 0, (char *)NULL) == PASS);
	ft_dlstclear(&d, free);
	d = GET_TOKS("<");
	TEST_CHECK(compare_token(d, LESS, 0, (char *)NULL) == PASS);
	ft_dlstclear(&d, free);
	d = GET_TOKS("{");
	TEST_CHECK(compare_token(d, LBRACE, 0, (char *)NULL) == PASS);
	ft_dlstclear(&d, free);
	d = GET_TOKS("}");
	TEST_CHECK(compare_token(d, RBRACE, 0, (char *)NULL) == PASS);
	ft_dlstclear(&d, free);
	d = GET_TOKS("(");
	TEST_CHECK(compare_token(d, LBRAKET, 0, (char *)NULL) == PASS);
	ft_dlstclear(&d, free);
	d = GET_TOKS(")");
	TEST_CHECK(compare_token(d, RBRAKET, 0, (char *)NULL) == PASS);
	ft_dlstclear(&d, free);
	d = GET_TOKS("tok");
	TEST_CHECK(compare_token(d, TOKEN, 0, "tok") == PASS);
	ft_dlstclear(&d, free);
}

void	test_single_quotes(void)
{
}

void	test_double_quotes(void)
{
}


TEST_LIST = {
	{ "test EOF", test_eof},
	{ "test identify tokens operator", test_basic_tokens_operator},
	{ "test syntax", test_syntax},
	{ NULL, NULL }
};
