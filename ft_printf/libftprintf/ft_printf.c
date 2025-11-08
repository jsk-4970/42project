/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyamada <jyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:08:31 by jyamada           #+#    #+#             */
/*   Updated: 2025/11/08 10:28:25 by aburi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

void    ft_convert(const char *format, int count)
{

}

int		ft_printf(const char *format, ...)
{
	va_list		args;
    int         count;

	va_start	(args, format);
    count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
            ft_convert(format, count);
		}
		else
		{
			ft_putchar_fd(*format, 2);
            count++;
		}
	}
    return (count);
}
