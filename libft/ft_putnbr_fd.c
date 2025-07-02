/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clouden <clouden@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 23:13:47 by clouden           #+#    #+#             */
/*   Updated: 2025/07/02 20:28:55 by clouden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_putnbr_fd(int n, int fd)
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
/*
#include <stdio.h>

int main(void)
{
    int n = -214748368;

    ft_putnbr_fd(n, 1);
}
*/
