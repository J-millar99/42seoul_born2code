/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:33:03 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/01 17:56:02 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rarb_push(t_node **alst, t_node **blst, int value, char lst)
{
	if (lst == 'a')
	{
		while ((*alst)->value != value && find_right_place_alst(*blst, value) > 0)
			rotate_rotate(alst, blst);
		while ((*alst)->value != value)
			rotate_a(alst);
		while (find_right_place_alst(*blst, value) > 0)
			rotate_b(blst);
		push_b(blst, alst);
	}
	else
	{
		while ((*blst)->value != value && find_right_place_blst(*alst, value) > 0)
			rotate_rotate(alst, blst);
		while ((*blst)->value != value)
			rotate_b(blst);
		while (find_right_place_alst(*alst, value) > 0)
			rotate_a(alst);
		push_a(alst, blst);
	}
	return (-1);
}

int	rrarrb_push(t_node **alst, t_node **blst, int value, char lst)
{
	if (lst == 'a')
	{
		while ((*alst)->value != value && find_right_place_alst(*blst, value) > 0)
			rotate_rotate_reverse(alst, blst);
		while ((*alst)->value != value)
			rotate_reverse_a(alst);
		while (find_right_place_blst(*blst, value) > 0)
			rotate_reverse_b(blst);
		push_b(blst, alst);
	}
	else
	{
		while ((*blst)->value != value && find_right_place_blst(*alst, value) > 0)
			rotate_rotate_reverse(alst, blst);
		while ((*blst)->value != value)
			rotate_reverse_b(blst);
		while (find_right_place_blst(*blst, value) > 0)
			rotate_reverse_a(alst);
		push_a(alst, blst);
	}
	return (-1);
}

int	rarrb_push(t_node **alst, t_node **blst, int value, char lst)
{
	if (lst == 'a')
	{
		while ((*alst)->value != value)
			rotate_a(alst);
		while (find_right_place_blst(*blst, value) > 0)
			rotate_reverse_b(blst);
		push_b(blst, alst);
	}
	else
	{
		while (find_right_place_alst(*alst, value) > 0)
			rotate_a(alst);
		while ((*blst)->value != value)
			rotate_reverse_b(blst);
		push_a(alst, blst);
	}
	return (-1);
}

int	rrarb_push(t_node **alst, t_node **blst, int value, char lst)
{
	if (lst == 'a')
	{
		while ((*alst)->value != value)
			rotate_reverse_a(alst);
		while (find_right_place_blst(*blst, value) > 0)
			rotate_b(blst);
		push_b(blst, alst);
	}
	else
	{
		while (find_right_place_alst(*alst, value) > 0)
			rotate_reverse_a(alst);
		while ((*blst)->value != value)
			rotate_b(blst);
		push_a(alst, blst);
	}
	return (-1);
}
