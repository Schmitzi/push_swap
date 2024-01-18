/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeiger- <mgeiger-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 11:47:02 by utente            #+#    #+#             */
/*   Updated: 2023/12/08 14:40:49 by mgeiger-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	to_top_a(t_list **stack, t_list *top)
{
	while (*stack != top)
	{
		if (top->median == TRUE)
			ra(stack);
		else
			rra(stack);
	}
}

void	to_top_b(t_list **stack, t_list *top)
{
	while (*stack != top)
	{
		if (top->median)
			rb(stack);
		else
			rrb(stack);
	}
}

static void	move(t_list **stack_a, t_list **stack_b)
{
	t_list	*cheap_node;

	cheap_node = find_cheap(*stack_b);
	if (cheap_node->median && cheap_node->target->median)
		rotate_stacks(stack_a, stack_b, cheap_node);
	else if (!(cheap_node->median) && !(cheap_node->target->median))
		rev_rotate_stacks(stack_a, stack_b, cheap_node);
	to_top_b(stack_b, cheap_node);
	to_top_a(stack_a, cheap_node->target);
	pa(stack_a, stack_b);
}

void	push_swap(t_list **stack_a, t_list **stack_b)
{
	t_list	*min;
	int		len;

	len = ft_lstsize(*stack_a);
	if (len == 5)
		five_sort(stack_a, stack_b);
	else
	{
		while (len-- > 3)
			pb(stack_b, stack_a);
	}
	three_sort(stack_a);
	while (*stack_b)
	{
		init(*stack_a, *stack_b);
		move(stack_a, stack_b);
	}
	set_posmed(*stack_a);
	min = find_min(*stack_a);
	if (min->median)
		while (*stack_a != min)
			ra(stack_a);
	else
		while (*stack_a != min)
			rra(stack_a);
}
