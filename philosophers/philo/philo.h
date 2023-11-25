/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: millar <millar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:09:00 by jaehyji           #+#    #+#             */
/*   Updated: 2023/11/25 19:57:25 by millar           ###   ########.fr       */
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

typedef struct s_system	t_sys;
typedef pthread_mutex_t	t_mutex;
typedef unsigned int	t_uint;

# define ACTIVATE 0
# define SHUTDOWN 1

# define ALIVE 0
# define DEAD 1

typedef struct s_philopher
{
	pthread_t	thread;
	t_sys		*system;
	t_uint		idx;
	int			num_of_meals;
	long long	lifespan;
	t_mutex		*r_fork;
	t_mutex		*l_fork;
}	t_philo;

typedef struct s_system
{
	t_uint		num_of_philo;
	t_uint		time_to_die;
	t_uint		time_to_eat;
	t_uint		time_to_sleep;
	int			num_of_must_meals;
	t_uint		status;
	long long	time;
	t_mutex		message;
	t_mutex		end;
	t_mutex		*forks;
	t_philo		*philos;
}	t_sys;

/*	libft	*/
char		**ft_split(char const *s, char c);
char		*ft_strspacejoin(char const *s1, char const *s2);
char		*ft_substr(char const *str, unsigned int start, size_t len);
char		*ft_strdup(const char *s1);
size_t		ft_strlen(const char *s);
void		*ft_memcpy(void *dst, const void *src, size_t n);
int			ft_strcmp(char *s1, char *s2);
long long	ft_atoll(const char *str);

/*	check_input	*/
int			check_input(int argc, char **argv, t_sys *system);

/*	clean_up	*/
void		free_str(char *str);
void		free_arr(char **str);
int			ft_error(char *error_string, t_sys *system);
void		ft_exit(t_sys *system);

/*	environment	*/
int			set_environment(t_sys *system);

/*	simulate	*/
void		*routine(void *ptr);
void		message(char *notice, t_philo *philo);
int			check_philosopher_status(t_philo *philo);
int			check_system_status(t_sys *system);
int			check_status(t_philo *philo);

/*	utils	*/
long long	get_time(void);
void		ft_usleep(long long limit_time, t_philo *philo);
#endif
