/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:18:53 by jaehyji           #+#    #+#             */
/*   Updated: 2023/07/25 18:47:02 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx_mms_20210621/mlx.h"
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>

typedef struct s_map
{
	int		x;
	int		y;
	int		z;
	void	*next;
}	t_map;

/*	map_check	*/
void	check_map(char *av);
int		check_file(char *filename);
void	check_no_data(char *line);
int		check_num(char **arr);
void	check_possible_map(int fd, char *line);

/*	key_utils	*/
void	input_key(void *mlx_ptr, void *win_ptr);
int		on_key_press(int keycode, void *param);

/*	image_utils	*/
void	set_image(void *mlx_ptr, void *win_ptr);

/*	error_utils	*/
void	print_error(char *estr, int code);
void	free_arr(char **arr);

#endif