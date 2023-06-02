/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_case_atob.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 12:13:04 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/01 20:25:47 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	case_rarb_atob(t_node *alst, t_node *blst, int value)
{
	int		i;

	i = find_right_place_blst(blst, value);
	if (i < find_idx(alst, value))
		i = find_idx(alst, value);
	return (i);
}

int	case_rrarrb_atob(t_node *alst, t_node *blst, int value)
{
	int		i;

	i = 0;
	if (find_right_place_blst(blst, value))
		i = lstsize(blst) - find_right_place_blst(blst, value);
	if ((i < (lstsize(alst) - find_idx(alst, value))) && find_idx(alst, value))
		i = lstsize(alst) - find_idx(alst, value);
	return (i);
}

int	case_rarrb_atob(t_node *alst, t_node *blst, int value)
{
	int		i;

	i = 0;
	if (find_right_place_blst(blst, value))
		i = lstsize(blst) - find_right_place_blst(blst, value);
	i = find_idx(alst, value) + i;
	return (i);
}

int	case_rrarb_atob(t_node *alst, t_node *blst, int value)
{
	int		i;

	i = 0;
	if (find_idx(alst, value))
		i = lstsize(alst) - find_idx(alst, value);
	i = find_right_place_blst(blst, value) + i;
	return (i);
}
