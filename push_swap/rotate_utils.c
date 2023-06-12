/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:56:51 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/12 16:55:01 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_node **alst)
{
	if (!*alst)
		return ;
	if ((*alst)->next)
		*alst = (*alst)->next;
	write(1, "ra\n", 3);
}

void	rotate_b(t_node **blst)
{
	if (!*blst)
		return ;
	if ((*blst)->next)
		*blst = (*blst)->next;
	write(1, "rb\n", 3);
}

void	rotate_a_np(t_node **alst)
{
	if (lstsize(*alst) < 2)
		return ;
	if ((*alst)->next)
		*alst = (*alst)->next;
}

void	rotate_b_np(t_node **blst)
{
	if (lstsize(*blst) < 2)
		return ;
	if ((*blst)->next)
		*blst = (*blst)->next;
}

void	rotate_rotate(t_node **alst, t_node **blst)
{
	rotate_a_np(alst);
	rotate_b_np(blst);
	write(1, "rr\n", 3);
}
