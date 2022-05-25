/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmicheli <mmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 13:55:02 by mmicheli          #+#    #+#             */
/*   Updated: 2022/05/16 20:30:39 by mmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../lib/libft.h"
# include "../mlx/mlx.h"
# include <math.h>
# include <stdio.h>

# define MAP_HGT 1080
# define MAP_WTH 1920
# define C_WHITE 16777215
# define C_RED 16711680
# define C_GREEN 2263842
# define C_BLUE 255
# define C_YELLOW 16776960
# define C_ORANGE 16747520

typedef struct s_fdf
{
	int				f_color;
	int				d_height;
	int				c_flag;
	struct s_fdf	*next;
}					t_fdf;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_dots
{
	float	x;
	float	x1;
	float	y;
	float	y1;
	float	z;
	float	z1;
	int		dot_color;
	int		c_flag;
	t_data	*img;
}				t_dots;

typedef struct s_place
{
	int		height;
	int		width;
	int		zoom;
	int		color;
	int		color_1;
	int		color_2;
	int		color_f;
	t_fdf	**coord;
	t_data	img;
	void	*mlx_ptr;
	void	*win_ptr;
	int		win_height;
	int		win_width;
	int		shift_x;
	int		shift_y;
	double	h;
	double	angle;
	double	angle_x;
	double	angle_y;
	double	angle_z;
	t_dots	dot;
}				t_place;

void	make_zoom(t_dots *buf, float *x1, float *y1, t_place *map);
void	make_color(t_place *map, t_dots *buf);
void	make_3d(float *x, float *y, int z, t_place *map);
void	make_shift(t_dots *buf, float *x1, float *y1, t_place *map);
void	color_change(t_place *map);
void	rotations(int key, t_place *map);

void	read_map(char *file_name, t_place *map);
void	start_window(t_place *map);
void	put_map(t_place *map);
int		key_discover(int key, t_place *map);
void	x_rotation(t_dots *buf, float *y1, float *z1, t_place *map);
void	y_rotation(t_dots *buf, float *x1, float *z1, t_place *map);
void	z_rotation(t_dots *buf, float *x1, float *y1, t_place *map);
void	iso_parallel(int key, t_place *map);

void	map_error(void);
void	fd_error(t_place *map);

#endif