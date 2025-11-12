/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyamada <jyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:19:41 by jyamada           #+#    #+#             */
/*   Updated: 2025/11/09 21:41:32 by aburi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr(int n)
{
	long	longn;

	longn = (long)n;
	if (longn < 0)
	{
		ft_putchar('-');
		longn = -longn;
	}
	if (longn >= 10)
		ft_putnbr(longn / 10);
	ft_putchar((longn % 10) + '0');
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
