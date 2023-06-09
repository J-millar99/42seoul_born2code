/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:42:20 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/17 18:42:20 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft_bonus.h"

int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}
