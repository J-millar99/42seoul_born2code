/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:43:34 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/12 15:17:17 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_a_np(t_node **alst, t_node **blst)
{
	if (*blst == NULL)
		return ;
	process(alst, blst);
}

void	push_b_np(t_node **blst, t_node **alst)
{
	if (*alst == NULL)
		return ;
	process(blst, alst);
}

void	push_command(t_node **alst, t_node **blst, char *command)
{
	if (!ft_strcmp(command, "pa\n"))
		push_a_np(alst, blst);
	else if (!ft_strcmp(command, "pb\n"))
		push_b_np(blst, alst);
	else
		print_error();
}
