/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:07:00 by pedro             #+#    #+#             */
/*   Updated: 2024/04/02 18:07:01 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef EXPANSION_H
# define EXPANSION_H

# include "minishell.h"

void	expander(t_token *input);
int		tilde_expansion(t_token *word);
int		parameter_expansion(t_token *word, int start_expan);
void	filename_expansion(void);
void	quote_remove(char *str);

#endif
