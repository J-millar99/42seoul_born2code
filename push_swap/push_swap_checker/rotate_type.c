/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:44:15 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/12 12:52:03 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	rotate_reverse_a_np(t_node **alst)
{
	if (lstsize(*alst) < 2)
		return ;
	if ((*alst)->prev)
		*alst = (*alst)->prev;
}

void	rotate_reverse_b_np(t_node **blst)
{
	if (lstsize(*blst) < 2)
		return ;
	if ((*blst)->prev)
		*blst = (*blst)->prev;
}

void	rotate_command(t_node **alst, t_node **blst, char *command)
{
	if (!ft_strcmp(command, "ra\n"))
		rotate_a_np(alst);
	else if (!ft_strcmp(command, "rb\n"))
		rotate_b_np(blst);
	else if (!ft_strcmp(command, "rr\n"))
	{
		rotate_a_np(alst);
		rotate_b_np(blst);
	}
	else if (!ft_strcmp(command, "rra\n"))
		rotate_reverse_a_np(alst);
	else if (!ft_strcmp(command, "rrb\n"))
		rotate_reverse_b_np(blst);
	else if (!ft_strcmp(command, "rrr\n"))
	{
		rotate_reverse_a_np(alst);
		rotate_reverse_b_np(blst);
	}
	else
		print_error();
}
