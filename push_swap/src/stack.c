/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburi <aburi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 00:00:00 by aburi             #+#    #+#             */
/*   Updated: 2026/01/29 00:00:00 by aburi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*make_new_stack(int value)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	new->next = NULL;
	new->value = value;
	return (new);
}

t_stack	*find_last_stack(t_stack *list)
{
	if (list == NULL)
		return (list);
	while (list->next != NULL)
		list = list->next;
	return (list);
}

int	stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*last_list;

	if (new == NULL)
		return (0);
	if (*stack == NULL)
		*stack = new;
	else
	{
		last_list = find_last_stack(*stack);
		last_list->next = new;
	}
	return (1);
}
