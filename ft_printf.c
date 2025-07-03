/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clouden <clouden@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:54:33 by clouden           #+#    #+#             */
/*   Updated: 2025/07/03 12:54:50 by clouden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_mapfmt(char *new, va_list args)
{
	int	bytes;
	
	bytes = 0;
	if (*new == 's')
		bytes += ft_putstr_fd(va_arg(args, const char *), 1);
	if (*new == 'd' || *new == 'i')
		bytes += ft_putnbr_fd(va_arg(args, int), 1);
	if (*new == 'c')
		bytes += ft_putchar_fd(va_arg(args, int), 1);
	if (*new == 'u')
		bytes += ft_putunbr_fd(va_arg(args, unsigned int), 1);
	if (*new == '%')
		bytes += ft_putchar_fd('%', 1);
	if (*new == 'x')
		bytes += ft_puthex_fd(va_arg(args, unsigned int), 1);
	if (*new == 'X')
		bytes += ft_putupphex_fd(va_arg(args, unsigned int), 1);
	if (*new == 'p')
	{
		bytes += ft_putstr_fd("0x", 1);
		bytes += ft_putaddrhex_fd(va_arg(args, unsigned long), 1);
	}
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
	ssize_t			bytes;	

	new = ft_strchr(fmt, '%');
	va_start(args, fmt);
	write(1, fmt, new - fmt);	
	bytes = ft_read_splits(new, args);	
	va_end(args);
	return (bytes);
}
