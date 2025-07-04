/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clouden <clouden@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:55:10 by clouden           #+#    #+#             */
/*   Updated: 2025/07/03 13:22:59 by clouden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include "libft/libft.h"

int	ft_printf(const char *fmt, ...);
int	ft_putunbr_fd(unsigned int n, int fd);
int	ft_putstr_fd(const char *s, int fd);
int	ft_puthex_fd(unsigned long long n, int fd, char mode);
int	ft_putaddrhex_fd(unsigned long long n, int fd);

#endif
