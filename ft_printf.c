/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clouden <clouden@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:54:33 by clouden           #+#    #+#             */
/*   Updated: 2025/07/01 22:05:43 by clouden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
static ft_fmtdet(char *new, va_list args)
{
	const char		*str;
	char			*old;
	int				c;
	unsigned int	u;
	
}
*/
int	ft_printf(const char *fmt, ...)
{
	va_list			args;
	const char		*str;
	char			*new;
	char			*old;
	int				d;
	int				c;
	unsigned int	u;
	
	new = ft_strchr(fmt, '%');
	va_start(args, fmt);
	write(1, fmt, new - fmt);	
	while (new)
	{
		new++;	
		if (*new == 's')
		{
			str = va_arg(args, const char *);
			write(1, str, ft_strlen(str));
		}
		if (*new == 'd' || *new == 'i')
		{
			d = va_arg(args, int);
			ft_putnbr_fd(d, 1);
		}
		if (*new == 'c')
		{
			c = va_arg(args, int);
			write(1, &c, 1);
		}
		if (*new == 'u')
		{
			u = va_arg(args, unsigned int);
			ft_putnbr_fd(u, 1);
		}
		if (*new == '%')
			write(1,"%", 1);
		new++;
		old = new;
		new = ft_strchr(new, '%');
		if (new)
			write(1, old, new - old);
		else
			write(1, old, ft_strlen(old));
	}
	
	va_end(args);
	return (0);
}
