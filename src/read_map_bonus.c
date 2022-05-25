/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmicheli <mmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 18:33:22 by mmicheli          #+#    #+#             */
/*   Updated: 2022/05/16 16:42:26 by mmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

static int	get_map_width(char *file_name)
{
	int		fd;
	int		count;
	char	*line;

	count = 0;
	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	if (line)
	{
		count = ft_wordcount(line, ' ');
		free(line);
		close(fd);
	}
	return (count);
}

static int	get_map_height(char *file_name)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(file_name, O_RDONLY);
	count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			free(line);
			break ;
		}
		count++;
		free(line);
	}
	close(fd);
	return (count);
}

static void	get_nums(t_fdf *coord, char *line)
{
	char	**arrnum;
	char	**num_color;
	int		i;

	arrnum = ft_split(line, ' ');
	i = 0;
	while (arrnum[i])
	{
		num_color = ft_split(arrnum[i], ',');
		coord[i].d_height = ft_atoi(num_color[0]);
		coord[i].f_color = 0;
		if (num_color[1])
		{
			coord[i].f_color = ft_htoi(num_color[1]);
			coord[i].c_flag = 1;
		}
		free(num_color[1]);
		free(num_color[0]);
		free(num_color);
		free(arrnum[i]);
		i++;
	}
	free(arrnum);
}

void	make_place_for_map(t_place *map)
{
	int	i;

	map->coord = (t_fdf **)malloc(sizeof(t_fdf *) * (map->height + 1));
	if (!map->coord)
		ft_malloc_error(1);
	i = -1;
	while (++i <= map->height)
		map->coord[i] = (t_fdf *)malloc(sizeof(t_fdf) * map->width + 1);
	if (!map->coord[--i])
		ft_malloc_error(1);
}

void	read_map(char *file_name, t_place *map)
{
	int		fd;
	int		i;
	char	*line;

	map->height = get_map_height(file_name);
	map->width = get_map_width(file_name);
	if (!map->height && !map->width)
		map_error();
	make_place_for_map(map);
	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
		fd_error(map);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		get_nums(map->coord[i++], line);
		free(line);
	}
	free(line);
	close(fd);
}
