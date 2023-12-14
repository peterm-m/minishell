#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "acutest.h"
#include "minishell.h"

#define calc_time(cur_time) (((double)(clock() - cur_time))/CLOCKS_PER_SEC)
