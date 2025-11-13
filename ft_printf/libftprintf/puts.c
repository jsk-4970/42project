/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyamada <jyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 21:55:49 by jyamada           #+#    #+#             */
/*   Updated: 2025/11/13 19:26:43 by jyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_c(int c)
{
	ft_putchar((char)c);
	return (1);
}

int	put_s(char *s)
{
	if (s == NULL)
	{
		ft_putstr("NULL");
	}
	ft_putstr(s);
	return (ft_strlen(s));
}

int	put_d(long d)
{
	int	digit;

	digit = 0;
	ft_putnbr(d);
	if (d < 0)
		digit++;
	if (d == 0)
	{
		ft_putnbr(0);
	}
	while (d)
	{
		d /= 10;
		digit++;
	}
	return (digit);
}

// int		put_d(unsigned long x)
//{
//
//}

int	put_x(unsigned long x, char c)
{
	char	base[17];
	char	arr[13];
	int		digit;
	int		i;

	if (c == 'x')
		ft_strlcpy(base, "0123456789abcdef", 17);
	else if (c == 'X')
		ft_strlcpy(base, "0123456789ABCDEF", 17);
	digit = 0;
	if (x == 0)
		ft_putchar('0');
	while (x > 0)
	{
		arr[digit] = base[x % 16];
		x /= 16;
		digit++;
	}
	arr[digit] = '\0';
	i = digit;
	while (i--)
		ft_putchar(arr[i]);
	return (digit + 1);
}

int	put_p(void *ptr)
{
	int	ret;

	ft_putstr("0X");
	ret = put_x((uintptr_t)ptr, 'x');
	return (ret + 2);
}

// int main(void)
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
//    int x = put_x(111111111, 'x');
//    write(1, "\n", 1);
//    ft_putnbr(x);
//	write(1, "\n", 1);
//    int p = put_p(&c);
//    write(1, "\n", 1);
//    ft_putnbr(p);
//}
