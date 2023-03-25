/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:49:27 by jaehyji           #+#    #+#             */
/*   Updated: 2023/03/25 17:51:05 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (lst == NULL || *lst == NULL)
		return ;
	temp = (*lst)->next;
	while (temp != NULL)
	{
		del((*lst)->content);
		free(*lst);
		*lst = temp;
		temp = (*lst)->next;
	}
	del((*lst)->content);
	free(*lst);
	*lst = NULL;
}
