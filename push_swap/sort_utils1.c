/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:12:53 by jaehyji           #+#    #+#             */
/*   Updated: 2023/05/26 16:05:56 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node **lst)
{
	t_node	*fnode_prev;
	t_node	*fnode_next;
	t_node	*bnode_prev;
	t_node	*bnode_next;
	t_node	*bnode;

	bnode = (*lst)->next;
	fnode_prev = (*lst)->prev;
	fnode_next = (*lst)->next;
	bnode_prev = bnode->prev;
	bnode_next = bnode->next;
	(*lst)->prev = fnode_next;
	(*lst)->next = bnode_next;
	bnode->prev = fnode_prev;
	bnode->next = bnode_prev;
	*lst = bnode;
}

void	push(t_node **lst)
{
	if (!*lst)
		return ;

}

void	rotate(t_node **lst)
{
	if ((*lst)->next)
		*lst = (*lst)->next;
}

void	rotate_reverse(t_node **lst)
{
	if ((*lst)->prev)
		*lst = (*lst)->prev;
}
