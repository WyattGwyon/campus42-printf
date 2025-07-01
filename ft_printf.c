/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clouden <clouden@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:54:33 by clouden           #+#    #+#             */
/*   Updated: 2025/07/01 16:11:10 by clouden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list		args;
	const char	*str;
	char		*c;
	int			d;

	c = ft_strchr(fmt, '%');
	va_start(args, fmt);
	while (c)
	{
		if (c[1] == 's')
		{
			str = va_arg(args, const char *);
			write(1, str, ft_strlen(str));
		}
		if (c[1] == 'd')
		{
			d = va_arg(args, int);
			ft_putnbr_fd(d, 1);
		}
		c = ft_strchr(c + 1, '%');
	}
/*
	str = va_arg(args, const char *);
	write(1, str, ft_strlen(str));
	str = va_arg(args, const char *);
	write(1, str, ft_strlen(str));
*/
	va_end(args);
	return (0);
}
