/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rotate_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:20:05 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/02 18:15:16 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_rotate_type_atob(t_node *alst, t_node *blst)
{
	int		i;
	int		asize;
	t_node	*tmp;

	tmp = alst;
	asize = lstsize(alst);
	i = case_rrarrb_atob(alst, blst, tmp->value);
	while (asize--)
	{
		if (i > case_rarb_atob(alst, blst, tmp->value))
			i = case_rarb_atob(alst, blst, tmp->value);
		if (i > case_rrarrb_atob(alst, blst, tmp->value))
			i = case_rrarrb_atob(alst, blst, tmp->value);
		if (i > case_rarrb_atob(alst, blst, tmp->value))
			i = case_rarrb_atob(alst, blst, tmp->value);
		if (i > case_rrarb_atob(alst, blst, tmp->value))
			i = case_rrarb_atob(alst, blst, tmp->value);
		tmp = tmp->next;
	}
	return (i);
}

int	check_rotate_type_btoa(t_node *alst, t_node *blst)
{
	int		i;
	int		bsize;
	t_node	*tmp;

	tmp = blst;
	bsize = lstsize(blst);
	i = case_rrarrb_btoa(alst, blst, tmp->value);
	while (bsize--)
	{
		if (i > case_rarb_btoa(alst, blst, tmp->value))
			i = case_rarb_btoa(alst, blst, tmp->value);
		if (i > case_rrarrb_btoa(alst, blst, tmp->value))
			i = case_rrarrb_btoa(alst, blst, tmp->value);
		if (i > case_rarrb_btoa(alst, blst, tmp->value))
			i = case_rarrb_btoa(alst, blst, tmp->value);
		if (i > case_rrarb_btoa(alst, blst, tmp->value))
			i = case_rrarb_btoa(alst, blst, tmp->value);
		tmp = tmp->next;
	}
	return (i);
}
