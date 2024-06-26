/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:09:00 by jaehyji           #+#    #+#             */
/*   Updated: 2023/11/27 17:02:43 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <string.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <signal.h>
# include <sys/time.h>
# include <pthread.h>
# include <semaphore.h>

# define ACTIVATE 0
# define SHUTDOWN 1
# define ALIVE 0
# define DEAD 1

typedef struct s_system	t_sys;
typedef struct s_philo	t_philo;
typedef unsigned int	t_uint;

typedef struct s_philo
{
	t_uint		idx;
	long long	lifespan;
	int			num_of_meals;
	sem_t		*status;
	t_sys		*system;
}	t_philo;

typedef struct s_system
{
	t_uint		num_of_philo;
	t_uint		time_to_die;
	t_uint		time_to_eat;
	t_uint		time_to_sleep;
	int			num_of_must_meals;
	long long	time;
	sem_t		*message;
	sem_t		*forks;
	sem_t		**philo_status;
	pid_t		*pids;
}	t_sys;

/*	libft	*/
char		**ft_split(char const *s, char c);
char		*ft_strspacejoin(char const *s1, char const *s2);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_substr(char const *str, unsigned int start, size_t len);
char		*ft_strdup(const char *s1);
size_t		ft_strlen(const char *s);
void		*ft_memcpy(void *dst, const void *src, size_t n);
int			ft_strcmp(char *s1, char *s2);
long long	ft_atoll(const char *str);
void		*ft_malloc(unsigned long type, int size);
char		*ft_itoa(int n);

/*	check_input	*/
void		check_input(int argc, char **argv, t_sys *system);

/*	clean_up	*/
void		free_str(char *str);
void		free_arr(char **str);
void		ft_exit(t_sys *system);

/*	simulate	*/
void		set_environment(t_sys *system);
void		routine(t_sys *system);
void		simulate(t_sys *system);
void		message(char *notice, t_philo *philo);
void		check_philo_status(t_philo *philo);
t_philo		init_philo(t_sys *system);
/*	utils	*/
long long	get_time(void);
void		ft_usleep(long long limit_time, t_philo *philo);

/*	error	*/
void		error(char *error_string);

/*	semaphore	*/
sem_t		*ft_sem_open(const char *sem_name, int num_of_access_data);
void		ft_sem_wait(sem_t *semaphore);
void		ft_sem_post(sem_t *semaphore);
void		ft_sem_close(sem_t *semaphore);
void		ft_sem_unlink(const char *semaphore);

#endif
