#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "acutest.h"

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

#define calc_time(cur_time) (((double)(clock() - cur_time))/CLOCKS_PER_SEC)
