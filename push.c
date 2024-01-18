/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeiger- <mgeiger-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 10:36:47 by mgeiger-          #+#    #+#             */
/*   Updated: 2023/12/06 10:51:05 by mgeiger-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_list **stack_a, t_list **stack_b)
{
	t_list	*node;

	if (*stack_b == NULL)
		return ;
	node = *stack_b;
	*stack_b = (*stack_b)->next;
	if (*stack_b)
		(*stack_b)->prev = NULL;
	node->prev = NULL;
	if (*stack_a == NULL)
	{
		*stack_a = node;
		node->next = NULL;
	}
	else
	{
		node->next = *stack_a;
		node->next->prev = node;
		*stack_a = node;
	}
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
	write(1, "pa\n", 3);
}

void	pb(t_list **stack_b, t_list **stack_a)
{
	push(stack_b, stack_a);
	write(1, "pb\n", 3);
}
