/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:56:58 by pedromar          #+#    #+#             */
/*   Updated: 2023/12/22 16:38:08 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYNTAX_H
# define SYNTAX_H

# include "minishell.h"

typedef struct s_tree
{
	int				data;
	struct s_tree	*left;
	struct s_tree	*right;
}	t_tree;

t_tree	*ft_newtree(int data);
size_t	ft_size_tree(t_tree	*tree);
size_t	ft_height_tree(t_tree *tree);
t_tree	*ft_insert(t_tree *root, int data);

void	syntax(t_dlst *lex);

#endif
