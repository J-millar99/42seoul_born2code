/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:24:08 by jaehyji           #+#    #+#             */
/*   Updated: 2023/03/25 02:56:14 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
