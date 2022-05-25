/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configurations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmicheli <mmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:20:12 by mmicheli          #+#    #+#             */
/*   Updated: 2022/05/19 20:35:13 by mmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	move_keys(int key, t_place *map)
{
	if (key == 126)
		map->shift_y -= 10;
	if (key == 125)
		map->shift_y += 10;
	if (key == 124)
		map->shift_x += 10;
	if (key == 123)
		map->shift_x -= 10;
}

void	change_shift_angle(int key, t_place *map)
{
	if (key == 12)
		map->angle -= 0.05;
	if (key == 13)
		map->angle += 0.05;
	if (key == 15)
		map->h += 0.1;
	if (key == 14)
		map->h -= 0.1;
}

void	change_zoom_color(int key, t_place *map)
{
	if (key == 27)
	{
		if (map->zoom - 5 > 0)
			map->zoom -= 5;
	}
	if (key == 24)
			map->zoom += 5;
	if (key == 49)
		color_change(map);
}

void	escape(t_place *map)
{
	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	ft_exit(0);
}

int	key_discover(int key, t_place *map)
{
	if ((key >= 0 && key <= 4) || (key >= 6 && key <= 7))
		rotations(key, map);
	if (key >= 12 && key <= 15)
		change_shift_angle(key, map);
	if (key == 24 || key == 27 || key == 49)
		change_zoom_color(key, map);
	if (key == 34 || key == 35)
		iso_parallel(key, map);
	if (key == 53)
		escape(map);
	if (key >= 123 && key <= 126)
		move_keys(key, map);
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	map->img.img = mlx_new_image(&map->mlx_ptr, MAP_WTH, \
	MAP_HGT);
	map->img.addr = mlx_get_data_addr(map->img.img, \
		&map->img.bits_per_pixel, &map->img.line_length, \
		&map->img.endian);
	put_map(map);
	return (0);
}
