/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:04:31 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/12 11:52:53 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_reverse_a(t_node **alst)
{
	if (lstsize(*alst) < 2)
		return ;
	if ((*alst)->prev)
		*alst = (*alst)->prev;
	write(1, "rra\n", 4);
}

void	rotate_reverse_b(t_node **blst)
{
	if (lstsize(*blst) < 2)
		return ;
	if ((*blst)->prev)
		*blst = (*blst)->prev;
	write(1, "rrb\n", 4);
}

void	rotate_rotate_reverse(t_node **alst, t_node **blst)
{
	rotate_reverse_a(alst);
	rotate_reverse_b(blst);
	write(1, "rrr\n", 4);
}
