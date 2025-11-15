/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyamada <jyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:08:31 by jyamada           #+#    #+#             */
/*   Updated: 2025/11/15 20:10:48 by jyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_read_next(const char *format, va_list args)
{
	if (*format == 'c')
		return (put_c(va_arg(args, int)));
	else if (*format == 's')
		return (put_s(va_arg(args, char *)));
	else if (*format == 'p')
		return (put_p(va_arg(args, uintptr_t)));
	else if (*format == 'd')
		return (put_d(va_arg(args, int)));
	else if (*format == 'i')
		return (put_d(va_arg(args, int)));
	else if (*format == 'u')
		return (put_u(va_arg(args, unsigned int)));
	else if (*format == 'x')
		return (put_x(va_arg(args, unsigned int), 'x'));
	else if (*format == 'X')
		return (put_x(va_arg(args, unsigned int), 'X'));
	else if (*format == '%')
		return (ft_putchar('%'), 1);
	else
	{
		format++;
		return (1);
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (ft_get_read_next(format, args) == -1)
				return (-1);
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

#include <stdio.h>

 int	main(void)
 {
	int a = printf("+:%%%%%%%\n");
	int b = ft_printf("-:%%%%%%%\n");
////// 	int c = printf("+:%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%%%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 
//////42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
////// 	int d = ft_printf("-:%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%%%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 
//////42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
//
//	int	c = printf("+:%p\n",(void *)0);
//	int	d = ft_printf("-:%p\n", (void *)0);
//	printf("a = %d\nb = %d\nc = %d\nd = %d\n", a, b, c, d);
////// 	printf("printf: %p ", -1);
//////	ft_printf("printf: %p ", -1);
//////	printf("printf:%s\n", NULL);
//////	ft_printf("+:%s\n", NULL);
////	printf("+:%p\n",(void *)-1);
////	ft_printf("-:%p\n",(void *)-1);
////	printf("+:%d\n", INT_MIN);
////	ft_printf("-:%d\n", INT_MIN);
////	printf("+:%u\n", 0);
////	ft_printf("-:%u\n", 0);
////	printf("+:%x\n", 0);
////	ft_printf("-:%x\n", 0);
}
