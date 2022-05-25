/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmicheli <mmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 14:54:40 by mmicheli          #+#    #+#             */
/*   Updated: 2022/05/11 15:04:50 by mmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_chr(const char *s, int c)
{
	int	i;

	i = -1;
	while (s[++i])
		if (s[i] == (char)c)
			return (i);
	if (s[i] == (char)c)
		return (i);
	return (-1);
}

static size_t	ft_strlen_base(const char *str, int *f)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 97 && str[i] <= 102)
			*f = 1;
		i++;
	}
	return (i);
}

unsigned int	ft_htoi(const char *str)
{
	int				i;
	int				a;
	int				len;
	unsigned int	res;
	char			*base;

	i = 2;
	res = 0;
	a = 0;
	base = "0123456789ABCDEF";
	len = ft_strlen_base(&str[i], &a);
	if (a)
		base = "0123456789abcdef";
	a = find_chr(base, str[i]);
	if (a != -1)
	{
		while (len--)
		{
			a = find_chr(base, str[i++]);
			res += pow(16, len) * a;
		}
	}
	return (res);
}
