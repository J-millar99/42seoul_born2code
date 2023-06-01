/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:04:31 by jaehyji           #+#    #+#             */
/*   Updated: 2023/05/30 14:08:33 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_reverse_a(t_node **alst)
{
	if (!*alst)
		return ;
	if ((*alst)->prev)
		*alst = (*alst)->prev;
	ft_printf("rra\n");
}

void	rotate_reverse_b(t_node **blst)
{
	if (!*blst)
		return ;
	if ((*blst)->prev)
		*blst = (*blst)->prev;
	ft_printf("rrb\n");
}

void	rotate_rotate_reverse(t_node **alst, t_node **blst)
{
	rotate_reverse_a(alst);
	rotate_reverse_b(blst);
	ft_printf("rrr\n");
}
