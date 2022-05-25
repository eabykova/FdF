/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmicheli <micheli@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:16:48 by mmicheli          #+#    #+#             */
/*   Updated: 2021/10/24 17:09:41 by mmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *) s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char	*dest;
	char	*tmp;
	int		len;
	int		i;

	len = ft_strlen(s1);
	dest = malloc(sizeof(char) * len + 1);
	tmp = dest;
	i = 0;
	if (tmp)
	{
		while (s1[i])
		{
			tmp[i] = s1[i];
			i++;
		}
		tmp[i] = '\0';
		return (dest);
	}
	return (NULL);
}

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	ds;
	size_t	ss;

	ds = 0;
	ss = 0;
	while (dst[ds] && ds < dstsize)
		ds++;
	while ((src[ss]) && ((ds + ss + 1) < dstsize))
	{
		dst[ds + ss] = src[ss];
		ss++;
	}
	if (ds != dstsize)
		dst[ds + ss] = '\0';
	return (ds + ft_strlen(src));
}
