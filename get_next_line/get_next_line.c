/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:36:34 by aburi             #+#    #+#             */
/*   Updated: 2025/11/28 20:51:51 by aburi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//return the length to newline
int		len_to_newline(char *buf)
{
	int	ret;

	ret = 0;
	return (ret);
}

//the func to duplicate buf to list(maybe by '\n') and enter NULL to next
t_list	*append(t_list *list, char *buf)
{
	static t_list	*new_node;
	int				len;

	new_node = malloc(sizeof(t_list));
	new_node -> content = buf;
	new_node -> next = NULL;
	len = len_to_newline(buf);
	while (len < BUFSIZE)
	{

	}
	return (new_node);
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	static t_list	*new_node;
	char			*buf;
	int				read_ret;

	buf = malloc(BUFSIZE + 1);
	read_ret = read(fd, buf, BUFSIZE);
	if (read_ret <= 0)
		return (NULL);
	buf[BUFSIZE + 1] = '\0';
	append(list, buf);
	list = new_node;
	return (new_node -> content);
}

