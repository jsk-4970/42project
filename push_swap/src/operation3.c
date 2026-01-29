/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyamada <jyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 18:05:25 by jyamada           #+#    #+#             */
/*   Updated: 2026/01/17 13:32:18 by jyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*find_before_last(t_stack *list)
{
	if (list == NULL || list->next == NULL)
		return (NULL);
	while (list->next->next != NULL)
		list = list->next;
	return (list);
}

void	reverse_rotate(t_stack **list)
{
	t_stack	*last;
	t_stack	*tmp;

	if (!list || !*list || !(*list)->next)
		return ;
	last = find_last_stack(*list);
	tmp = find_before_last(*list);
	last->next = *list;
	*list = last;
	tmp->next = NULL;
}

void	rra(t_stack **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}
