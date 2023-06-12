/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:56:21 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/12 16:53:15 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_node **alst, t_node **blst)
{
	if (*blst == NULL)
		return ;
	process(alst, blst);
	write(1, "pa\n", 3);
}

void	push_b(t_node **blst, t_node **alst)
{
	if (*alst == NULL)
		return ;
	process(blst, alst);
	write(1, "pb\n", 3);
}

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
