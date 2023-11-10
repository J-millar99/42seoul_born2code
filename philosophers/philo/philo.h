/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:09:00 by jaehyji           #+#    #+#             */
/*   Updated: 2023/11/10 17:35:13 by jaehyji          ###   ########.fr       */
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
	struct s_system	*info;
	pthread_t		pthread_behavior;
	pthread_t		pthread_supervisor;
	unsigned int	idx;
	unsigned int	num_of_meals;
	unsigned int	status;
	unsigned int	lifespan;
	unsigned int	eating;
	pthread_mutex_t	message;
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
char			**ft_split(char const *s, char c);
char			*ft_strspacejoin(char const *s1, char const *s2);
char			*ft_substr(char const *str, unsigned int start, size_t len);
char			*ft_strdup(const char *s1);
size_t			ft_strlen(const char *s);
void			*ft_memcpy(void *dst, const void *src, size_t n);
int				ft_strcmp(char *s1, char *s2);
/*	check_input	*/
int				check_input(int argc, char **argv, t_sys *system);

/*	clean_up	*/
void			free_str(char *str);
void			free_arr(char **str);
int				ft_error(char *error_string, t_sys *system);
void			ft_exit(t_sys *system);

/*	environment	*/
int				set_environment(t_sys *system);

/*	simulate	*/
int				simulate(t_sys *sys);
int				isolated_philosopher(t_sys *system);
void			*behave(void *ptr);
void			*supervisor(void *ptr);
void			message(char *notice, t_philo *philo);
void			eating(t_philo *philo);

/*	utils	*/
unsigned int	get_time(t_sys *system);

#endif
