/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmicheli <mmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:27:33 by mmicheli          #+#    #+#             */
/*   Updated: 2022/05/23 14:55:33 by mmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static void	imagine_change(t_dots *buf, float *x1, float *y1, t_place *map)
{
	make_color(map, buf);
	make_zoom(buf, x1, y1, map);
	x_rotation(buf, y1, &map->dot.z1, map);
	y_rotation(buf, x1, &map->dot.z1, map);
	z_rotation(buf, x1, y1, map);
	make_3d(&buf->x, &buf->y, map->dot.z, map);
	make_3d(x1, y1, map->dot.z1, map);
	make_shift(buf, x1, y1, map);
}

static void	put_line(t_dots buf, float x1, float y1, t_place *map)
{
	float	x_st;
	float	y_st;
	int		max;

	map->dot.z = map->coord[(int)buf.y][(int)buf.x].d_height * map->h;
	map->dot.z1 = map->coord[(int)y1][(int)x1].d_height * map->h;
	buf.z = map->dot.z;
	buf.z1 = map->dot.z1;
	imagine_change(&buf, &x1, &y1, map);
	x_st = x1 - buf.x;
	y_st = y1 - buf.y;
	max = ft_max_i(ft_mod(x_st), ft_mod(y_st));
	x_st /= max;
	y_st /= max;
	while ((int)(buf.x - x1) || (int)(buf.y - y1))
	{
		if (buf.x >= 20 && buf.x <= MAP_WTH - 20 && buf.y >= 20 && buf.y <= \
			MAP_HGT - 20)
			my_mlx_pixel_put(&map->img, buf.x, buf.y, map->color);
		buf.x += x_st;
		buf.y += y_st;
	}
}

void	put_map(t_place *map)
{
	t_dots	buf;

	map->dot.y = 0;
	buf.c_flag = 0;
	while (map->dot.y < map->height)
	{
		map->dot.x = 0;
		while (map->dot.x < map->width)
		{
			buf.x = map->dot.x;
			buf.y = map->dot.y;
			buf.dot_color = 0;
			buf.dot_color = map->coord[(int)buf.y][(int)buf.x].f_color;
			if (buf.dot_color == 0)
				buf.c_flag++;
			if (map->dot.x < map->width - 1)
				put_line(buf, (map->dot.x + 1), map->dot.y, map);
			if (map->dot.y < map->height - 1)
				put_line(buf, map->dot.x, (map->dot.y + 1), map);
			map->dot.x++;
		}
		map->dot.y++;
	}
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.img, 0, 0);
	mlx_destroy_image(map->mlx_ptr, map->img.img);
}
