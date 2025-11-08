/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyamada <jyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:19:41 by jyamada           #+#    #+#             */
/*   Updated: 2025/11/08 22:21:27 by jyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	long	longn;

	longn = (long)n;
	if (longn < 0)
	{
		ft_putchar_fd('-', fd);
		longn = -longn;
	}
	if (longn >= 10)
		ft_putnbr_fd(longn / 10, fd);
	ft_putchar_fd((longn % 10) + '0', fd);
}

//#include <stdio.h>
//
//int main(void)
//{
//	printf("ft_putnbr_fd(42, 1): ");
//	ft_putnbr_fd(42, 1);
//	printf("\n");
//
//	printf("ft_putnbr_fd(0, 1): ");
//	ft_putnbr_fd(0, 1);
//	printf("\n");
//
//	printf("ft_putnbr_fd(-42, 1): ");
//	ft_putnbr_fd(-42, 1);
//	printf("\n");
//
//	printf("ft_putnbr_fd(INT_MIN, 1): ");
//	ft_putnbr_fd(-2147483648, 1);
//	printf("\n");
//	return (0);
//}
