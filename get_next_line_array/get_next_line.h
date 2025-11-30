/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyamada <jyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 16:06:00 by jyamada           #+#    #+#             */
/*   Updated: 2025/11/30 16:29:12 by jyamada          ###   ########.fr       */
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

char	*ft_getfile(int fd, char *buf);
char	*ft_extract_line(char *buf);
char	*get_next_line(int fd);

#endif
