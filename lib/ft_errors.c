/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmicheli <mmicheli@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:02:24 by mmicheli          #+#    #+#             */
/*   Updated: 2022/04/20 14:02:25 by mmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_exit(int exit_code)
{
	exit(exit_code);
}

void	ft_error(int stream_code, int exit_code)
{
	write(stream_code, "Error\n", 6);
	exit(exit_code);
}

void	ft_malloc_error(int exit_code)
{
	ft_printf("Malloc error\n");
	exit(exit_code);
}

void	ft_kraft_error(char *message, int exit_code)
{
	ft_printf("%s\n", message);
	exit(exit_code);
}
