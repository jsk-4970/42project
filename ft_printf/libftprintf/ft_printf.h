/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyamada <jyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 20:41:35 by jyamada           #+#    #+#             */
/*   Updated: 2025/11/15 14:41:51 by jyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <inttypes.h>
# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_strlen(const char *str);
int		ft_strlcpy(char *dest, const char *src, size_t dstsize);
void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putnbr(size_t n);

int		ft_read_next(const char *format, va_list args);
int		ft_printf(const char *format, ...);
int		put_c(int c);
int		put_s(char *s);
int		put_p(uintptr_t ptr);
int		put_d(long d);
int		put_u(unsigned long u);
int		put_x(unsigned long x, char c);

#endif
