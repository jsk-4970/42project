/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyamada <jyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 16:04:04 by jyamada           #+#    #+#             */
/*   Updated: 2025/11/28 22:21:36 by aburi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <cstddef>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

#ifndef BUFSIZE
# define BUFSIZE 42
#endif

typedef struct s_list
{
    char            *content;
    struct s_list   *next;
}                   t_list;

size_t  ft_strlen(const char *str);
char    *ft_strchr(const char *buf, int c);
size_t  ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize);
char    *ft_strjoin(char const *s1, char const *s2);

char    *get_next_line(int fd);
t_list  *append(t_list *list, char *buf);
int     len_to_newline(char *str);

#endif
