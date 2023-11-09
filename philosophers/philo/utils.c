/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: millar <millar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:56:50 by millar            #+#    #+#             */
/*   Updated: 2023/11/09 17:20:11 by millar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned int    get_time(t_sys *system)
{
    struct timeval  time_val;

    if (gettimeofday(&time_val, NULL) == -1)
        return (ft_error("gettimeofday_founction_error", system));
    return ((time_val.tv_sec * (u_int64_t)1000) + (time_val.tv_usec / 1000));
}

int ft_strcmp(char *s1, char *s2)
{
    while (*s1 && *s2)
    {
        if (*s1 != *s2)
            return (*s1 - *s2);
        s1++;
        s2++;
    }
    return (*s1 - *s2);
}
