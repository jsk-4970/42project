/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyamada <jyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:08:31 by jyamada           #+#    #+#             */
/*   Updated: 2025/11/14 21:39:27 by aburi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int	ft_check(char c)
//{
//	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
//		|| c == 'u' || c == 'x' || c == 'X' || c == '%')
//		return (1);
//	return (0);
//}

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
		return (put_u((unsigned long)va_arg(args, int)));
	else if (*format == 'x')
		return (put_x(va_arg(args, int), 'x'));
	else if (*format == 'X')
		return (put_x(va_arg(args, int), 'X'));
	else if (*format == '%')
		return (ft_putchar('%'), 1);
	else
		format++;
	return (1);
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
int main(void)
{
//	printf("printf: %c %c %c \n", '0', 0, '1');
//	ft_printf("ft_printf: %c %c %c \n", '0', 0, '1');
	printf("printf: %s %s \n", "", "-");
	ft_printf("ft_printf: %s %s \n", "", "-");
	printf("printf: %p ", -1);
	ft_printf("printf: %p ", -1);

//	printf("printf:%s\n", NULL);
//	ft_printf("ft_printf:%s\n", NULL);
//	printf("printf:%p\n", (void *)-1);
//	ft_printf("ft_printf:%p\n", -1);
//	printf("printf:%d\n", INT_MIN);
//	ft_printf("ft_printf:%d\n", INT_MIN);

}
