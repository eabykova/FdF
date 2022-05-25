/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmicheli <mmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:11:56 by mmicheli          #+#    #+#             */
/*   Updated: 2022/05/23 14:50:38 by mmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	ft_close(t_place *map)
{
	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	exit(0);
}

static void	choose_window_size(t_place *map)
{
	if (map->height > 100 || map->width > 100)
	{
		map->img.addr = mlx_get_data_addr(map->img.img, \
		&map->img.bits_per_pixel, &map->img.line_length, \
		&map->img.endian);
		map->zoom = 5;
		if (map->height > 200 || map->width > 200)
			map->zoom = 1;
		map->shift_x = map->width * map->zoom / 2;
		map->shift_y = map->height * map->zoom * 0.5;
	}
	else
	{
		map->img.addr = mlx_get_data_addr(map->img.img, \
		&map->img.bits_per_pixel, &map->img.line_length, \
		&map->img.endian);
		map->zoom = 10;
		map->shift_x = map->width * map->zoom / 1.5;
		map->shift_y = map->height * map->zoom * 1.5;
	}
}

void	start_window(t_place *map)
{
	map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(map->mlx_ptr, MAP_WTH, MAP_HGT, "FdF");
	map->img.img = mlx_new_image(&map->mlx_ptr, MAP_WTH, MAP_HGT);
	choose_window_size(map);
	map->angle = 0.5;
	map->angle_x = 0;
	map->angle_y = 0;
	map->angle_z = -M_PI / 2;
	map->h = 1;
	map->color = 0;
	map->color_1 = C_WHITE;
	map->color_2 = C_RED;
	put_map(map);
	mlx_key_hook(map->win_ptr, key_discover, map);
	mlx_hook(map->win_ptr, 17, 0, ft_close, map);
	mlx_loop(map->mlx_ptr);
}
