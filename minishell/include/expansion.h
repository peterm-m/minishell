/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:07:00 by pedro             #+#    #+#             */
/*   Updated: 2024/04/02 18:35:21 by pedro            ###   ########.fr       */
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
