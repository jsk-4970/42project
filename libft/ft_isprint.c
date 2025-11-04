/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyamada <jyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:25:49 by jyamada           #+#    #+#             */
/*   Updated: 2025/10/30 15:05:05 by jyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (32 <= c && c <= 126)
		return (1);
	return (0);
}

//#include <stdio.h>
//
//int main(void)
//{
//	printf("ft_isprint(' ') = %d\n", ft_isprint(' '));
//	printf("ft_isprint('a') = %d\n", ft_isprint('a'));
//	printf("ft_isprint('~') = %d\n", ft_isprint('~'));
//	printf("ft_isprint(31) = %d\n", ft_isprint(31));
//	printf("ft_isprint(127) = %d\n", ft_isprint(127));
//	return (0);
//}
