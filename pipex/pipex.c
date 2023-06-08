/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:12:41 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/06 14:12:41 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
    commands to implement
    1. grep
    2. ls
    3. wc
*/

/*
    argv number = n
    av[0]: pipex(program name)
    av[1]: first file
    av[4]: last file
    av[1 < n < 4]: command
*/

int main(int ac, char *av[])
{
    int     fd[2];
    pid_t   child;

    if (ac == 5)
    {
        child = fork(); 
        if (pipe(fd) == -1 || child == -1)
            print_error();
        if (child == 0)
            c_process();
        if (waitpid(child, NULL, 0) == -1)
            print_error();
        p_process();
    }
    else
    {
        /* error */
    }
    return (0);
}