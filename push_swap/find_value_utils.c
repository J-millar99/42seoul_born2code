/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_value_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 12:31:43 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/01 18:57:48 by jaehyji          ###   ########.fr       */
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

int	find_right_place_alst(t_node *alst, int value)
{
	int		i;
	t_node	*tmp;

	i = 0;
	if (bi_lstlast(alst)->value < value && value < alst->value)
		i = 0;
	else if (lst_max(alst) < value || value < lst_min(alst))
		i = find_idx(alst, lst_max(alst));
	else
	{
		tmp = alst->next;
		while (tmp->value < value || value < alst->value)
		{
			alst = alst->next;
			tmp = alst->next;
			i++;
		}
	}
	return (i);
}

int	find_right_place_blst(t_node *blst, int value)
{
	int		i;
	t_node	*tmp;

	i = 0;
	if (blst->value < value && value < bi_lstlast(blst)->value) /* 터진지점 */
	{
		i = 0;
	}
	else if (lst_max(blst) < value || value < lst_min(blst))
		i = find_idx(blst, lst_max(blst));
	else
	{
		tmp = blst->next;
		while (blst->value < value || value < tmp->value)
		{
			blst = blst->next;
			tmp = blst->next;
			i++;
		}
	}
	return (i);
}
