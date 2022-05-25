/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmicheli <mmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:53:32 by mmicheli          #+#    #+#             */
/*   Updated: 2022/05/09 15:39:01 by mmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

void	x_rotation(t_dots *buf, float *y1, float *z1, t_place *map)
{
	float	prev_y;
	float	prev_z;
	float	prev_y1;
	float	prev_z1;

	prev_y = buf->y;
	prev_z = map->dot.z;
	prev_y1 = *y1;
	prev_z1 = *z1;
	buf->y = prev_y * cos(map->angle_x) + prev_z * sin(map->angle_x);
	map->dot.z = -prev_y * sin(map->angle_x) + prev_z * cos(map->angle_x);
	*y1 = prev_y1 * cos(map->angle_x) + prev_z1 * sin(map->angle_x);
	*z1 = -prev_y1 * sin(map->angle_x) + prev_z1 * cos(map->angle_x);
}

void	y_rotation(t_dots *buf, float *x1, float *z1, t_place *map)
{
	float	prev_x;
	float	prev_z;
	float	prev_x1;
	float	prev_z1;

	prev_x = buf->x;
	prev_z = map->dot.z;
	prev_x1 = *x1;
	prev_z1 = *z1;
	buf->x = prev_x * cos(map->angle_y) + prev_z * sin(map->angle_y);
	map->dot.z = -prev_x * sin(map->angle_y) + prev_z * cos(map->angle_y);
	*x1 = prev_x1 * cos(map->angle_y) + prev_z1 * sin(map->angle_y);
	*z1 = -prev_x1 * sin(map->angle_y) + prev_z1 * cos(map->angle_y);
}

void	z_rotation(t_dots *buf, float *x1, float *y1, t_place *map)
{
	float	prev_x;
	float	prev_y;
	float	prev_x1;
	float	prev_y1;

	prev_x = buf->x;
	prev_y = buf->y;
	prev_x1 = *x1;
	prev_y1 = *y1;
	buf->x = prev_x * cos(map->angle_z) - prev_y * sin(map->angle_z);
	buf->y = prev_x * sin(map->angle_z) + prev_y * cos(map->angle_z);
	*x1 = prev_x1 * cos(map->angle_z) - prev_y1 * sin(map->angle_z);
	*y1 = prev_x1 * sin(map->angle_z) + prev_y1 * cos(map->angle_z);
}
