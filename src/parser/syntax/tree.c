/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:10:59 by pedromar          #+#    #+#             */
/*   Updated: 2023/12/20 20:29:53 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tree	*ft_newtree(int  data)
{
	t_tree	*new;

	new  = (t_tree *) malloc(sizeof(t_tree));
	if (new == NULL)
		return (new);
	new->left = NULL;
	new->right = NULL;
	new->data = data;
	return (new);
}

size_t	ft_size_tree(t_tree	*tree)
{
	if (tree == NULL)
		return (0);
	else
		return (1 + ft_size_tree(tree->left) + ft_size_tree(tree->right));
}

size_t	ft_height_tree(t_tree *tree)
{
	int		h_left;
	int		h_rigth;

	if (tree == NULL)
		return (-1);
	h_left = ft_height_tree(tree->left);
	h_rigth = ft_height_tree(tree->right);
	return (1 + (h_left * ( h_left > h_rigth) + h_left * ( h_left <= h_rigth)));
}

t_tree	*ft_insert(t_tree *root, int data)
{
	if (root == NULL)
		return (ft_newtree(data));
	if (data <  root->data)
		root->left = ft_insert(root->left, data);
	else
		root->right = ft_insert(root->right, data);
	return (root);
}
