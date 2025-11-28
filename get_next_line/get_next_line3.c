/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 19:57:51 by aburi             #+#    #+#             */
/*   Updated: 2025/11/28 20:46:26 by aburi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*content;
	char	*buf;
	int		ret_of_read;
	int		i;

	i = 0;
	while (ret_of_read != -1)
	{
		buf = malloc(BUFSIZE * i + 1);
		ret_of_read = read(fd, buf, BUFSIZE);
		i++;
	}
}
