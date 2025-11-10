/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyamada <jyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 21:55:49 by jyamada           #+#    #+#             */
/*   Updated: 2025/11/09 21:33:57 by aburi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		put_c(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int		put_s(char *s)
{
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}

//int		put_p()
//{}

int		put_d(long d)
{
	int		digit;

	digit = 0;
	ft_putnbr_fd(d, 1);
	while (d)
	{
		d /= 10;
		digit++;
	}
	return (digit);
}

int     put_u(unsigned long u)
{
    int
}

int main(void)
{
	int c = put_c('a', 1);
	ft_putnbr_fd(c, 1);
	write(1, "\n", 1);
	int s = put_s("hello", 5);
	ft_putnbr_fd(s, 1);
	write(1, "\n", 1);
	int d = put_d(1234, 4);
	ft_putnbr_fd(d, 1);
}
