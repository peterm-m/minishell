#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "acutest.h"
#include "minishell.h"

typedef enum e_test_out
{
	PASS,
	FAIL
}	t_test_out;

void	test_syntax(void);

#define calc_time(cur_time) (((double)(clock() - cur_time))/CLOCKS_PER_SEC)
