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
	t_node	*lastnode;
	t_node	*secondnode;

	if (*lst == NULL || (*lst)->next == NULL || (*lst)->prev == NULL)
		return ;
	secondnode = (*lst)->next;
	lastnode = (*lst)->prev;
	if (secondnode->value != lastnode->value)
	{
		(*lst)->prev = secondnode;
		(*lst)->next = secondnode->next;
		secondnode->next = secondnode->prev;
		secondnode->prev = lastnode;
	}
	*lst = secondnode;
	if (secondnode->value != lastnode->value)
		lastnode->next = *lst;
}

void	push(t_node **bot, t_node **top)
{
	t_node	*bot_lastnode;
	t_node	*bot_secondnode;
	t_node	*top_lastnode;
	t_node	*top_secondnode;

	if (*top == NULL)
		return ;
	process_top(&bot, &top);
	process_bot(&bot, &top);
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
