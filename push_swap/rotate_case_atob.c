/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_case_atob.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 12:13:04 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/21 11:33:54 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	case_rarb_atob(t_node *alst, t_node *blst, int a_val)
{
	int		i;

	i = find_in_blst(blst, a_val);
	if (i < find_idx(alst, a_val))
		i = find_idx(alst, a_val);
	return (i);
}

int	case_rrarrb_atob(t_node *alst, t_node *blst, int a_val)
{
	int		i;

	i = 0;
	if (find_in_blst(blst, a_val))
		i = lstsize(blst) - find_in_blst(blst, a_val);
	if ((i < (lstsize(alst) - find_idx(alst, a_val))) && find_idx(alst, a_val))
		i = lstsize(alst) - find_idx(alst, a_val);
	return (i);
}

int	case_rarrb_atob(t_node *alst, t_node *blst, int a_val)
{
	int		i;

	i = 0;
	if (find_in_blst(blst, a_val))
		i = lstsize(blst) - find_in_blst(blst, a_val);
	i = find_idx(alst, a_val) + i;
	return (i);
}

int	case_rrarb_atob(t_node *alst, t_node *blst, int a_val)
{
	int		i;

	i = 0;
	if (find_idx(alst, a_val))
		i = lstsize(alst) - find_idx(alst, a_val);
	i = find_in_blst(blst, a_val) + i;
	return (i);
}
