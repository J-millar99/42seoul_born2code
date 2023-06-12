/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:44:15 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/12 16:55:53 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_command(t_node **alst, t_node **blst, char *command)
{
	if (!ft_strcmp(command, "pa\n"))
		push_a_np(alst, blst);
	else if (!ft_strcmp(command, "pb\n"))
		push_b_np(blst, alst);
	else
		print_error();
}

void	swap_command(t_node **alst, t_node **blst, char *command)
{
	if (!ft_strcmp(command, "sa\n"))
		swap_a_np(alst);
	else if (!ft_strcmp(command, "sb\n"))
		swap_b_np(blst);
	else if (!ft_strcmp(command, "ss\n"))
	{
		swap_a_np(alst);
		swap_b_np(blst);
	}
	else
		print_error();
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
