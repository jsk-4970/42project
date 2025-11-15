/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyamada <jyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 21:34:10 by jyamada           #+#    #+#             */
/*   Updated: 2025/11/15 20:28:55 by jyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_c(int c)
{
	if (ft_putchar((char)c) == -1)
		return (-1);
	return (1);
}

int	put_s(char *s)
{
	if (s == NULL)
	{
		if (ft_putstr("(null)") == -1)
			return (-1);
		return (6);
	}
	if (ft_putstr(s) == -1)
		return (-1);
	return (ft_strlen(s));
}
