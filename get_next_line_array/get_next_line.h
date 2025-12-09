/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyamada <jyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 16:06:00 by jyamada           #+#    #+#             */
/*   Updated: 2025/12/08 20:47:38 by aburi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>

#ifndef BUFSIZE
# define BUFSIZE 42
#endif

char	*ft_getfile(int fd, char *buf);
char	*ft_extract_line(char *buf);
char    *ft_clean_stash(char *tmp_stash, int len_line);
char	*get_next_line(int fd);

#endif
