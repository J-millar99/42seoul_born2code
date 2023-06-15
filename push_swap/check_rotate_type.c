/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rotate_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:20:05 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/15 15:04:13 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	what is the rotate type returning the least cost.
*/

int	check_rotate_type_atob(t_node *alst, t_node *blst)
{
	int		min_cost;
	int		asize;
	t_node	*a_val;

	a_val = alst;
	asize = lstsize(alst);
	min_cost = case_rrarrb_atob(alst, blst, a_val->value);
	while (asize--)
	{
		if (min_cost > case_rarb_atob(alst, blst, a_val->value))
			min_cost = case_rarb_atob(alst, blst, a_val->value);
		if (min_cost > case_rrarrb_atob(alst, blst, a_val->value))
			min_cost = case_rrarrb_atob(alst, blst, a_val->value);
		if (min_cost > case_rarrb_atob(alst, blst, a_val->value))
			min_cost = case_rarrb_atob(alst, blst, a_val->value);
		if (min_cost > case_rrarb_atob(alst, blst, a_val->value))
			min_cost = case_rrarb_atob(alst, blst, a_val->value);
		a_val = a_val->next;
	}
	return (min_cost);
}

int	check_rotate_type_btoa(t_node *alst, t_node *blst)
{
	int		min_cost;
	int		bsize;
	t_node	*b_val;

	b_val = blst;
	bsize = lstsize(blst);
	min_cost = case_rrarrb_btoa(alst, blst, b_val->value);
	while (bsize--)
	{
		if (min_cost > case_rarb_btoa(alst, blst, b_val->value))
			min_cost = case_rarb_btoa(alst, blst, b_val->value);
		if (min_cost > case_rrarrb_btoa(alst, blst, b_val->value))
			min_cost = case_rrarrb_btoa(alst, blst, b_val->value);
		if (min_cost > case_rarrb_btoa(alst, blst, b_val->value))
			min_cost = case_rarrb_btoa(alst, blst, b_val->value);
		if (min_cost > case_rrarb_btoa(alst, blst, b_val->value))
			min_cost = case_rrarb_btoa(alst, blst, b_val->value);
		b_val = b_val->next;
	}
	return (min_cost);
}
