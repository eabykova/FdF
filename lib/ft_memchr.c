/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmicheli <micheli@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:29:21 by mmicheli          #+#    #+#             */
/*   Updated: 2021/10/24 14:47:01 by mmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*buf;
	size_t			i;

	buf = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (buf[i] == (unsigned char)c)
			return ((void *)(buf + i));
		i++;
	}
	return (NULL);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*buf1;
	const unsigned char	*buf2;
	size_t				i;

	buf1 = (unsigned char *)s1;
	buf2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)buf1[i] != (unsigned char)buf2[i])
			return ((unsigned char)buf1[i] - (unsigned char)buf2[i]);
		i++;
	}
	return (0);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*buf;

	if (!dst && !src)
		return (NULL);
	buf = dst;
	while (n > 0)
	{
		*(char *)buf = *(char *)src;
		buf++;
		src++;
		n--;
	}
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (!dst && !src)
		return (NULL);
	if (dst > src)
	{
		while (len-- > 0)
			((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}

void	*ft_memset(void *b, int c, size_t len)
{
	char	*buf;

	buf = (char *)b;
	while (len > 0)
	{
		buf[len - 1] = c;
		len--;
	}
	return (b);
}
