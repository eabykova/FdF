/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_discover1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmicheli <mmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:04:37 by mmicheli          #+#    #+#             */
/*   Updated: 2022/05/16 20:09:36 by mmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

void	rotations(int key, t_place *map)
{
	if (key == 0)
		map->angle_x -= 0.05;
	if (key == 1)
		map->angle_x += 0.05;
	if (key == 2)
		map->angle_y -= 0.05;
	if (key == 3)
		map->angle_y += 0.05;
	if (key == 6)
		map->angle_z -= 0.05;
	if (key == 7)
		map->angle_z += 0.05;
}

void	iso_parallel(int key, t_place *map)
{
	if (key == 34)
	{
		map->angle = 0.5;
		map->angle_x = 0;
		map->angle_y = 0;
		map->angle_z = -M_PI / 2;
	}
	if (key == 35)
	{
		map->angle = 0;
		map->angle_x = 0;
		map->angle_y = 0;
		map->angle_z = 0;
	}
}
