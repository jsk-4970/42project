/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyamada <jyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 16:04:04 by jyamada           #+#    #+#             */
/*   Updated: 2025/11/18 15:54:29 by aburi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

#ifndef BUFSIZE
# define BUFSIZE 42
#endif

typedef struct s_list
{
    char            *contents;
    size_t          len;
    struct s_list   *next;
}                   t_list;

char	*get_next_line(int fd);
int     ft_getc(int fd);

#endif
