/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmicheli <micheli@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 13:12:29 by mmicheli          #+#    #+#             */
/*   Updated: 2021/10/24 16:27:01 by mmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	char	*buf;
	int		l;

	if (s1 && s2)
	{
		l = ft_strlen(s1) + ft_strlen(s2);
		res = malloc(sizeof(char) * l + 1);
		buf = res;
		if (buf)
		{
			while (*s1)
				*buf++ = *s1++;
			while (*s2)
				*buf++ = *s2++;
			*buf = '\0';
			return (res);
		}
	}
	return (NULL);
}

char	*ft_char_join(char *s1, char ch)
{
	char	*tmp;
	long	i;

	i = -1;
	if (s1)
	{
		tmp = malloc(sizeof(char) * ((ft_strlen(s1) + 2)));
		if (!tmp)
			ft_error(2, 1);
		while (s1[++i])
			tmp[i] = s1[i];
		tmp[i] = ch;
		tmp[i + 1] = '\0';
		free (s1);
	}
	else
	{
		tmp = malloc(sizeof(char) * 2);
		if (!tmp)
			ft_error(2, 1);
		tmp[0] = ch;
		tmp[1] = '\0';
	}
	return (tmp);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;
	char	*buf;

	i = 0;
	buf = (char *)src;
	len = ft_strlen(buf);
	if (!dstsize)
		return (len);
	while (buf[i] && i < dstsize - 1)
	{
		dst[i] = buf[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}
