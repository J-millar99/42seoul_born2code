/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 02:03:33 by jaehyji           #+#    #+#             */
/*   Updated: 2023/03/26 02:03:33 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft_bonus.h"

int	ft_lstsize(t_list *lst)
{
	int		lst_cnt;

	lst_cnt = 0;
	while (lst != NULL)
	{
		++lst_cnt;
		lst = lst->next;
	}
	return (lst_cnt);
}
