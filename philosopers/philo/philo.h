/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:09:00 by jaehyji           #+#    #+#             */
/*   Updated: 2023/08/18 21:16:17 by jaehyji          ###   ########.fr       */
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

typedef struct s_sys
{
	struct timeval	time;
	pthread_mutex_t	mutex;
	int				input_arr[5];
}	t_sys;

/*		f_string	*/
char	*ft_strspacejoin(char const *s1, char const *s2);
char	*ft_substr(char const *str, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	**ft_split(char const *s, char c);

/*		f_check		*/
int		ft_atoi(const char *str);
char	*make_str(int ac, char **av);
int		check_input(int argc, char **argv, int *arr);

/*		f_clean		*/
void	split_free(char **str);

#endif
