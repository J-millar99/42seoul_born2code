/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:56:51 by jaehyji           #+#    #+#             */
/*   Updated: 2023/05/30 14:06:35 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_node **alst)
{
	if (!*alst)
		return ;
	if ((*alst)->next)
		*alst = (*alst)->next;
	ft_printf("ra\n");
}

void	rotate_b(t_node **blst)
{
	if (!*blst)
		return ;
	if ((*blst)->next)
		*blst = (*blst)->next;
	ft_printf("rb\n");
}

void	rotate_rotate(t_node **alst, t_node **blst)
{
	rotate_a(alst);
	rotate_b(blst);
	ft_printf("rr\n");
}