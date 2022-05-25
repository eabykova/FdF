/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmicheli <mmicheli@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:45:23 by mmicheli          #+#    #+#             */
/*   Updated: 2021/12/06 17:36:18 by mmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_specificator( const char *strin, va_list args)
{
	int	count;

	count = 0;
	if (*strin == 'c')
		count += ft_spec_c(args, *strin);
	else if (*strin == 's')
		count += ft_spec_s(args, (char *)strin);
	else if (*strin == 'i' || *strin == 'd')
		count += ft_spec_i_d(args, *strin);
	else if (*strin == 'u')
		count += ft_spec_u(args, *strin);
	else if (*strin == 'x')
		count += ft_spec_xs(args, *strin);
	else if (*strin == 'X')
		count += ft_spec_xl(args, *strin);
	else if (*strin == 'p')
		count += ft_spec_p(args, *strin);
	else if (*strin == '%')
		count += ft_putchar_counter('%');
	return (count);
}

int	ft_strparse(const char *strin, va_list args)
{
	int	count;

	count = 0;
	while (1)
	{
		if (!*strin)
			break ;
		else if (*strin == '%' && *strin++)
			count += ft_specificator(strin, args);
		else if (*strin != '%')
			count += ft_putchar_counter(*strin);
		strin++;
	}
	return (count);
}

int	ft_printf(const char *frm, ...)
{
	va_list	args;
	char	*str;
	int		count;

	count = 0;
	str = ft_strdup(frm);
	if (!str)
		return (-1);
	va_start(args, frm);
	count += ft_strparse((const char *)str, args);
	va_end(args);
	free((char *)str);
	return (count);
}
