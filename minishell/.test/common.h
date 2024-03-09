/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 20:43:30 by pedromar          #+#    #+#             */
/*   Updated: 2024/01/23 21:43:52 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include <stdio.h>
# include <stdlib.h>
# include <assert.h>
# include <string.h>

# include "minishell.h"
# include "acutest.h"

typedef enum e_test_out
{
	PASS,
	FAIL
}	t_test_out;


# define calc_time(cur_time) (((double)(clock() - cur_time))/CLOCKS_PER_SEC)

#endif