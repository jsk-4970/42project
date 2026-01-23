/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyamada <jyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 17:01:11 by jyamada           #+#    #+#             */
/*   Updated: 2026/01/23 14:34:43 by jyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"


void	free_args(char **args, int flag_to_free)
{
	if (flag_to_free == 1)
		return ;
	while (!*args)
	{
		free(*args);
		args++;
	}
}

void	free_stack(t_stack *a)
{
	if (a == NULL)
		return ;
	while (!a->next)
	{
		free(a);
		a = a->next;
	}
}

