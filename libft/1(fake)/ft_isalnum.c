/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyamada <jyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 21:16:40 by jyamada           #+#    #+#             */
/*   Updated: 2025/10/29 22:50:54 by jyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (!(('0' <= c && c <= '9') || ('a' <= c && c <= 'z') || ('A' <= c
				&& c <= 'Z')))
		return (0);
	return (1);
}

//#include <stdio.h>
//#include <ctype.h>
//
//int main(void)
//{
//	printf("ft_alnum('a') = %d (expected: 1)\n", ft_alnum('a'));
//	printf("ft_alnum('Z') = %d (expected: 1)\n", ft_alnum('Z'));
//	printf("ft_alnum('5') = %d (expected: 1)\n", ft_alnum('5'));
//	printf("ft_alnum(' ') = %d (expected: 0)\n", ft_alnum(' '));
//	printf("ft_alnum('!') = %d (expected: 0)\n", ft_alnum('!'));
//	printf("ft_alnum(127) = %d (expected: 0)\n", ft_alnum(127));
//	return (0);
//}
