/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:18:53 by jaehyji           #+#    #+#             */
/*   Updated: 2023/07/28 16:41:44 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define VERTICAL 800
# define HORIZONTAL 1280

# include "../minilibx_mms_20210621/mlx.h"
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>

typedef struct s_file
{
	int		limit_row;
	int		limit_col;
	int		width;
	int		height;
	int		mtp_x;
	int		mtp_y;
	int		fd;
	char	*filename;
}	t_file;

typedef struct s_map
{
	double	x;
	double	y;
	double	z;
	int		color;
}	t_map;

typedef struct s_mlx
{
	void	*mptr;
	void	*wptr;
}	t_mlx;

/*	check_utils	*/
void	checking_file(t_file *info);
void	checking_no_data(char *line, t_file *info);
void	checking_map_data(t_file *info);
void	checking_possible_map(char *line, t_file *info);

/* color_utils	*/
int		ft_atoi_fdf(char **str);
void	ft_atoi_z(t_map *map, char *str);
void	ft_atoi_color(t_map *map, char **str);
int		ft_atoi_hex(char *str);

/*	coordinates_utils	*/
t_map	coordinate(int row, int col, char **arr, t_file *info);
char	**one_coordinate_line(t_file *info);
void	locate_mid(t_map **map, t_file *info);
void	initializing_coordinates_data(t_map *map);
/*	error_utils	*/
void	print_error(char *estr, int code, t_file *info);

/*	key_utils	*/
int		on_key_press(int keycode);
void	input_key(void *win_ptr);

/*	map_utils	*/
t_map	**initial_map(t_file *info);
void	make_map(t_mlx *mlx, t_file *info);
void	plotting(t_mlx *mlx, t_map **map, t_file *info);
void	line_put(t_mlx *mlx, t_map map1, t_map map2, t_file *info);

/* rotate_algorithm	*/
void	isometric_projection(t_map **map, t_file *info);
void	rotate_std_x(t_map *map, double theta);
void	rotate_std_y(t_map *map, double theta);
void	rotate_std_z(t_map *map, double theta);

/*	utils	*/
void	initializing_fileinfo(t_file *info, char *filename);
int		is_sep(char c, char sep);
int		word_count(const char *s, char c);
void	free_split(char **array);
void	free_map(t_map **map, t_file *info);

/*	screen_utils	*/
void	setting_window(t_mlx *mlx, t_file *info);
void	adjusting_screen(t_map **map, t_file *info);

/*	temp_f	*/
void	put_crossline(t_mlx *mlx, t_file *info);
#endif
