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

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i ++;
	return (i);
}

int	ft_putstr_fd(const char *s, int fd)
{
	int	bytes;

	bytes = 0;
	bytes += write(fd, s, ft_strlen(s));
	return (bytes);
}

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


int	ft_putptr_fd(void *ptr, int fd)
{
	int bytes;

	bytes = 0;
	if (ptr == NULL)
	{
		bytes += ft_putstr_fd("(nil)", fd);
		return (bytes);
	}
	bytes += ft_putstr_fd("0x", fd);
	bytes += ft_puthex_fd((uintptr_t)ptr, fd, 'x');
	return (bytes);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (*s == '\0')
			return ((char *)0);
		else
			s++;
	}
	return ((char *)s);
}
