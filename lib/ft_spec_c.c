/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmicheli <mmicheli@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:12:21 by mmicheli          #+#    #+#             */
/*   Updated: 2021/12/22 17:33:48 by mmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar_counter(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_spec_c(va_list args, char ch)
{
	int	count;

	count = 0;
	ch = va_arg(args, int);
	count += ft_putchar_counter(ch);
	return (count);
}
