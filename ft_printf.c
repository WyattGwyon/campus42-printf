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

int	ft_putchar_fd(char c, int fd)
{
	int	bytes;

	bytes = 0;
	bytes += write(fd, &c, 1);
	return (bytes);
}

int	ft_putstr_fd(const char *s, int fd)
{
	if (!s)
		return (ft_putstr_fd("(null)", 1));
	return (write(fd, s, ft_strlen(s)));
}

int	ft_putnbr_fd(int n, int fd)
{
	int	bytes;

	bytes = 0;
	if (n == -2147483648)
	{
		bytes += write(fd, "-2147483648", 11);
		return (bytes);
	}
	if (n < 0)
	{
		bytes += ft_putchar_fd('-', fd);
		n = n * -1;
	}
	if (n >= 10)
		bytes += ft_putnbr_fd(n / 10, fd);
	bytes += ft_putchar_fd(n % 10 + '0', fd);
	return (bytes);
}

static int	ft_mapfmt(char *new, va_list args)
{
	unsigned long long	ptr;

	if (*new == 's')
		return (ft_putstr_fd(va_arg(args, const char *), 1));
	if (*new == 'd' || *new == 'i')
		return (ft_putnbr_fd(va_arg(args, int), 1));
	if (*new == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	if (*new == 'u')
		return (ft_putunbr_fd(va_arg(args, unsigned int), 1));
	if (*new == '%')
		return (ft_putchar_fd('%', 1));
	if (*new == 'x' || *new == 'X')
	{
		ptr = (unsigned long long)va_arg(args, unsigned int);
		return (ft_puthex_fd(ptr, 1, *new));
	}
	if (*new == 'p')
		return (ft_putptr_fd(va_arg(args, void *), 1));
	return (0);
}

int	ft_printf(const char *fmt, ...)
{
	va_list			args;
	char			*new;
	char			*old;
	ssize_t			bytes;	

	new = ft_strchr(fmt, '%');
	if (!new)
		return (va_end(args), write(1, fmt, ft_strlen(fmt)));
	va_start(args, fmt);
	bytes = write(1, fmt, new - fmt);
	while (new)
	{
		bytes += ft_mapfmt(++new, args);
		old = ++new;
		new = ft_strchr(new, '%');
		if (new)
			bytes += write(1, old, new - old);
		else
			bytes += write(1, old, ft_strlen(old));
	}
	return (va_end(args), bytes);
}
