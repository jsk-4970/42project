/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyamada <jyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:44:19 by jyamada           #+#    #+#             */
/*   Updated: 2025/10/26 12:40:39 by jyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		c += 'A' - 'a';
	return (c);
}

//#include <stdio.h>
//#include <ctype.h>
//
//int main(void)
//{
//	printf("ft_toupper('a') = %c\n", ft_toupper('a'));
//	printf("ft_toupper('z') = %c\n", ft_toupper('z'));
//	printf("ft_toupper('A') = %c\n", ft_toupper('A'));
//	printf("ft_toupper('Z') = %c\n", ft_toupper('Z'));
//	printf("ft_toupper('5') = %c\n", ft_toupper('5'));
//	return (0);
//}
