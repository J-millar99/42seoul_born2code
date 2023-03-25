/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 01:57:41 by jaehyji           #+#    #+#             */
/*   Updated: 2023/03/26 01:57:41 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c == 32)
		return (64);
	else if ((33 <= c && c <= 47) || (58 <= c && c <= 64))
		return (16);
	else if ((91 <= c && c <= 96) || (123 <= c && c <= 126))
		return (16);
	else if (48 <= c && c <= 57)
		return (4);
	else if (65 <= c && c <= 90)
		return (1);
	else if (97 <= c && c <= 122)
		return (2);
	else
		return (0);
}
