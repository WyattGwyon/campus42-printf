/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clouden <clouden@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 14:57:26 by clouden           #+#    #+#             */
/*   Updated: 2025/07/03 14:57:31 by clouden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr_fd(unsigned int n, int fd)
{
	int	bytes;

	bytes = 0;
	if (n >= 10)
		bytes += ft_putunbr_fd(n / 10, fd);
	bytes += ft_putchar_fd(n % 10 + '0', fd);
	return (bytes);
}

int	ft_puthex_fd(unsigned long long n, int fd, char mode)
{
	int bytes;
	char *x;
	char *X;
	int r;

	bytes = 0;
	x = "0123456789abcdef";
	X = "0123456789ABCDEF";
	if (n >= 16)
		bytes += ft_puthex_fd(n / 16, fd, mode);
	r = n % 16;
	if (mode == 'x' || mode == 'p')
		bytes += ft_putchar_fd(x[r],fd);
	if (mode == 'X')
		bytes += ft_putchar_fd(X[r],fd);
	return (bytes);
}


int	ft_putaddrhex_fd(unsigned long long n, int fd)
{
	int bytes;
	int r;	
	
    bytes = 0;
	if (n >= 16)
		bytes += ft_putaddrhex_fd(n / 16, fd);
	r = n % 16;
	if (r == 10)
		bytes += ft_putchar_fd('a', fd);
	if (r == 11)
		bytes += ft_putchar_fd('b', fd);
	if (r == 12)
		bytes += ft_putchar_fd('c', fd);
	if (r == 13)
		bytes += ft_putchar_fd('d', fd);
	if (r == 14)
		bytes += ft_putchar_fd('e', fd);
	if (r == 15)
		bytes += ft_putchar_fd('f', fd);
	if (r < 10)
		bytes += ft_putchar_fd(r + '0', fd);
	return (bytes);
}
