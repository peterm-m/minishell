#include <time.h>
#include "../ft_lst.h"
#include <stdlib.h>
#include "acutest.h"

void freeList(t_lst *head) {if (head) freeList((t_lst *)head->next); free(head);}

void test_new(void)
{
	t_lst * l =  ft_lstnew((void*)42);
	TEST_ASSERT(l->data == (void*)42);
	TEST_ASSERT(l->next == 0);
    free(l);
}

void test_size(void)
{
	t_lst * l =  NULL;
	TEST_ASSERT(ft_lstsize(l) == 0);
	ft_lstaddf(&l, ft_lstnew((void*)1));
	TEST_ASSERT(ft_lstsize(l) == 1);
	ft_lstaddf(&l, ft_lstnew((void*)2));
	TEST_ASSERT(ft_lstsize(l) == 2);
	freeList(l);
	return (0);
}

void test_lstaddf(void)
{
	t_lst *l =  NULL;
	ft_lstaddf(&l, ft_lstnew((void*)1));
	TEST_ASSERT(l->data == (void*)1);
	TEST_ASSERT(l->next == 0);
	ft_lstaddf(&l, ft_lstnew((void*)2));
	TEST_ASSERT(l->data == (void*)2);
	TEST_ASSERT(((t_lst *)l->next)->data == (void*)1);
	TEST_ASSERT(((t_lst *)l->next)->next == 0);
	freeList(l);
}

void test_lstaddb(void)
{
	t_lst * l =  NULL;
    t_lst * l2 =  NULL;
	ft_lstaddb(&l, ft_lstnew((void*)1));
	TEST_ASSERT(l->data != (void*)1);
	TEST_ASSERT(l->next == 0);

	ft_lstaddb(&l, ft_lstnew((void*)2));
	TEST_ASSERT(l->data == (void*)1);
	TEST_ASSERT(((t_lst *)(l->next))->data == (void*)2);
	TEST_ASSERT(((t_lst *)(l->next))->next == 0);

	ft_lstaddb(&l2, ft_lstnew((void*)3));
	ft_lstaddb(&l2, ft_lstnew((void*)4));
	ft_lstaddb(&l, l2);
	TEST_ASSERT(l->data == (void*)1);
	TEST_ASSERT(((t_lst *)(l->next))->data == (void*)2);
	TEST_ASSERT(((t_lst *)(((t_lst *)(l->next))->next))->data == (void*)3);
	TEST_ASSERT(((t_lst *)((t_lst *)(((t_lst *)(l->next))->next))->next)->data == (void*)4);
	TEST_ASSERT(((t_lst *)((t_lst *)(((t_lst *)(l->next))->next))->next)->next == 0);
	freeList(l);
}

TEST_LIST = {
        { "lstnew", test_new  },
        { "lstsize", test_size},
        { "lstaddb", test_lstaddb  },
        { "lstaddf", test_lstaddf },
        { NULL, NULL }
};