/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mod.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmicheli <mmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 17:11:09 by mmicheli          #+#    #+#             */
/*   Updated: 2022/04/30 17:45:48 by mmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_mod(float i)
{
	if (i < 0)
		i *= -1;
	return (i);
}

float	ft_max_i(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

float	ft_min_i(float a, float b)
{
	if (a < b)
		return (a);
	else
		return (b);
}
