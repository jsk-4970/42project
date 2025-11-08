/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyamada <jyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 20:55:24 by jyamada           #+#    #+#             */
/*   Updated: 2025/10/31 21:36:44 by jyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

int	ft_isspace(int c)
{
	if (c == '\f' || c == '\n' || c == '\r' || c == '\t' || c == '\v'
		|| c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	size_t	res;
	int		len;
	int		i;
	size_t	sign;

	len = ft_strlen(nptr);
	res = 0;
	i = 0;
	sign = 1;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (i < len && ft_isdigit(nptr[i]) == 1)
	{
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	return ((int)res * sign);
}

//#include <stdio.h>
//#include <stdlib.h>
//
// int main(void)
//{
//
//	printf("ft_atoi(\"1\") = %d (expected: 1)\n", ft_atoi("1"));
//	printf("ft_atoi(\"-42\") = %d (expected: -42)\n", ft_atoi("-42"));
//	printf("ft_atoi(\"42\") = %d (expected: 42)\n", ft_atoi("42"));
//	printf("ft_atoi(\"-42\") = %d (expected: -42)\n", ft_atoi("-42"));
//	printf("ft_atoi(\"+42\") = %d (expected: 42)\n", ft_atoi("+42"));
//	printf("ft_atoi(\"   123\") = %d (expected: 123)\n", ft_atoi("   123"));
//	printf("ft_atoi(\"0\") = %d (expected: 0)\n", ft_atoi("0"));
//	printf("ft_atoi(\"2147483647\") = %d (expected: 2147483647)\n",
//	ft_atoi("2147483647"));
//	printf("ft_atoi(\"-2147483648\") = %d (expected: -2147483648)\n",
//	ft_atoi("-2147483648"));
//	printf("ft_atoi(\"123abc\") = %d (expected: 123)\n", ft_atoi("123abc"));
//	return (0);
//}
