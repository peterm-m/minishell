#include <time.h>
#include <stdlib.h>
#include "acutest.h"

void	test_new0(void)
{
// ej test
	TEST_ASSERT(0 == 0);
}

void	test_new1(void)
{
// ej test
	TEST_ASSERT(0 == 0);
}

TEST_LIST = {
        { "test 0", test_new0  },
        { "test 1", test_new1 },
        { NULL, NULL }
};