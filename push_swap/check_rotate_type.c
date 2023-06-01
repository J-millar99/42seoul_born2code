/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rotate_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:20:05 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/01 18:48:17 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_rotate_type_atob(t_node *alst, t_node *blst)
{
	int		i;
	int		asize;

	asize = lstsize(alst);
	i = case_rrarrb_atob(alst, blst, alst->value); /* 터진지점 */
	while (asize--)
	{
		if (i > case_rarb_atob(alst, blst, alst->value))
			i = case_rarb_atob(alst, blst, alst->value);
		if (i > case_rrarrb_atob(alst, blst, alst->value))
			i = case_rrarrb_atob(alst, blst, alst->value);
		if (i > case_rarrb_atob(alst, blst, alst->value))
			i = case_rarrb_atob(alst, blst, alst->value);
		if (i > case_rrarb_atob(alst, blst, alst->value))
			i = case_rrarb_atob(alst, blst, alst->value);
		alst = alst->next;
	}
	return (i);
}

int	check_rotate_type_btoa(t_node *alst, t_node *blst)
{
	int		i;
	int		bsize;

	bsize = lstsize(blst);
	i = case_rrarrb_btoa(alst, blst, blst->value);
	while (bsize--)
	{
		if (i > case_rarb_btoa(alst, blst, blst->value))
			i = case_rarb_btoa(alst, blst, blst->value);
		if (i > case_rrarrb_btoa(alst, blst, blst->value))
			i = case_rrarrb_btoa(alst, blst, blst->value);
		if (i > case_rarrb_btoa(alst, blst, blst->value))
			i = case_rarrb_btoa(alst, blst, blst->value);
		if (i > case_rrarb_btoa(alst, blst, blst->value))
			i = case_rrarb_btoa(alst, blst, blst->value);
		blst = blst->next;
	}
	return (i);
}
