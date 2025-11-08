/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyamada <jyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 21:48:48 by jyamada           #+#    #+#             */
/*   Updated: 2025/10/30 15:05:06 by jyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (0 <= c && c <= 127)
		return (1);
	return (0);
}

//#include <stdio.h>
//
//int main(void)
//{
//	printf("ft_isascii('a') = %d\n", ft_isascii('a'));
//	printf("ft_isascii(127) = %d\n", ft_isascii(127));
//	printf("ft_isascii(0) = %d\n", ft_isascii(0));
//	printf("ft_isascii(128) = %d\n", ft_isascii(128));
//	printf("ft_isascii(-1) = %d\n", ft_isascii(-1));
//	return (0);
//}
