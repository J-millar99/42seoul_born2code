/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 16:44:44 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/18 16:45:23 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(void)
{
    //int fd = open("test1.txt", O_RDWR);
    // dup2(fd, STDIN_FILENO);
    // write(0, "!@#", 3);
    printf("%d\n", write(1, "123\n", 4));
    printf("%d\n", write(-1, "123\n", 4));
    return (0);
}