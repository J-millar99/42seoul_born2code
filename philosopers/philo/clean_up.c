/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: millar <millar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:10:09 by jaehyji           #+#    #+#             */
/*   Updated: 2023/11/02 06:08:50 by millar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_str(char *str)
{
	if (!str)
		return ;
	free(str);
	str = NULL;
}

void	free_arr(char **str)
{
	int		idx;

	idx = 0;
	while (str[idx])
	{
		free(str[idx]);
		str[idx] = NULL;
		idx++;
	}
	free(str);
	str = NULL;
}

void	escape(t_id *lst, int max)
{
	t_id	*tmp;

	while (max > 0)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
		max--;
	}
}

void	lstclear(t_id *lst)
{
	t_id	*tmp;

	if (lst == NULL)
		return ;
	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
}
