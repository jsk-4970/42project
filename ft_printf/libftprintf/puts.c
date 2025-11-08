/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyamada <jyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 21:55:49 by jyamada           #+#    #+#             */
/*   Updated: 2025/11/08 22:25:19 by jyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		put_c(int c, int count)
{
	ft_putchar_fd(c, 1);
	return (count + 1);
}

int		put_s(char *s, int count)
{
	ft_putstr_fd(s, 1);
	return (count + ft_strlen(s));
}

//int		put_p()
//{}

int		put_d(int d, int count)
{
	int		digit;

	digit = 0;
	ft_putnbr_fd(d, 1);
	while (d)
	{
		d /= 10;
		digit++;
	}
	return (count + digit);
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
