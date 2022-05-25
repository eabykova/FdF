/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_i_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmicheli <mmicheli@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 17:33:03 by mmicheli          #+#    #+#             */
/*   Updated: 2021/12/22 17:33:49 by mmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_putnbr_counter(long int i)
{
	static long int	count;

	count = 0;
	if (i < 0)
	{
		ft_putchar_counter('-');
		ft_putnbr_counter(i * -1);
		count++;
	}
	else
	{
		if (i >= 10)
		{
			count++;
			ft_putnbr_counter(i / 10);
		}
		ft_putchar_counter((i % 10) + '0');
		count++;
	}
	return (count);
}

int	ft_spec_i_d(va_list args, int i)
{
	int	count;

	count = 0;
	i = va_arg(args, int);
	count += ft_putnbr_counter(i);
	return (count);
}
