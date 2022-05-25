/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmicheli <mmicheli@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:12:21 by mmicheli          #+#    #+#             */
/*   Updated: 2022/05/09 17:38:40 by mmicheli         ###   ########.fr       */
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
