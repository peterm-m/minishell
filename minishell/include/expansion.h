/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:37:46 by pedromar          #+#    #+#             */
/*   Updated: 2024/03/12 22:23:54 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSION_H
# define EXPANSION_H

# include "minishell.h"

# define BUILTINS_DIR "/Users/pedromar/goinfre/minishell/minishell/builtins"

int		tilde_expansion(t_word *word);
int		parameter_expansion(t_word *word);

#endif