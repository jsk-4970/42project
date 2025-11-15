/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyamada <jyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 21:55:49 by jyamada           #+#    #+#             */
/*   Updated: 2025/11/15 20:19:22 by jyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_d(long d)
{
	int	digit;

	digit = 0;
	if (ft_putnbr(d) == -1)
		return (-1);
	if (d < 0)
	{
		digit++;
		d = -d;
	}
	if (d == 0)
		return (1);
	while (d)
	{
		d /= 10;
		digit++;
	}
	return (digit);
}

int	put_u(unsigned long u)
{
	int	digit;

	digit = 0;
	if (ft_putnbr(u) == -1)
		return (-1);
	if (u == 0)
		return (1);
	while (u)
	{
		u /= 10;
		digit++;
	}
	return (digit);
}

int	put_x(unsigned long x, char c)
{
	char	base[17];
	char	arr[19];
	int		digit;
	int		i;

	if (c == 'x')
		ft_strlcpy(base, "0123456789abcdef", 17);
	if (c == 'X')
		ft_strlcpy(base, "0123456789ABCDEF", 17);
	digit = 0;
	if (x == 0)
		return (ft_putchar('0'), 1);
	while (x > 0)
	{
		arr[digit] = base[x % 16];
		x /= 16;
		digit++;
	}
	arr[digit] = '\0';
	i = digit;
	while (i--)
	{
		if (ft_putchar(arr[i]) == -1)
			return (-1);
	}
	return (digit);
}

int	put_p(uintptr_t ptr)
{
	int	ret;

	if (ptr == 0)
	{
		if (ft_putstr("(nil)") == -1)
			return (-1);
		return (5);
	}
	if (ft_putstr("0x") == -1)
		return (-1);
	ret = put_x((uintptr_t)ptr, 'x');
	if (ret == -1)
		return (-1);
	return (ret + 2);
}

//#include <stdio.h>
//
//int main(void)
//{
//	int c = put_c('a');
//	write(1, "\n", 1);
//	ft_putnbr(c);
//	write(1, "\n", 1);
//	int s = put_s("hello");
//	write(1, "\n", 1);
//	ft_putnbr(s);
//	write(1, "\n", 1);
//	int d = put_d(-1234);
//	write(1, "\n", 1);
//	ft_putnbr(d);
//	write(1, "\n", 1);
//    int x = put_x(16, 'x');
//    write(1, "\n", 1);
//    ft_putnbr(x);
//	write(1, "\n", 1);
//    int p = put_p(&c);
//    write(1, "\n", 1);
//    ft_putnbr(p);
//	printf(" %u ", -1);
//}
