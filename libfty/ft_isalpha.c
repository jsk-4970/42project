/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyamada <jyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 20:41:09 by jyamada           #+#    #+#             */
/*   Updated: 2025/10/25 16:18:22 by jyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
		return (1);
	return (0);
}

//#include <stdio.h>
//
//int main(void)
//{
//	printf("ft_isalpha('a') = %d\n", ft_isalpha('a'));
//	printf("ft_isalpha('Z') = %d\n", ft_isalpha('Z'));
//	printf("ft_isalpha('5') = %d\n", ft_isalpha('5'));
//	printf("ft_isalpha(' ') = %d\n", ft_isalpha(' '));
//	printf("ft_isalpha('!') = %d\n", ft_isalpha('!'));
//	return (0);
//}
