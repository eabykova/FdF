/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmicheli <mmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 13:52:43 by mmicheli          #+#    #+#             */
/*   Updated: 2022/05/19 17:54:37 by mmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf_bonus.h"

int	main(int argc, char **argv)
{
	t_place	*map;

	if (argc == 2)
	{
		map = (t_place *)malloc(sizeof(t_place));
		if (!map)
			ft_malloc_error(1);
		read_map(argv[1], map);
		start_window(map);
		free(map);
	}
	ft_printf("Wrong number of arguments!\n");
}
