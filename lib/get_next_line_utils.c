/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmicheli <micheli@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 12:15:49 by mmicheli          #+#    #+#             */
/*   Updated: 2022/05/09 17:38:40 by mmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, char *src)
{
	char	*buf;

	buf = dest;
	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (buf);
}

int	ft_lstsize_gnl(t_list *list)
{
	t_list	*buf;
	int		i;

	i = 0;
	buf = list;
	while (buf)
	{
		i += (int)(ft_strlen(buf->content));
		buf = buf->next;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;
	size_t			res;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
	{
		str = malloc(sizeof(char));
		if (!str)
			return (NULL);
		*str = '\0';
		return (str);
	}
	res = ft_strlen(s) - start;
	if (res < len)
		len = res;
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (len-- != 0)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

void	ft_lstadd_back_ch(t_list **lst, char *new)
{
	t_list	*buf;
	t_list	*tmp;

	buf = malloc(sizeof(t_list));
	if (!buf)
		return ;
	buf->content = new;
	buf->next = NULL;
	if (!(*lst))
		*lst = buf;
	else
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = buf;
	}
}
