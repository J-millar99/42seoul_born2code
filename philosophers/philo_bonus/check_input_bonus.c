/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:29:59 by jaehyji           #+#    #+#             */
/*   Updated: 2023/11/27 18:24:23 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static char	*make_str(int argc, char **argv);
static int	cnt_arr(char **arr);
static void	make_system_info(char **argv, t_sys *system);

void	check_input(int argc, char **argv, t_sys *system)
{
	int		cnt;
	char	*line;
	char	**line_arr;

	line = make_str(argc, argv);
	if (!line)
		error("number of argument error");
	line_arr = ft_split(line, ' ');
	free_str(line);
	if (!line_arr)
		error("line_arr ft_split error");
	cnt = cnt_arr(line_arr);
	if (cnt != 4 && cnt != 5)
		error("number of argument error");
	make_system_info(line_arr, system);
}

char	*ft_strdup(const char *s1)
{
	size_t	s1_len;
	char	*dupstr;

	s1_len = ft_strlen(s1);
	dupstr = (char *)malloc(sizeof(char) * (s1_len + 1));
	if (!dupstr)
		return (NULL);
	ft_memcpy(dupstr, s1, s1_len + 1);
	return (dupstr);
}

static char	*make_str(int argc, char **argv)
{
	int		i;
	char	*str;
	char	*tmp;

	if (!*argv)
		return (NULL);
	str = ft_strdup(argv[0]);
	if (!str)
		error("ft_strdup error");
	i = 1;
	while (i < argc - 1)
	{
		tmp = str;
		str = ft_strspacejoin(str, argv[i]);
		if (!str)
		{
			free_str(tmp);
			error("ft_strspacejoin error");
		}
		i++;
		free(tmp);
	}
	return (str);
}

static int	cnt_arr(char **arr)
{
	int	idx;

	idx = 0;
	while (arr[idx])
		idx++;
	return (idx);
}

static void	make_system_info(char **argv, t_sys *system)
{
	long long	num;

	num = ft_atoll(argv[0]);
	if (num > 200)
		error("argument value error");
	system->num_of_philo = (t_uint) num;
	num = ft_atoll(argv[1]);
	system->time_to_die = (t_uint) num;
	num = ft_atoll(argv[2]);
	system->time_to_eat = (t_uint) num;
	num = ft_atoll(argv[3]);
	system->time_to_sleep = (t_uint) num;
	num = ft_atoll(argv[4]);
	if (num == 0)
		num = -1;
	system->num_of_must_meals = num;
	free_arr(argv);
}
