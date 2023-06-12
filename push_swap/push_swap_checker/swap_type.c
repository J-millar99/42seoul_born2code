/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:44:03 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/12 15:17:23 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_a_np(t_node **alst)
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
		lnode->next = snode;
		lnode->prev = *alst;
	}
	*alst = snode;
}

void	swap_b_np(t_node **blst)
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
		lnode->next = snode;
		lnode->prev = *blst;
	}
	*blst = snode;
}

void	swap_command(t_node **alst, t_node **blst, char *command)
{
	if (!ft_strcmp(command, "sa\n"))
		swap_a_np(alst);
	else if (!ft_strcmp(command, "sb\n"))
		swap_b_np(blst);
	else if (!ft_strcmp(command, "ss\n"))
	{
		swap_a_np(alst);
		swap_b_np(blst);
	}
	else
		print_error();
}
