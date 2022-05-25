/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmicheli <micheli@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 13:46:53 by mmicheli          #+#    #+#             */
/*   Updated: 2022/05/11 14:54:15 by mmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int i)
{
	int	res;

	res = 0;
	if (i < 0)
		res++;
	while (i / 10)
	{
		i /= 10;
		res++;
	}
	return (++res);
}

char	*ft_itoa(int n)
{
	char			*num;
	int				i;
	unsigned int	j;

	i = ft_numlen(n);
	num = malloc(sizeof(char) * i + 1);
	if (num)
	{
		num[i--] = '\0';
		j = n;
		if (n == 0)
			num[0] = '0';
		if (n < 0)
		{
			num[0] = '-';
			j = -n;
		}
		while (j > 0)
		{
			num[i] = j % 10 + '0';
			j /= 10;
			i--;
		}
	}
	return (num);
}

int	ft_atoi(const char *str)
{
	unsigned int	val;
	unsigned long	i;
	unsigned long	sign;

	val = 0;
	i = 0;
	sign = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		val *= 10;
		val += (str[i] - '0');
		i++;
	}
	return ((int)val * sign);
}
