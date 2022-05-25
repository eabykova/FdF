/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmicheli <mmicheli@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:30:33 by mmicheli          #+#    #+#             */
/*   Updated: 2021/10/24 16:25:14 by mmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}

void	ft_putendl_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return ;
	while (*s)
		ft_putchar_fd(*s++, fd);
	write(fd, "\n", 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	char			c;
	unsigned int	i;

	if (fd < 0)
		return ;
	i = n;
	if (n < 0)
	{
		write(fd, "-", 1);
		i = -n;
	}
	if (i / 10)
		ft_putnbr_fd((i / 10), fd);
	c = i % 10 + '0';
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return ;
	while (*s)
		ft_putchar_fd(*s++, fd);
}
