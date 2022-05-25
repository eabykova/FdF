/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmicheli <micheli@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:33:45 by mmicheli          #+#    #+#             */
/*   Updated: 2022/05/18 15:18:51 by mmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_checkbuf(t_list **list, char *buf, int *place)
{
	int	st;

	st = *place;
	while (buf[*place])
	{
		if (buf[*place] == '\n')
		{
			*place += 1;
			ft_lstadd_back_ch(list, ft_substr(buf, st, ((*place) - st)));
			return (1);
		}
		*place += 1;
	}
	if (st != *place)
		ft_lstadd_back_ch(list, ft_substr(buf, st, ((*place) - st)));
	*place = 0;
	return (0);
}

char	*ft_strmaker(t_list **list)
{
	t_list	*buf;
	long	size;
	char	*output;

	size = ft_lstsize_gnl(*list);
	if (!size)
		return (NULL);
	output = malloc(sizeof(char) * (size + 1));
	if (!output)
		return (NULL);
	output[0] = '\0';
	if (*list)
	{
		while (*list)
		{
			buf = (*list)->next;
			output = ft_strcat(output, (*list)->content);
			free((*list)->content);
			free(*list);
			*list = buf;
		}
	}
	return (output);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	t_list		*list;
	static int	i;
	long		size;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	list = NULL;
	while (1)
	{
		if (i == 0)
		{
			size = read(fd, buf, BUFFER_SIZE);
			if (size <= 0)
				break ;
			buf[size] = '\0';
		}
		if (ft_checkbuf(&list, buf, &i))
			break ;
	}
	return (ft_strmaker(&list));
}
