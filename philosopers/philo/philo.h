/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: millar <millar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:09:00 by jaehyji           #+#    #+#             */
/*   Updated: 2023/11/02 06:08:42 by millar           ###   ########.fr       */
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
	int				info[5];
}	t_sys;

typedef struct s_id
{
	struct s_id		*prev;
	struct s_id		*next;
	pthread_t		threads;
	int				idx;
	int				right;
	int				left;
	int				eat_time;
	int				eat_num;
}	t_id;

/*	check_input	*/
int		check_input(int argc, char **argv, int *arr);
int		ft_atoi(const char *str);
char	*make_str(int argc, char **argv);
int 	cnt_arr(char **arr);

/*	clean	*/
void	free_str(char *str);
void	free_arr(char **str);
void	lstclear(t_id *lst);

/*	libft	*/
char	**ft_split(char const *s, char c);
char	*ft_strspacejoin(char const *s1, char const *s2);
char	*ft_substr(char const *str, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);

/*	enter	*/
int		enter(t_id **lst, int max);
t_id	*lstnew(void);
t_id	*lstlast(t_id *lst);
void	lstadd_back(t_id **lst, t_id *newnode);
void	escape(t_id *lst, int max);
#endif
