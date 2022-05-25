/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmicheli <mmicheli@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 13:19:12 by mmicheli          #+#    #+#             */
/*   Updated: 2021/10/24 17:00:25 by mmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		((char *)s)[i++] = 0;
}

int	ft_wordcount(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s && *s != c)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static char	**ft_elemfree(char **arr, int size)
{
	while (size--)
		free(arr[size]);
	free(*arr);
	return (NULL);
}

static char	*ft_printword(char const *s, char c)
{
	int		i;
	char	*str;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	str = malloc(sizeof(char) * i + 1);
	if (str)
	{
		ft_strlcpy(str, s, i + 1);
		return (str);
	}
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;
	int		strl;

	if (s)
	{
		strl = ft_wordcount(s, c);
		arr = malloc(sizeof(char *) * (strl + 1));
		if (arr)
		{
			i = -1;
			while (++i < strl)
			{
				while (s[0] == c)
					s++;
				arr[i] = ft_printword(s, c);
				if (!arr[i])
					ft_elemfree(arr, i);
				s = s + ft_strlen(arr[i]);
			}
			arr[i] = 0;
			return (arr);
		}
	}
	return (NULL);
}
