/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmicheli <mmicheli@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 17:33:34 by mmicheli          #+#    #+#             */
/*   Updated: 2021/12/22 17:33:52 by mmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_convert_uint(int i)
{
	unsigned int	max_uint;
	int				count;

	count = 0;
	max_uint = 4294967295;
	if (i < 0)
	{
		i *= -1;
		max_uint = max_uint - i + 1;
		count += ft_putnbr_counter(max_uint);
	}
	else
		count += ft_putnbr_counter(i);
	return (count);
}

int	ft_spec_u(va_list args, unsigned int i)
{
	int	count;

	count = 0;
	i = va_arg(args, unsigned int);
	count += ft_convert_uint(i);
	return (count);
}
