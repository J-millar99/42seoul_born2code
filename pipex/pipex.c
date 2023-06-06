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
    av[n - 1]: last file
    av[1 ~ n - 1]: command
*/

int main(int ac, char *av[])
{
    check_files(av);
}