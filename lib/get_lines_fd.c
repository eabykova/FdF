/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lines_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmicheli <mmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:27:44 by mmicheli          #+#    #+#             */
/*   Updated: 2022/05/23 14:51:56 by mmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_chjoin(char *s1, char c)
{
	char	*tmp;
	long	i;

	i = -1;
	if (s1)
	{
		tmp = malloc(sizeof(char) * ft_strlen(s1) + 2);
		if (!tmp)
			ft_malloc_error(1);
		while (s1[++i])
			tmp[i] = s1[i];
		tmp[i] = c;
		tmp[i + 1] = '\0';
		free(s1);
	}
	else
	{
		tmp = malloc(sizeof(char) * 2);
		if (!tmp)
			ft_malloc_error(1);
		tmp[0] = c;
		tmp[1] = '\0';
	}
	return (tmp);
}

char	**get_lines_fd(int fd)
{
	char	c;
	char	*res;
	char	**string;

	res = NULL;
	string = NULL;
	if (fd >= 0)
	{
		while (read(fd, &c, 1))
			res = ft_chjoin(res, c);
		res = ft_chjoin(res, '\0');
		string = ft_split(res, '\n');
		free(res);
		if (!string)
			ft_malloc_error(1);
		return (string);
	}
	ft_kraft_error("Reading error\n", 1);
	return (NULL);
}
