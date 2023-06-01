/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:56:21 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/01 18:57:29 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_node **alst, t_node **blst)
{
	if (*blst == NULL)
		return ;
	process(alst, blst);
	ft_printf("pa\n");
}

void	push_b(t_node **blst, t_node **alst)
{
	if (*alst == NULL)
		return ;
	process(blst, alst);
	ft_printf("pb\n");
}
