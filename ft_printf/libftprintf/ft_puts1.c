/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyamada <jyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 21:34:10 by jyamada           #+#    #+#             */
/*   Updated: 2025/11/13 21:34:18 by jyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_c(int c)
{
	ft_putchar((char)c);
	return (1);
}

int	put_s(char *s)
{
	if (s == NULL)
	{
		ft_putstr("NULL");
		return (4);
	}
	ft_putstr(s);
	return (ft_strlen(s));
}
