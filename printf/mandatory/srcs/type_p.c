/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 00:25:33 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/29 03:07:58 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	type_p(va_list vlist)
{
	void	*ptr;
	int		plen;

	ptr = va_arg(vlist, void *);
	if ((unsigned long) ptr == 0)
		return (write(1, "0x0", 3));
	plen = write(1, "0x", 2);
	plen += check_unsigned_long_len((unsigned long) ptr);
	print_pointer((unsigned long) ptr);
	return (plen);
}

void	print_pointer(unsigned long num)
{
	if (num >= 16)
	{
		print_pointer(num / 16);
		print_pointer(num % 16);
	}
	else
		write(1, &"0123456789abcdef"[num % 16], 1);
}
