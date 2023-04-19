/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_str.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 00:04:40 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/19 02:42:15 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	p_str(char *str)
{
	int		plen;

	if (!str)
		return (write(1, "(null)", 6));
	plen = write(1, str, ft_strlen(str));
	return (plen);
}
