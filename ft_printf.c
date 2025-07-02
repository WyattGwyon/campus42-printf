/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clouden <clouden@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:54:33 by clouden           #+#    #+#             */
/*   Updated: 2025/07/02 20:27:19 by clouden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putunbr_fd(unsigned int n, int fd)
{
	int	bytes;

	bytes = 0;
	if (n < 0)
	{
		bytes += ft_putchar_fd('-', fd);
		n = n * -1;
	}
	if (n >= 10)
		bytes += ft_putunbr_fd(n / 10, fd);
	bytes += ft_putchar_fd(n % 10 + '0', fd);
	return (bytes);
}
/*
static int ft_fmthex(char *new, va_list args)
{
	
}
*/
static int ft_mapfmt(char *new, va_list args)
{
	const char		*s;
	int				c;
	unsigned int	u;
	int 			bytes;
	
	bytes = 0;
	if (*new == 's')
	{
		s = va_arg(args, const char *);
		bytes += write(1, s, ft_strlen(s));
	}
	if (*new == 'd' || *new == 'i')
	{
		c = va_arg(args, int);
		bytes += ft_putnbr_fd(c, 1);
	}
	if (*new == 'c')
	{
		c = va_arg(args, int);
		bytes += write(1, &c, 1);
	}
	if (*new == 'u')
	{
		u = va_arg(args, unsigned int);
		bytes += ft_putunbr_fd(u, 1);
	}
	if (*new == '%')
		bytes += write(1,"%", 1);
	return (bytes);
}

static int ft_read_splits(char *new, va_list args)
{
	char	*old;
	int		bytes;
	
	bytes = 0;
	while (new)
	{
		new++;
		bytes += ft_mapfmt(new, args);	
		new++;
		old = new;
		new = ft_strchr(new, '%');
		if (new)
			bytes += write(1, old, new - old);
		else
			bytes += write(1, old, ft_strlen(old));
	}
	return (bytes);
}

int	ft_printf(const char *fmt, ...)
{
	va_list			args;
	char			*new;
	ssize_t				bytes;	

	new = ft_strchr(fmt, '%');
	va_start(args, fmt);
	write(1, fmt, new - fmt);	
	bytes = ft_read_splits(new, args);	
	va_end(args);
	return (bytes);
}
