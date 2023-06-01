/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:28:19 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/01 18:55:53 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_algorithm(t_node **alst)
{
	t_node	*blst;
	int		idx;

	if (lstsize(*alst) == 2)
		swap_a(alst);
	else
	{
		blst = setting_blst(alst); /* 터진 지점 */
		alst = setting_alst(alst, &blst);
		idx = find_idx(*alst, lst_min(*alst));
		if (idx < lstsize(*alst) - idx)
		{
			while ((*alst)->value != lst_min(*alst))
				rotate_a(alst);
		}
		else
		{
			while ((*alst)->value != lst_min(*alst))
				rotate_reverse_a(alst);
		}	
	}
}

t_node	*setting_blst(t_node **alst)
{
	t_node	*blst;

	blst = NULL;
	if (lstsize(*alst) > 3)
		push_b(&blst, alst);
	if (lstsize(*alst) > 3 && !check_sorted(*alst))
		push_b(&blst, alst);
	if (lstsize(*alst) > 3 && !check_sorted(*alst))
		operate_remaining_alst3(&blst, alst);
	if (!check_sorted(*alst))
		sort_remaining_alst3(alst);
	return (blst);
}

t_node	**setting_alst(t_node **alst, t_node **blst)
{
	int		type;
	t_node	*tmp;

	while (*blst)
	{
		tmp = *blst;
		type = check_rotate_type_btoa(*alst, *blst);
		while (type >= 0)
		{
			if (type == case_rarb_btoa(*alst, *blst, tmp->value))
				type = rarb_push(alst, blst, tmp->value, 'b');
			else if (type == case_rrarrb_btoa(*alst, *blst, tmp->value))
				type = rrarrb_push(alst, blst, tmp->value, 'b');
			else if (type == case_rarrb_btoa(*alst, *blst, tmp->value))
				type = rarrb_push(alst, blst, tmp->value, 'b');
			else if (type == case_rrarb_btoa(*alst, *blst, tmp->value))
				type = rrarb_push(alst, blst, tmp->value, 'b');
			else
				tmp = tmp->next;
		}
	}
	return (alst);
}

void	operate_remaining_alst3(t_node **blst, t_node **alst)
{
	int		type;
	t_node	*tmp;

	while (lstsize(*alst) > 3 && !check_sorted(*alst))
	{
		tmp = *alst;
		type = check_rotate_type_atob(*alst, *blst); /* 터진 지점 */
		while (type >= 0)
		{
			if (type == case_rarb_atob(*alst, *blst, tmp->value))
				type = rarb_push(alst, blst, tmp->value, 'a');
			else if (type == case_rrarrb_atob(*alst, *blst, tmp->value))
				type = rrarrb_push(alst, blst, tmp->value, 'a');
			else if (type == case_rarrb_atob(*alst, *blst, tmp->value))
				type = rarrb_push(alst, blst, tmp->value, 'a');
			else if (type == case_rrarb_atob(*alst, *blst, tmp->value))
				type = rrarb_push(alst, blst, tmp->value, 'a');
			else
				tmp = tmp->next;
		}
	}
}

void	sort_remaining_alst3(t_node **alst)
{
	if (lst_min(*alst) == (*alst)->value)
	{
		rotate_reverse_a(alst);
		swap_a(alst);
	}
	else if (lst_max(*alst) == (*alst)->value)
	{
		rotate_a(alst);
		if (!check_sorted(*alst))
			swap_a(alst);
	}
	else
	{
		if (find_idx(*alst, lst_max(*alst)) == 1)
			rotate_reverse_a(alst);
		else
			swap_a(alst);
	}
}
