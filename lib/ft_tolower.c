/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmicheli <micheli@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 10:41:17 by mmicheli          #+#    #+#             */
/*   Updated: 2021/10/24 14:47:01 by mmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return ((int)c);
}

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return ((int)c);
}

void	*ft_calloc(size_t arr, size_t size)
{
	void	*dst;

	dst = malloc(arr * size);
	if (!dst)
		return (NULL);
	ft_bzero(dst, (arr * size));
	return (dst);
}
