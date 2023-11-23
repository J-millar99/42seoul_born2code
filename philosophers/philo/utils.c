/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: millar <millar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:56:50 by millar            #+#    #+#             */
/*   Updated: 2023/11/23 23:42:22 by millar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    message(char *notice, t_philo *philo)
{
    long long	time;

    pthread_mutex_lock(&philo->system->message);
    if (check_system_status(philo->system) == SHUTDOWN)
        return ;
    time = get_time() - philo->age;
    printf("%lld %u %s\n", time, philo->idx, notice);
    if (!ft_strcmp(notice, "died"))
	{
    	pthread_mutex_lock(&philo->system->end);
        philo->system->status = SHUTDOWN;
    	pthread_mutex_unlock(&philo->system->end);
	}
    pthread_mutex_unlock(&philo->system->message);
}

long long	get_time(void)
{
	struct timeval	time_val;

	gettimeofday(&time_val, NULL);
	return ((time_val.tv_sec * 1000) + (time_val.tv_usec / 1000));
}

void	ft_usleep(long long limit_time, t_philo *philo)
{
	long long	start_time;
	long long	current_time;

	start_time = get_time();
	current_time = get_time();
	while (current_time - start_time < limit_time)
	{
		usleep(500);
		if (philo && !check_status(philo))
			break ;
		current_time = get_time();
	}
}

int	ft_strcmp(char *s1, char *s2)
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

long long	ft_atoll(const char *str)
{
	long long	num;

	if (!str)
		return (0);
	if (*str == '-')
		return (-1);
	if (*str == '+')
		str++;
	if (!*str)
		return (-1);
	num = 0;
	while ('0' <= *str && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		if (num > UINT_MAX)
			return (-1);
		str++;
	}
	if (*str)
		return (-1);
	return (num);
}