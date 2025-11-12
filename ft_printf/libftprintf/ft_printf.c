/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyamada <jyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:08:31 by jyamada           #+#    #+#             */
/*   Updated: 2025/11/12 17:10:56 by aburi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libftprintf.h"

int    ft_read_next(const char *format, va_list args)
{
	if (*format == 'c')
		return (put_c(va_arg(args, int)));
    else if (*format == 's')
        return (put_s(va_arg(args, char *)));
//    if (*format == 'p')
//        return (put_p(va_arg(args, void*)));
    else if (*format == 'd')
        return (put_d(va_arg(args, int)));
    else if (*format == 'i')
        return (put_d(va_arg(args, int)));
//    else if (*format == 'u')
//        return (put_u(va_arg(args, int)));
//    else if (*format == 'x')
//        return (put_x(va_arg(args, int), 'x'));
//    else if (*format == 'X')
//        return (put_x(va_arg(args, int), 'X'));
    else if (*format == '%')
        return (ft_putchar('%'), 1);
    return (0);
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
            count += ft_read_next(format, args);
		}
		else
		{
			ft_putchar(*format);
            count++;
		}
        format++;
	}
    va_end(args);
    return (count);
}

int main(void)
{
    ft_putnbr(ft_printf("%s %d\n", "hello", 2));
}
