/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 18:04:16 by jaehyji           #+#    #+#             */
/*   Updated: 2023/03/25 19:08:21 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define	BUFFER_SIZE = 42

char	*get_next_line(int fd)
{
	char	buff[BUFFER_SIZE + 1];

	read(fd, buff, BUFFER_SIZE);
}

int main()
{
}