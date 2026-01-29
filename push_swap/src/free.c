/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyamada <jyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 17:01:11 by jyamada           #+#    #+#             */
/*   Updated: 2026/01/23 15:16:00 by jyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_args(char **args, int flag_to_free)
{
	char	**tmp;

	if (flag_to_free != 1 || args == NULL)
		return ;
	tmp = args;
	while (*args)
	{
		free(*args);
		args++;
	}
	free(tmp);
}

void	free_stack(t_stack *a)
{
	t_stack	*tmp;

	if (a == NULL)
		return ;
	while (a != NULL)
	{
		tmp = a->next;
		free(a);
		a = tmp;
	}
}
