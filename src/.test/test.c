#include <time.h>
#include <stdlib.h>
#include "common.h"

int	compare_token(t_dlst *d, int type, int expand, char *str)
{
	t_token *t;
	t_dlst	*aux;

	if (!d)
		return (0);
	t = (t_token *)d->data;
	printf("\n");
	printf("1 %d %d\n",t->type, type);
	printf("2 %d %d\n",t->expand ,expand);
	printf("3 %s %s\n",t->str, str);
	if (t->type != type || t->expand != expand || strcmp(t->str, str) != 0)
			return (0);
	aux = d->next;
	ft_dlstdelone(d, free);
	d = aux;
	return (1);
}


void	test_new0(void)
{
	t_token *t = (t_token *) malloc(sizeof(t_token));
	t->type = 0; t->expand = 0; t->str = strdup("hola");
	t_dlst *d = ft_dlstnew(t);
	TEST_ASSERT(compare_token(d, 0, 0, "hola") == 1);
}

void	test_new1(void)
{
	t_token *t = (t_token *) malloc(sizeof(t_token));
	t->type = 0; t->expand = 0; t->str = strdup("hola");
	TEST_ASSERT(compare_token(ft_dlstnew(t), 1, 0, "hola") == 1);
}

TEST_LIST = {
        { "test 0", test_new0  },
        { "test 1", test_new1 },
        { NULL, NULL }
};