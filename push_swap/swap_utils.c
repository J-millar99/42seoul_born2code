/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:12:53 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/05 13:26:19 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_node **alst)
{
	t_node	*lnode;
	t_node	*snode;
	int		size;

	size = lstsize(*alst);
	if (size < 2)
		return ;
	snode = (*alst)->next;
	lnode = (*alst)->prev;
	if (size > 2)
	{
		(*alst)->prev = snode;
		(*alst)->next = snode->next;
		snode->next = snode->prev;
		snode->prev = lnode;
	}
	if (size > 2)
	{
		lnode->next = snode;
		lnode->prev = *alst;
	}
	*alst = snode;
	write(1, "sa\n", 3);
}

void	swap_b(t_node **blst)
{
	t_node	*lnode;
	t_node	*snode;
	int		size;

	size = lstsize(*blst);
	if (size < 2)
		return ;
	snode = (*blst)->next;
	lnode = (*blst)->prev;
	if (size > 2)
	{
		(*blst)->prev = snode;
		(*blst)->next = snode->next;
		snode->next = snode->prev;
		snode->prev = lnode;
	}
	if (size > 2)
	{
		lnode->next = snode;
		lnode->prev = *blst;
	}
	*blst = snode;
	write(1, "sb\n", 3);
}

void	swap_swap(t_node **alst, t_node **blst)
{
	swap_a(alst);
	swap_b(blst);
	write(1, "ss\n", 3);
}
