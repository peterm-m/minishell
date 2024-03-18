/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:37:46 by pedromar          #+#    #+#             */
/*   Updated: 2024/03/15 18:24:38 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSION_H
# define EXPANSION_H

# include "minishell.h"

int		tilde_expansion(t_word *word);
int		parameter_expansion(t_word *word);

#endif