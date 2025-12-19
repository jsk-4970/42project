/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburi <aburi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 16:06:00 by jyamada           #+#    #+#             */
/*   Updated: 2025/12/19 15:59:13 by aburi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t	ft_strlen(const char *str);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_read(int fd, char *buf);
ssize_t	find_new_line(char *str);
char	*ft_getfile(int fd, char *buf);
char	*ft_extract_line(char *buf);
char	*ft_clean_stash(char *tmp_stash, size_t len_line);
char	*get_next_line(int fd);

#endif
