/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmicheli <mmicheli@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 17:33:14 by mmicheli          #+#    #+#             */
/*   Updated: 2021/12/22 17:33:49 by mmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_spec_p(va_list args, unsigned long int i)
{
	char	count;

	count = 0;
	i = va_arg(args, unsigned long int);
	if (!i)
	{
		count += ft_putstr_counter("0x");
		count += ft_putnbr_counter(0);
		return (count);
	}
	count += ft_putstr_counter("0x");
	count += ft_convert_hex_dwn(i);
	return (count);
}
