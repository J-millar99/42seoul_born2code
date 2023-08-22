/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:10:09 by jaehyji           #+#    #+#             */
/*   Updated: 2023/08/22 15:11:08 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	split_free(char **str)
{
	int		idx;

	idx = 0;
	while (str[idx])
	{
		free(str[idx]);
		idx++;
	}
	free(str);
}

void	lstclear(t_id **lst)
{
	t_id	*temp;

	if (lst == NULL || *lst == NULL)
		return ;
	temp = (*lst)->next;
	while (temp != NULL)
	{
		free(*lst);
		*lst = temp;
		temp = (*lst)->next;
	}
	free(*lst);
}
