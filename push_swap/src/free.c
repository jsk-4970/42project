/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyamada <jyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 17:01:11 by jyamada           #+#    #+#             */
/*   Updated: 2026/01/23 15:10:10 by jyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"


void	free_args(char **args, int flag_to_free)
{
	if (flag_to_free != 1)
		return ;
	while (*args)
	{
		free(*args);
		args++;
	}
	free(args);
}

void	free_stack(t_stack *a)
{
	t_stack	*tmp;

	if (a == NULL)
		return ;
	while (a->next)
	{
		tmp = a->next;
		free(a);
		a = tmp;
	}
}

