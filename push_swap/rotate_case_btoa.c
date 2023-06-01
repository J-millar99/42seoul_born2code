/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_case_btoa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:23:07 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/01 17:31:44 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	case_rarb_btoa(t_node *alst, t_node *blst, int value)
{
	int		i;

	i = find_right_place_alst(alst, value);
	if (i < find_idx(blst, value))
		i = find_idx(blst, value);
	return (i);
}

int	case_rrarrb_btoa(t_node *alst, t_node *blst, int value)
{
	int		i;

	i = 0;
	if (find_right_place_alst(alst, value))
		i = lstsize(alst) - find_right_place_alst(alst, value);
	if ((i < (lstsize(blst) - find_idx(blst, value))) && find_idx(blst, value))
		i = lstsize(blst) - find_idx(blst, value);
	return (i);
}

int	case_rarrb_btoa(t_node *alst, t_node *blst, int value)
{
	int		i;

	i = 0;
	if (find_idx(blst, value))
		i = lstsize(blst) - find_idx(blst, value);
	i = find_right_place_alst(alst, value) + i;
	return (i);
}

int	case_rrarb_btoa(t_node *alst, t_node *blst, int value)
{
	int		i;

	i = 0;
	if (find_right_place_alst(alst, value))
		i = lstsize(alst) - find_right_place_alst(alst, value);
	i = find_idx(blst, value) + i;
	return (i);
}