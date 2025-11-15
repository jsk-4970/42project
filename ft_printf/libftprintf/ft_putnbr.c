/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburi <aburi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:19:41 by jyamada           #+#    #+#             */
/*   Updated: 2025/11/16 00:39:40 by aburi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long n)
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
	{
		if (ft_putnbr(longn / 10) == -1)
			return (-1);
	}
	if (ft_putchar((longn % 10) + '0') == -1)
		return (-1);
	return (1);
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
