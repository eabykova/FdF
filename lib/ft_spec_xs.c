/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_xs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmicheli <mmicheli@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 17:34:45 by mmicheli          #+#    #+#             */
/*   Updated: 2021/12/22 17:35:11 by mmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_convert_hex_dwn(unsigned long int decnum)
{
	unsigned long int	quot;
	unsigned long int	tmp;
	int					i;
	int					j;
	char				hexnum[19];

	i = 0;
	quot = decnum;
	while (quot != 0)
	{
		tmp = quot % 16;
		if (tmp < 10)
			tmp += 48;
		else
			tmp += 87;
		hexnum[i++] = tmp;
		quot /= 16;
	}
	j = i - 1;
	while (j >= 0)
		ft_putchar_counter(hexnum[j--]);
	return (i);
}

int	ft_spec_xs(va_list args, unsigned int i)
{
	int	count;

	count = 0;
	i = va_arg(args, unsigned int);
	if (!i)
	{
		count += ft_putnbr_counter(0);
		return (count);
	}
	count += ft_convert_hex_dwn((long int)i);
	return (count);
}
