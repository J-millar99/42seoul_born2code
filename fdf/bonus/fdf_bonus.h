/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:18:53 by jaehyji           #+#    #+#             */
/*   Updated: 2023/08/08 17:17:58 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

/*	macro	*/
# define VERTICAL 1200
# define HORIZONTAL 1600
# define ESC 53
# define UP 126
# define DOWN 125
# define RIGHT 124
# define LEFT 123
# define ZOOMIN 24
# define ZOOMOUT 27
# define ERASE 14
# define X_AXIS 7
# define Y_AXIS 16
# define Z_AXIS 6
# define PJ_A 18
# define PJ_B 19

/*	includes	*/
# include "../minilibx_mms_20210621/mlx.h"
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>

/*	structs	*/
typedef struct s_flag
{
	int		on;
	int		max;
	int		up_max;
	int		down_max;
	int		right_max;
	int		left_max;
}	t_flag;

typedef struct s_file
{
	int		limit_row;
	int		limit_col;
	int		fd;
	char	*filename;
}	t_file;

typedef struct s_map
{
	double	init_x;
	double	init_y;
	double	init_z;
	double	x;
	double	y;
	double	z;
	int		color;
}	t_map;

typedef struct s_mlx
{
	void	*mptr;
	void	*wptr;
	void	*img;
	char	*addr;
	t_map	**map;
	t_file	*info;
	t_flag	*lflag;
	int		bpp;
	int		len;
	int		endian;
}	t_mlx;

/*	check_utils	*/
void	checking_file(t_file *info);
void	checking_no_data(char *line, t_file *info);
void	checking_map_data(t_file *info);
void	checking_possible_map(char *line, t_file *info);

/*	get_color	*/
int		ft_atoi_fdf(char **str);
void	ft_atoi_z(t_map *map, char *str);
void	ft_atoi_color(t_map *map, char **str);
int		ft_atoi_hex(char *str);

/*	get_coordinates	*/
t_map	coordinate(int row, int col, char **arr, t_file *info);
char	**one_coordinate_line(t_file *info);
void	locate_mid(t_map **map, t_file *info);
void	locate_zero(t_map **map, t_file *info);
void	initializing_coordinates(t_map **map, t_file *info);

/*	error_utils	*/
void	print_error(char *estr, int code, t_file *info);

/*	event_hooks	*/
int		event_hooks(t_mlx *mlx);
int		input_key(int keycode, t_mlx *mlx);
int		close_window(t_mlx *mlx);

/*	map_utils	*/
t_map	**initial_map(t_file *info);
void	make_map(t_mlx *mlx, t_file *info);
void	draw(t_mlx *mlx, t_map **map, t_file *info);
void	draw_line(t_mlx *mlx, t_map p, t_map q);

/*	projection_key	*/
void	projection_key(t_mlx *mlx, int keycode);
void	isometric_projection(t_mlx *mlx, t_map **map, t_file *info);
void	oblique_projection(t_mlx *mlx, t_map **map, t_file *info);

/* rotate_algorithm	*/
void	rotate_std_x(t_map *map, double theta);
void	rotate_std_y(t_map *map, double theta);
void	rotate_std_z(t_map *map, double theta);

/*	rotate_key	*/
void	rotate_key(t_mlx *mlx, int keycode);
void	rotate_x(t_mlx *mlx);
void	rotate_y(t_mlx *mlx);
void	rotate_z(t_mlx *mlx);

/*	initializing_utils	*/
void	initializing_fileinfo(t_file *info, char *filename);
void	initializing_coordinates_data(t_map *map);
void	setting_mlx(t_flag *lflag, t_mlx *mlx, t_map **map, t_file *info);

/*	utils	*/
int		is_sep(char c, char sep);
int		word_count(const char *s, char c);
void	free_split(char **array);
void	free_map(t_map **map, t_file *info);
void	get_height(t_map **map, t_file *info);

/*	screen_utils	*/
void	setting_window(t_mlx *mlx, t_file *info);
void	setting_img_data(t_mlx *mlx, t_file *info);
void	setting_image(t_mlx *mlx);

/*	move_key	*/
void	move_key(t_mlx *mlx, int keycode);
void	move_up(t_mlx *mlx);
void	move_down(t_mlx *mlx);
void	move_right(t_mlx *mlx);
void	move_left(t_mlx *mlx);

/*	size_key	*/
void	size_key(t_mlx *mlx, int keycode);
void	zoomin_image(t_mlx *mlx);
void	zoomout_image(t_mlx *mlx);

/*	limit_utils	*/
void	check_limit(t_mlx *mlx);
int		up_limit(t_map **map, t_file *info);
int		down_limit(t_map **map, t_file *info);
int		right_limit(t_map **map, t_file *info);
int		left_limit(t_map **map, t_file *info);

#endif
