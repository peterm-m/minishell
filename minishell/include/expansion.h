/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <adiaz-uf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:37:46 by pedromar          #+#    #+#             */
/*   Updated: 2024/04/02 20:48:08 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef EXPANSION_H
# define EXPANSION_H

# include "minishell.h"

void	expander(t_token *input);
char	*tilde_expansion(char *str);
char	*parameter_expansion(char *str);
char	*filename_expansion(char *str);
void	quote_remove(char *str);

#endif
