/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyamada <jyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 20:41:09 by jyamada           #+#    #+#             */
/*   Updated: 2025/10/25 14:41:50 by jyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (!('0' <= c && c <= '9'))
		return (0);
	return (1);
}

//#include <stdio.h>
//
//int main(void)
//{
//	printf("ft_isdigit('0') = %d\n", ft_isdigit('0'));
//	printf("ft_isdigit('5') = %d\n", ft_isdigit('5'));
//	printf("ft_isdigit('9') = %d\n", ft_isdigit('9'));
//	printf("ft_isdigit('a') = %d\n", ft_isdigit('a'));
//	printf("ft_isdigit(' ') = %d\n", ft_isdigit(' '));
//	return (0);
//}
