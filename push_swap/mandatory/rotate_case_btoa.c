/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_case_btoa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:23:07 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/15 15:16:20 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	case_rarb_btoa(t_node *alst, t_node *blst, int b_val)
{
	int		i;

	i = find_in_alst(alst, b_val);
	if (i < find_idx(blst, b_val))
		i = find_idx(blst, b_val);
	return (i);
}

int	case_rrarrb_btoa(t_node *alst, t_node *blst, int b_val)
{
	int		i;

	i = 0;
	if (find_in_alst(alst, b_val))
		i = lstsize(alst) - find_in_alst(alst, b_val);
	if ((i < (lstsize(blst) - find_idx(blst, b_val))) && find_idx(blst, b_val))
		i = lstsize(blst) - find_idx(blst, b_val);
	return (i);
}

int	case_rarrb_btoa(t_node *alst, t_node *blst, int b_val)
{
	int		i;

	i = 0;
	if (find_idx(blst, b_val))
		i = lstsize(blst) - find_idx(blst, b_val);
	i = find_in_alst(alst, b_val) + i;
	return (i);
}

int	case_rrarb_btoa(t_node *alst, t_node *blst, int b_val)
{
	int		i;

	i = 0;
	if (find_in_alst(alst, b_val))
		i = lstsize(alst) - find_in_alst(alst, b_val);
	i = find_idx(blst, b_val) + i;
	return (i);
}
