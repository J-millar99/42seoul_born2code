/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_value_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 12:31:43 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/16 12:13:57 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_idx(t_node *lst, int value)
{
	int		idx;

	idx = 0;
	while (lst->value != value)
	{
		idx++;
		lst = lst->next;
	}
	return (idx);
}

int	find_in_alst(t_node *alst, int b_val)
{
	int		i;
	t_node	*tmp;

	i = 1;
	if (bi_lstlast(alst)->value < b_val && b_val < alst->value)
		i = 0;
	else if (lst_max(alst) < b_val || b_val < lst_min(alst))
		i = find_idx(alst, lst_min(alst));
	else
	{
		tmp = alst->next;
		while (tmp->value < b_val || b_val < alst->value)
		{
			alst = alst->next;
			tmp = alst->next;
			i++;
		}
	}
	return (i);
}

/*
	before push,
	The number of times the stack needs to be rotated
	to place the value in the correct position.
*/

int	find_in_blst(t_node *blst, int a_val)
{
	int		i;
	t_node	*tmp;

	i = 1;
	if (blst->value < a_val && a_val < bi_lstlast(blst)->value)
		i = 0;
	else if (lst_max(blst) < a_val || a_val < lst_min(blst))
		i = find_idx(blst, lst_max(blst));
	else
	{
		tmp = blst->next;
		while (blst->value < a_val || a_val < tmp->value)
		{
			blst = blst->next;
			tmp = blst->next;
			i++;
		}
	}
	return (i);
}
