/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmicheli <mmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:00:20 by mmicheli          #+#    #+#             */
/*   Updated: 2022/05/12 16:01:41 by mmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	map_error(void)
{
	ft_printf("Map error. Try another.\n");
	ft_exit(0);
}

void	fd_error(t_place *map)
{
	free(map->coord);
	free(map);
	ft_exit(1);
}
