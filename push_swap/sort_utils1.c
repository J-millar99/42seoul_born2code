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
	t_node	*lnode;
	t_node	*snode;

	if (*lst == NULL || (*lst)->next == NULL || (*lst)->prev == NULL)
		return ;
	snode = (*lst)->next;
	lnode = (*lst)->prev;
	if (snode->value != lnode->value)
	{
		(*lst)->prev = snode;
		(*lst)->next = snode->next;
		snode->next = snode->prev;
		snode->prev = lnode;
	}
	*lst = snode;
	if (snode->value != lnode->value)
		lnode->next = *lst;
}

void	push(t_node **bot, t_node **top)
{
	if (*top == NULL)
		return ;
	process(bot, top);
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
