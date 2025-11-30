/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:36:34 by aburi             #+#    #+#             */
/*   Updated: 2025/11/30 17:34:51 by jyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//the func to duplicate buf to list(maybe by '\n') and enter NULL to next
t_list	*append(t_list *new_node, char *buf)
{
	new_node = malloc(sizeof(t_list));
	new_node -> content = buf;
	new_node -> next = NULL;
	return (new_node);
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	static t_list	*new_node;
	char			*buf;
	int				read_ret;

	list = NULL;
	buf = malloc(BUFSIZE + 1);
	read_ret = 1;
	if (list == NULL)
	{
		list = malloc(sizeof(t_list));
		list -> next = new_node;
	}
	while (len_to_newline(buf) == -1 && buf != 0)
	{
		read_ret = read(fd, buf, BUFSIZE);
		if (read_ret == -1)
		{
			//handle error somehow in the case read() fails
		}
		buf[BUFSIZE] = '\0';
		append(new_node, buf);
		if (list -> content == NULL)
			printf("NULL");
//		printf("list -> content(just before strjoin)%s", list -> content);
//		list -> content = ft_strjoin(list -> content, buf);
	}
	free(buf);
	return (new_node -> content);
}

int main(void)
{
	int fd;
	char *line;

	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("file could not open");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (1);
}
