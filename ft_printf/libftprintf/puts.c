/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyamada <jyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 21:55:49 by jyamada           #+#    #+#             */
/*   Updated: 2025/11/11 21:02:55 by aburi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		put_c(int c)
{
	ft_putchar((char)c);
	return (1);
}

int		put_s(char *s)
{
    if (s == NULL)
        ft_putstr("NULL");
	ft_putstr(s);
	return (ft_strlen(s));
}

//int		put_p()
//{}

int		put_d(long d)
{
	int		digit;

	digit = 0;
	ft_putnbr(d);
	if (d < 0)
		digit++;
    if (d == 0)
        ft_putnbr(0);
	while (d)
	{
		d /= 10;
		digit++;
	}
	return (digit);
}

int     put_x(unsigned long x, char c)
{
    char    base[16];
    char    *ret;
    int     digit;
    
    if (c == 'x')
        ft_strlcpy(base, "0123456789abcdef", 17);
    else if (c == 'X')
        ft_strlcpy(base, "0123456789ABCDEF", 17);
    digit = 0; 
    if (x > 16)
        put_x(x / 16, c);
    put_x(x, c);
    return (digit);
}

int main(void)
{
	int c = put_c('a');
	write(1, "\n", 1);
	ft_putnbr(c);
	write(1, "\n", 1);
	int s = put_s("hello");
	write(1, "\n", 1);
	ft_putnbr(s);
	write(1, "\n", 1);
	int d = put_d(-1234);
	write(1, "\n", 1);
	ft_putnbr(d);
    int x = put_x(1234, 'x');
    write(1, "\n", 1);
    ft_putnbr(x);
}
