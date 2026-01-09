/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyamada <jyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:49:26 by jyamada           #+#    #+#             */
/*   Updated: 2025/10/26 12:33:16 by jyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		c -= 'A' - 'a';
	return (c);
}

//#include <stdio.h>
//#include <ctype.h>
//
//int main(void)
//{
//	printf("ft_lower('A') = %c\n", ft_lower('A'));
//	printf("ft_lower('Z') = %c\n", ft_lower('Z'));
//	printf("ft_lower('a') = %c\n", ft_lower('a'));
//	printf("ft_lower('z') = %c\n", ft_lower('z'));
//	printf("ft_lower('5') = %c\n", ft_lower('5'));
//	return (0);
//}
