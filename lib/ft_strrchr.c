/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmicheli <mmicheli@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:25:39 by mmicheli          #+#    #+#             */
/*   Updated: 2021/10/24 14:47:01 by mmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *) &s[i]);
		i--;
	}
	return (NULL);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		fn;

	if (s1 && set)
	{
		while (*s1 && ft_strchr(set, *s1))
			s1++;
		fn = ft_strlen(s1);
		while (fn > 0 && ft_strchr(set, s1[fn]))
			fn--;
		res = ft_substr((char *)s1, 0, fn + 1);
		return (res);
	}
	return (NULL);
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
