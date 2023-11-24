/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:56:50 by millar            #+#    #+#             */
/*   Updated: 2023/11/24 18:27:39 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
		usleep(200);
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
		error("argument value error");
	if (*str == '-')
		error("argument value error");
	if (*str == '+')
		str++;
	if (!*str)
		error("argument value error");
	num = 0;
	while ('0' <= *str && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		if (num > UINT_MAX)
			error("argument value error");
		str++;
	}
	if (*str)
		error("argument value error");
	return (num);
}
