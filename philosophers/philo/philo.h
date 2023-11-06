/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: millar <millar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:09:00 by jaehyji           #+#    #+#             */
/*   Updated: 2023/11/06 16:58:21 by millar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct	s_philopher
{
	t_sys			*info;
	pthread_t		behavior;
	unsigned int	idx;
	unsigned int	num_of_meals;
	unsigned int	status;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
}	t_philo;

typedef struct s_system
{
	unsigned int	num_of_philo;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	num_of_must_meals;
	unsigned int	death;
	unsigned int	survive;
	unsigned int	start_time;
	t_philo			*philos;
	pthread_mutex_t	*forks;
}	t_sys;

/*	libft	*/
char		**ft_split(char const *s, char c);
char		*ft_strspacejoin(char const *s1, char const *s2);
char		*ft_substr(char const *str, unsigned int start, size_t len);
char		*ft_strdup(const char *s1);
size_t		ft_strlen(const char *s);
void		*ft_memcpy(void *dst, const void *src, size_t n);

/*	check_input	*/
int			check_input(int argc, char **argv, t_sys *system);
long long	ft_atoll(const char *str);
char		*make_str(int argc, char **argv);
int 		cnt_arr(char **arr);

#endif


