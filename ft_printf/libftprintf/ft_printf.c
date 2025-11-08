/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyamada <jyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:08:31 by jyamada           #+#    #+#             */
/*   Updated: 2025/11/08 21:59:53 by jyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

int    ft_read_next(const char *format, int count)
{
	if (*format == c)
		put_c(va_arg(ap, int), count);
	return (count);
}

int		ft_printf(const char *format, ...)
{
	va_list		args;
    int         count;

	va_start(args, format);
    count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
            count = ft_read_next(format, count);
		}
		else
		{
			ft_putchar_fd(*format, 2);
            count++;
		}
	}
    return (count);
}
