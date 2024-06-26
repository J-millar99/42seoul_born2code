/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_cs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 23:45:38 by jaehyji           #+#    #+#             */
/*   Updated: 2023/08/08 08:21:12 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	type_c(va_list vlist)
{
	int	c;

	c = va_arg(vlist, int);
	return (write(1, &c, 1));
}

int	type_s(va_list vlist)
{
	char	*str;

	str = va_arg(vlist, char *);
	if (!str)
		return (write(1, "(null)", 6));
	return (write(1, str, ft_strlen(str)));
}

int	type_percent(void)
{
	return (write(1, "%", 1));
}
