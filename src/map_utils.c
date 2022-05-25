/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmicheli <mmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:00:16 by mmicheli          #+#    #+#             */
/*   Updated: 2022/05/16 19:38:38 by mmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	make_zoom(t_dots *buf, float *x1, float *y1, t_place *map)
{
	buf->x *= map->zoom;
	*x1 *= map->zoom;
	buf->y *= map->zoom;
	*y1 *= map->zoom;
	map->dot.z *= map->zoom;
	map->dot.z1 *= map->zoom;
}

void	make_color(t_place *map, t_dots *buf)
{
	map->color = buf->dot_color;
	if (map->color == 0)
	{
		if (buf->z > 0 || buf->z1 > 0 || buf->z < 0 || buf->z1 < 0)
			map->color = map->color_1;
		else
			map->color = map->color_2;
	}
}

void	make_3d(float *x, float *y, int z, t_place *map)
{
	float	prev_x;
	float	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(map->angle);
	*y = (prev_x + prev_y) * sin(map->angle) - z;
}

void	make_shift(t_dots *buf, float *x1, float *y1, t_place *map)
{
		buf->x += map->shift_x;
		buf->y += map->shift_y;
		*x1 += map->shift_x;
		*y1 += map->shift_y;
}

void	color_change(t_place *map)
{
	static int	fl;

	if (fl == 1)
	{
		map->color_1 = C_BLUE;
		map->color_2 = C_GREEN;
		fl++;
		return ;
	}
	if (fl == 2)
	{
		map->color_1 = C_WHITE;
		map->color_2 = C_RED;
		fl = 0;
		return ;
	}
	map->color_1 = C_YELLOW;
	map->color_2 = C_ORANGE;
		fl++;
}
