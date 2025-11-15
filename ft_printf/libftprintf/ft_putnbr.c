/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyamada <jyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:19:41 by jyamada           #+#    #+#             */
/*   Updated: 2025/11/15 19:27:23 by jyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(size_t n)
{
	long	longn;

	longn = (long)n;
	if (longn < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		longn = -longn;
	}
	if (longn >= 10)
		ft_putnbr(longn / 10);
	if (ft_putchar((longn % 10) + '0') == -1)
		return (-1);
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
