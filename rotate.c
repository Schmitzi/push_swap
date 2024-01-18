/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeiger- <mgeiger-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 10:07:07 by utente            #+#    #+#             */
/*   Updated: 2023/12/07 11:34:34 by mgeiger-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_list **stack)
{
	t_list	*last;
	int		len;

	len = ft_lstsize(*stack);
	if (stack == NULL || *stack == NULL || len == 1)
		return ;
	last = find_last(*stack);
	last->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last->next->prev = last;
	last->next->next = NULL;
}

void	rotate_stacks(t_list **stack_a, t_list **stack_b
							, t_list *cheap_node)
{
	while (*stack_a != cheap_node->target && *stack_b != cheap_node)
		rr(stack_a, stack_b);
	set_posmed(*stack_a);
	set_posmed(*stack_b);
}

void	ra(t_list **stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_list **stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}
